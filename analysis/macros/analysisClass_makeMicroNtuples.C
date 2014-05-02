#include "analysisClass.h"
#include "HcalNoiseTree.h"

#include "TF1.h"
#include "TH1F.h"
#include "TChain.h"
#include "TMath.h"

int getRing(int ieta){
  int absIeta = abs(ieta);
  if ( 0  <= absIeta && absIeta <= 16 ) return 0;
  if ( 17 <= absIeta && absIeta <= 20 ) return 1;
  if ( 21 <= absIeta && absIeta <= 23 ) return 2;
  if ( 24 <= absIeta && absIeta <= 25 ) return 3;
  if ( 26 <= absIeta && absIeta <= 27 ) return 4;
  if ( 28 <= absIeta && absIeta <= 28 ) return 5;
  return -1;
}

void analysisClass::loop(){

  //--------------------------------------------------------------------------------
  // Declare HCAL input trees
  //--------------------------------------------------------------------------------

  HcalNoiseTree * input_tree = getTree<HcalNoiseTree>("noise_tree", "no_pu_files" );
  int n_events = input_tree -> fChain -> GetEntries();

  //--------------------------------------------------------------------------------
  // String manipulation
  //--------------------------------------------------------------------------------

  std::string out_file_for_tree_name = m_outFileName;
  std::string from(".root");
  std::string to("_tree.root");
  size_t start_pos = 0;
  
  while((start_pos = out_file_for_tree_name.find(from, start_pos)) != std::string::npos) {
         out_file_for_tree_name.replace(start_pos, from.length(), to);
         start_pos += to.length();
  }

  //--------------------------------------------------------------------------------
  // Declare output tree and file
  //--------------------------------------------------------------------------------

  TFile * output_tree_file = new TFile(out_file_for_tree_name.c_str(), "RECREATE");
  TTree * output_tree      = new TTree("tree","tree");

  //--------------------------------------------------------------------------------
  // Declare branches
  //--------------------------------------------------------------------------------
  
  Int_t    Ring ;
  Int_t    IEta ;
  Int_t    IPhi ;
  Int_t    Depth;
  Double_t a_1  ;
  Double_t a1   ;
  Double_t a2   ;
  Double_t a3   ;
  Double_t TS4  ;

  output_tree -> Branch("Ring" , &Ring  , "Ring/I" );
  output_tree -> Branch("IEta" , &IEta  , "IEta/I" );
  output_tree -> Branch("IPhi" , &IPhi  , "IPhi/I" );
  output_tree -> Branch("Depth", &Depth , "Depth/I");
  output_tree -> Branch("a_1"  , &a_1   , "a_1/D"  );
  output_tree -> Branch("a1"   , &a1    , "a1/D"  );
  output_tree -> Branch("a2"   , &a2    , "a2/D"  );
  output_tree -> Branch("a3"   , &a3    , "a3/D"  );
  output_tree -> Branch("TS4"  , &TS4   , "TS4/D" );

  //--------------------------------------------------------------------------------
  // Clean branches we don't need
  //--------------------------------------------------------------------------------

  input_tree -> fChain -> SetBranchStatus("*"          , kFALSE);
  input_tree -> fChain -> SetBranchStatus("PulseCount" , kTRUE );
  input_tree -> fChain -> SetBranchStatus("IEta"       , kTRUE );
  input_tree -> fChain -> SetBranchStatus("IPhi"       , kTRUE );
  input_tree -> fChain -> SetBranchStatus("Depth"      , kTRUE );
  input_tree -> fChain -> SetBranchStatus("Charge"     , kTRUE );
  input_tree -> fChain -> SetBranchStatus("Energy"     , kTRUE );
  input_tree -> fChain -> SetBranchStatus("NumberOfGoodPrimaryVertices", kTRUE );
  
  //--------------------------------------------------------------------------------
  // Loop over the events
  //--------------------------------------------------------------------------------
  
  for (int iEvent = 0; iEvent < n_events; ++iEvent){

    //--------------------------------------------------------------------------------
    // Tell the user where we are
    //--------------------------------------------------------------------------------

    if (iEvent%100 == 0) std::cout << "Processing event " << iEvent << "/" << n_events << std::endl;
    
    //--------------------------------------------------------------------------------
    // Get each entry in the event
    //--------------------------------------------------------------------------------

    input_tree -> GetEntry(iEvent);

    //--------------------------------------------------------------------------------
    // Event level selection
    //--------------------------------------------------------------------------------
    
    if ( input_tree -> NumberOfGoodPrimaryVertices == 0 ) continue;

    //--------------------------------------------------------------------------------
    // Fill variables
    //--------------------------------------------------------------------------------

    for (int iHBHE = 0; iHBHE < input_tree -> PulseCount; ++iHBHE){

      //--------------------------------------------------------------------------------
      // Store some important values for selection
      //--------------------------------------------------------------------------------

      int     ieta   = input_tree -> IEta  [iHBHE];
      int     iphi   = input_tree -> IPhi  [iHBHE];
      int    depth   = input_tree -> Depth [iHBHE];
      bool     bad   = isBadChannel(0, ieta, iphi, depth);
      int     ring   = getRing(ieta);
      
      //--------------------------------------------------------------------------------
      // Cell-level selection
      //--------------------------------------------------------------------------------
      
      if (ring < 0) continue;
      if (input_tree -> Energy[iHBHE]    < 1.0) continue;
      if (input_tree -> Charge[iHBHE][4] < 5.0) continue;
      if (bad) continue;

      //--------------------------------------------------------------------------------
      // Get time sample information
      //--------------------------------------------------------------------------------

      Double_t tmp_TS3 = input_tree -> Charge[iHBHE][3];
      Double_t tmp_TS4 = input_tree -> Charge[iHBHE][4];
      Double_t tmp_TS5 = input_tree -> Charge[iHBHE][5];
      Double_t tmp_TS6 = input_tree -> Charge[iHBHE][6];
      Double_t tmp_TS7 = input_tree -> Charge[iHBHE][7];

      Double_t tmp_a_1 = tmp_TS3/tmp_TS4;
      Double_t tmp_a1  = tmp_TS5/tmp_TS4;
      Double_t tmp_a2  = tmp_TS6/tmp_TS4;
      Double_t tmp_a3  = tmp_TS7/tmp_TS4;
      
      //--------------------------------------------------------------------------------
      // Fill tree variables
      //--------------------------------------------------------------------------------

      Ring  = ring;
      IEta  = ieta;
      IPhi  = iphi;
      Depth = depth;
      a_1   = tmp_a_1;
      a1    = tmp_a1;
      a2    = tmp_a2;
      a3    = tmp_a3;
      TS4   = tmp_TS4;

      //--------------------------------------------------------------------------------
      // Fill the tree
      //--------------------------------------------------------------------------------
      
      output_tree -> Fill();

    } // end loop over digis

  } // end loop over events

  //--------------------------------------------------------------------------------
  // Write out the tree
  //--------------------------------------------------------------------------------

  output_tree_file -> cd(); 
  output_tree      -> Write();
  output_tree_file -> Close();
  
}
