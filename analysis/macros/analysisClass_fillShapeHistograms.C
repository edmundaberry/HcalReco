#include "analysisClass.h"
#include "HcalNoiseTree.h"

#include "TH1F.h"
#include "TChain.h"

#include <iomanip> 
#include <fstream>
#include <sstream>
#include <iostream>
#include <assert.h>  
#include <cmath>
#include <map>

int getNRings(){
  return 6;
}

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
  // Declare HCAL tree(s)
  //--------------------------------------------------------------------------------

  HcalNoiseTree * noise_tree = getTree<HcalNoiseTree>("noise_tree");
  int n_events = noise_tree -> fChain -> GetEntries();

  //--------------------------------------------------------------------------------
  // Clean branches we don't need
  //--------------------------------------------------------------------------------

  noise_tree -> fChain -> SetBranchStatus("*"         , kFALSE);
  noise_tree -> fChain -> SetBranchStatus("PulseCount", kTRUE );
  noise_tree -> fChain -> SetBranchStatus("IEta"      , kTRUE );
  noise_tree -> fChain -> SetBranchStatus("IPhi"      , kTRUE );
  noise_tree -> fChain -> SetBranchStatus("Depth"     , kTRUE );
  noise_tree -> fChain -> SetBranchStatus("Energy"    , kTRUE );
  noise_tree -> fChain -> SetBranchStatus("Charge"    , kTRUE );
  noise_tree -> fChain -> SetBranchStatus("OfficialDecision", kTRUE);
  noise_tree -> fChain -> SetBranchStatus("NumberOfGoodPrimaryVertices", kTRUE);

  //--------------------------------------------------------------------------------
  // Declare some important quantities
  //--------------------------------------------------------------------------------
  
  const int nrings = 6;

  //--------------------------------------------------------------------------------
  // Declare histograms
  //--------------------------------------------------------------------------------

  TH1F * h_npv = makeTH1F("npv",5,-0.5,4.5);
  TH1F * h_ieta= makeTH1F("ieta", 59, -29.5, 29.5 );
  TH1F * h_iphi= makeTH1F("iphi", 73, -0.5, 72.5 );
  TH2F * h_ieta_iphi = makeTH2F("ieta_iphi", 59, -29.5, 29.5, 73, -0.5, 72.5 );
  
  char hist_name[100];
  std::vector<TH2F*> a0_histograms, a1_histograms, a2_histograms, a3_histograms;
  for (int iring = 0; iring < nrings; ++iring){
    sprintf(hist_name, "a0_ring%d", iring); a0_histograms.push_back(makeTH2F(hist_name, 3000, 0, 3000, 10000, -10.0, 10.0));
    sprintf(hist_name, "a1_ring%d", iring); a1_histograms.push_back(makeTH2F(hist_name, 3000, 0, 3000, 10000, -10.0, 10.0));
    sprintf(hist_name, "a2_ring%d", iring); a2_histograms.push_back(makeTH2F(hist_name, 3000, 0, 3000, 10000, -10.0, 10.0));
    sprintf(hist_name, "a3_ring%d", iring); a3_histograms.push_back(makeTH2F(hist_name, 3000, 0, 3000, 10000, -10.0, 10.0));
  }

  TH2F* a0_histogram_hb = makeTH2F("a0_hb", 3000, 0, 3000, 100, -10.0, 10.0);
  TH2F* a1_histogram_hb = makeTH2F("a1_hb", 3000, 0, 3000, 100, -10.0, 10.0);
  TH2F* a2_histogram_hb = makeTH2F("a2_hb", 3000, 0, 3000, 100, -10.0, 10.0);
  TH2F* a3_histogram_hb = makeTH2F("a3_hb", 3000, 0, 3000, 100, -10.0, 10.0);

  TH2F* a0_histogram_he = makeTH2F("a0_he", 3000, 0, 3000, 100, -10.0, 10.0);
  TH2F* a1_histogram_he = makeTH2F("a1_he", 3000, 0, 3000, 100, -10.0, 10.0);
  TH2F* a2_histogram_he = makeTH2F("a2_he", 3000, 0, 3000, 100, -10.0, 10.0);
  TH2F* a3_histogram_he = makeTH2F("a3_he", 3000, 0, 3000, 100, -10.0, 10.0);
  
  //--------------------------------------------------------------------------------
  // Loop over the events
  //--------------------------------------------------------------------------------
  
  for (int iEvent = 0; iEvent < n_events; ++iEvent){

    //--------------------------------------------------------------------------------
    // Tell the user where we are
    //--------------------------------------------------------------------------------

    if (iEvent%1000 == 0) std::cout << "Processing event " << iEvent << "/" << n_events << std::endl;
    
    //--------------------------------------------------------------------------------
    // Get each entry in the event
    //--------------------------------------------------------------------------------

    noise_tree -> GetEntry(iEvent);

    //--------------------------------------------------------------------------------
    // Event-level selection
    // Note: "official selection" variable is always zero for MC?
    //--------------------------------------------------------------------------------

    // if ( noise_tree -> OfficialDecision ) continue;
    if ( noise_tree -> NumberOfGoodPrimaryVertices == 0 ) continue;

    //--------------------------------------------------------------------------------
    // Loop over the cells
    //--------------------------------------------------------------------------------
    
    int nHBHE = noise_tree -> PulseCount;
    
    h_npv -> Fill(noise_tree -> NumberOfGoodPrimaryVertices);

    for (int iHBHE = 0; iHBHE < nHBHE; ++iHBHE){

      //--------------------------------------------------------------------------------
      // Store some important values for selection
      //--------------------------------------------------------------------------------

      int     ieta   = noise_tree -> IEta  [iHBHE];
      int     iphi   = noise_tree -> IPhi  [iHBHE];
      int    depth   = noise_tree -> Depth [iHBHE];
      bool     bad   = isBadChannel(0, ieta, iphi, depth);
      int     ring   = getRing(ieta);
      
      //--------------------------------------------------------------------------------
      // Cell-level selection
      //--------------------------------------------------------------------------------
      
      if (ring < 0) continue;
      if (noise_tree -> Energy[iHBHE]    < 1.0) continue;
      if (noise_tree -> Charge[iHBHE][4] < 5.0) continue;
      if (bad) continue;

      //--------------------------------------------------------------------------------
      // Store some important values for plotting
      //--------------------------------------------------------------------------------
      
      double TS1 = noise_tree -> Charge[iHBHE][1];
      double TS2 = noise_tree -> Charge[iHBHE][2];
      double TS3 = noise_tree -> Charge[iHBHE][3];
      double TS4 = noise_tree -> Charge[iHBHE][4];
      double TS5 = noise_tree -> Charge[iHBHE][5];
      double TS6 = noise_tree -> Charge[iHBHE][6];
      double TS7 = noise_tree -> Charge[iHBHE][7];

      /*
      std::cout << "-------------------------------------------------------------------------------------------------------------------------------" << std::endl;
      for (int i = 0; i < 10; i++){
	std::cout << i << "\t";
      }
      std::cout << std::endl;
      for (int i = 0; i < 10; i++){
	std::cout << std::setprecision(2) <<  noise_tree -> Charge[iHBHE][i] << "\t";
      }
      std::cout << std::endl;
      */
      
      double a0  = TS3/TS4;
      double a1  = TS5/TS4;
      double a2  = TS6/TS4;
      double a3  = TS7/TS4;
      
      //--------------------------------------------------------------------------------
      // Fill histograms
      //--------------------------------------------------------------------------------

      h_ieta      -> Fill ( ieta );
      h_iphi      -> Fill ( iphi );
      h_ieta_iphi -> Fill ( ieta, iphi );

      a0_histograms[ring] -> Fill(TS4, a0);
      a1_histograms[ring] -> Fill(TS4, a1);
      a2_histograms[ring] -> Fill(TS4, a2);
      a3_histograms[ring] -> Fill(TS4, a3);

      if ( ring == 0 ){
	a0_histogram_hb -> Fill(TS4, a0);
	a1_histogram_hb -> Fill(TS4, a1);
	a2_histogram_hb -> Fill(TS4, a2);
	a3_histogram_hb -> Fill(TS4, a3);
      }

      else { 
      	a0_histogram_he -> Fill(TS4, a0);
      	a1_histogram_he -> Fill(TS4, a1);
	a2_histogram_he -> Fill(TS4, a2);
	a3_histogram_he -> Fill(TS4, a3);
      }
      
    }      
  }
}
