#include "analysisClass.h"
#include "HcalNoiseTree.h"

#include "TH1F.h"
#include "TChain.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <assert.h>  
#include <cmath>
#include <map>

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
  // Declare HCAL trees
  //--------------------------------------------------------------------------------

  HcalNoiseTree * no_pu_tree = getTree<HcalNoiseTree>("noise_tree", "no_pu_files" );
  HcalNoiseTree * pu_50_tree = getTree<HcalNoiseTree>("noise_tree", "pu_50_files" );
  
  //--------------------------------------------------------------------------------
  // Clean branches we don't need
  //--------------------------------------------------------------------------------

  // PU = 0
  no_pu_tree -> fChain -> SetBranchStatus("*"          , kFALSE);
  no_pu_tree -> fChain -> SetBranchStatus("RunNumber"  , kTRUE );
  no_pu_tree -> fChain -> SetBranchStatus("EventNumber", kTRUE );
  no_pu_tree -> fChain -> SetBranchStatus("LumiSection", kTRUE );
  no_pu_tree -> fChain -> SetBranchStatus("PulseCount" , kTRUE );
  no_pu_tree -> fChain -> SetBranchStatus("IEta"       , kTRUE );
  no_pu_tree -> fChain -> SetBranchStatus("IPhi"       , kTRUE );
  no_pu_tree -> fChain -> SetBranchStatus("Depth"      , kTRUE );
  no_pu_tree -> fChain -> SetBranchStatus("Charge"     , kTRUE );
  
  // PU = 50
  pu_50_tree -> fChain -> SetBranchStatus("*"          , kFALSE);
  pu_50_tree -> fChain -> SetBranchStatus("RunNumber"  , kTRUE );
  pu_50_tree -> fChain -> SetBranchStatus("EventNumber", kTRUE );
  pu_50_tree -> fChain -> SetBranchStatus("LumiSection", kTRUE );
  pu_50_tree -> fChain -> SetBranchStatus("PulseCount" , kTRUE );
  pu_50_tree -> fChain -> SetBranchStatus("IEta"       , kTRUE );
  pu_50_tree -> fChain -> SetBranchStatus("IPhi"       , kTRUE );
  pu_50_tree -> fChain -> SetBranchStatus("Depth"      , kTRUE );
  pu_50_tree -> fChain -> SetBranchStatus("Charge"     , kTRUE );
  
  //--------------------------------------------------------------------------------
  // Declare some important quantities
  //--------------------------------------------------------------------------------
  
  const int nrings = 6;

  //--------------------------------------------------------------------------------
  // Declare histograms
  //--------------------------------------------------------------------------------

  TH1F * h_no_pu_maxChargeHB = makeTH1F("no_pu_maxChargeHB", 10, -0.5, 9.5);
  TH1F * h_pu_50_maxChargeHB = makeTH1F("pu_50_maxChargeHB", 10, -0.5, 9.5);
  TH1F * h_no_pu_maxChargeHE = makeTH1F("no_pu_maxChargeHE", 10, -0.5, 9.5);
  TH1F * h_pu_50_maxChargeHE = makeTH1F("pu_50_maxChargeHE", 10, -0.5, 9.5);

  //--------------------------------------------------------------------------------
  // Just look at one event
  //--------------------------------------------------------------------------------
  
  int event_to_process = 0;

  for (int iEvent = event_to_process; iEvent < event_to_process + 1; ++iEvent){

    //--------------------------------------------------------------------------------
    // Tell the user where we are
    //--------------------------------------------------------------------------------
    
    std::cout << std::endl;
    std::cout << "Processing event " << iEvent << std::endl;
    
    //--------------------------------------------------------------------------------
    // Get each entry in the event
    //--------------------------------------------------------------------------------

    no_pu_tree -> GetEntry(iEvent);
    pu_50_tree -> GetEntry(iEvent);

    //--------------------------------------------------------------------------------
    // Assert that we're on the same event
    //--------------------------------------------------------------------------------
    
    std::cout << "No PU: " 
	      << "run = "   << no_pu_tree -> RunNumber   << ", " 
	      << "event = " << no_pu_tree -> EventNumber << ", "
	      << "ls = "    << no_pu_tree -> LumiSection << std::endl;
    std::cout << "PU 50: " 
	      << "run = "   << pu_50_tree -> RunNumber   << ", " 
	      << "event = " << pu_50_tree -> EventNumber << ", "
	      << "ls = "    << pu_50_tree -> LumiSection << std::endl;

    assert(no_pu_tree -> RunNumber   == pu_50_tree -> RunNumber  );
    assert(no_pu_tree -> EventNumber == pu_50_tree -> EventNumber);
    assert(no_pu_tree -> LumiSection == pu_50_tree -> LumiSection);

    std::cout << "--> Same event!" << std::endl;
    std::cout << std::endl;

    //--------------------------------------------------------------------------------
    // Get maximum charge in no pileup tree for HB and HE
    //--------------------------------------------------------------------------------
    
    int no_pu_nHBHE = no_pu_tree -> PulseCount;

    float no_pu_maxCharge_HB       = -1.0;
    int   no_pu_maxCharge_HB_ieta  = -1;
    int   no_pu_maxCharge_HB_iphi  = -1;
    int   no_pu_maxCharge_HB_depth = -1;
    int   no_pu_maxCharge_HB_iHBHE = -1;
    int   no_pu_maxCharge_HB_iTS   = -1;
    
    float no_pu_maxCharge_HE       = -1.0;
    int   no_pu_maxCharge_HE_ieta  = -1;
    int   no_pu_maxCharge_HE_iphi  = -1;
    int   no_pu_maxCharge_HE_depth = -1;
    int   no_pu_maxCharge_HE_iHBHE = -1;
    int   no_pu_maxCharge_HE_iTS   = -1;
    
    for (int no_pu_iHBHE = 0; no_pu_iHBHE < no_pu_nHBHE; ++no_pu_iHBHE){

      int no_pu_ieta  = no_pu_tree -> IEta [no_pu_iHBHE];
      int no_pu_iphi  = no_pu_tree -> IPhi [no_pu_iHBHE];
      int no_pu_depth = no_pu_tree -> Depth[no_pu_iHBHE];
      int ring = getRing ( no_pu_ieta );
      bool isHB = ( ring == 0 );
      bool isHE = ( ring != 0 );
      
      for (int i_sample = 0; i_sample < 10; ++i_sample){
	
	float no_pu_charge = no_pu_tree -> Charge[no_pu_iHBHE][i_sample];
	
	if (isHB && no_pu_charge > no_pu_maxCharge_HB){
	  no_pu_maxCharge_HB        = no_pu_charge;
	  no_pu_maxCharge_HB_ieta   = no_pu_ieta;
	  no_pu_maxCharge_HB_iphi   = no_pu_iphi;
	  no_pu_maxCharge_HB_depth  = no_pu_depth;
	  no_pu_maxCharge_HB_iHBHE  = no_pu_iHBHE;
	  no_pu_maxCharge_HB_iTS    = i_sample;
	}

	if (isHE && no_pu_charge > no_pu_maxCharge_HE){
	  no_pu_maxCharge_HE        = no_pu_charge;
	  no_pu_maxCharge_HE_ieta   = no_pu_ieta;
	  no_pu_maxCharge_HE_iphi   = no_pu_iphi;
	  no_pu_maxCharge_HE_depth  = no_pu_depth;
	  no_pu_maxCharge_HE_iHBHE  = no_pu_iHBHE;
	  no_pu_maxCharge_HE_iTS    = i_sample;
	}
      }
    }

    //--------------------------------------------------------------------------------
    // Find same digis in pileup tree
    //--------------------------------------------------------------------------------
    
    int pu_50_nHBHE = pu_50_tree -> PulseCount;

    float pu_50_matchCharge_HB       = -1.0;
    float pu_50_matchCharge_HE       = -1.0;
    int   pu_50_matchCharge_HB_iHBHE = -1;
    int   pu_50_matchCharge_HE_iHBHE = -1;
    
    for (int pu_50_iHBHE = 0; pu_50_iHBHE < pu_50_nHBHE; ++pu_50_iHBHE){
      
      int pu_50_ieta  = pu_50_tree -> IEta [pu_50_iHBHE];
      int pu_50_iphi  = pu_50_tree -> IPhi [pu_50_iHBHE];
      int pu_50_depth = pu_50_tree -> Depth[pu_50_iHBHE];
      
      if ( ( pu_50_ieta  == no_pu_maxCharge_HB_ieta  ) && 
	   ( pu_50_iphi  == no_pu_maxCharge_HB_iphi  ) && 
	   ( pu_50_depth == no_pu_maxCharge_HB_depth ) ){
	pu_50_matchCharge_HB        = pu_50_tree -> Charge[pu_50_iHBHE][no_pu_maxCharge_HB_iTS];
	pu_50_matchCharge_HB_iHBHE  = pu_50_iHBHE;
      }

      if ( ( pu_50_ieta  == no_pu_maxCharge_HE_ieta  ) && 
	   ( pu_50_iphi  == no_pu_maxCharge_HE_iphi  ) && 
	   ( pu_50_depth == no_pu_maxCharge_HE_depth ) ){
	pu_50_matchCharge_HE        = pu_50_tree -> Charge[pu_50_iHBHE][no_pu_maxCharge_HE_iTS];
	pu_50_matchCharge_HE_iHBHE  = pu_50_iHBHE;
      }
      
    }

    //--------------------------------------------------------------------------------
    // Print info about HB digi
    //--------------------------------------------------------------------------------
    
    std::cout << "Maximum charge (HB) in no-pileup sample:" << std::endl;
    std::cout << "\t" << "Digi   = HB(";
    std::cout << no_pu_maxCharge_HB_ieta  << ", " 
	      << no_pu_maxCharge_HB_iphi  << ", " 
	      << no_pu_maxCharge_HB_depth << ")" << std::endl;

    std::cout << "\t" << "charge = " << no_pu_maxCharge_HB << " fC" << std::endl;
    std::cout << "\t" << "full   = ";
    for (int i_sample = 0; i_sample < 10; ++i_sample){
      float charge = no_pu_tree -> Charge[no_pu_maxCharge_HB_iHBHE][i_sample];
      std::cout << charge << " ";
      int bin = h_no_pu_maxChargeHB -> FindBin(i_sample);
      h_no_pu_maxChargeHB -> SetBinContent(bin, charge);
    }
    std::cout << std::endl;
    
    std::cout << "Matching charge (HB) in pileup sample:" << std::endl;

    std::cout << "\t" << "charge = " << pu_50_matchCharge_HB << " fC" << std::endl;
    std::cout << "\t" << "full   = ";
    for (int i_sample = 0; i_sample < 10; ++i_sample){
      float charge = pu_50_tree -> Charge[pu_50_matchCharge_HB_iHBHE][i_sample];
      std::cout << charge << " ";
      int bin = h_no_pu_maxChargeHB -> FindBin(i_sample);
      h_pu_50_maxChargeHB -> SetBinContent(bin, charge);
    }
    std::cout << std::endl;
    
    std::cout << std::endl;

    //--------------------------------------------------------------------------------
    // Print info about HE digi
    //--------------------------------------------------------------------------------
    
    std::cout << "Maximum charge (HE) in no-pileup sample:" << std::endl;
    std::cout << "\t" << "Digi   = HE(";
    std::cout << no_pu_maxCharge_HE_ieta  << ", " 
	      << no_pu_maxCharge_HE_iphi  << ", " 
	      << no_pu_maxCharge_HE_depth << ")" << std::endl;

    std::cout << "\t" << "charge = " << no_pu_maxCharge_HE << " fC" << std::endl;
    std::cout << "\t" << "full   = ";
    for (int i_sample = 0; i_sample < 10; ++i_sample){
      float charge = no_pu_tree -> Charge[no_pu_maxCharge_HE_iHBHE][i_sample];
      std::cout << charge << " ";
      int bin = h_no_pu_maxChargeHE -> FindBin(i_sample);
      h_no_pu_maxChargeHE -> SetBinContent(bin, charge);
    }
    std::cout << std::endl;
    
    std::cout << "Matching charge (HE) in pileup sample:" << std::endl;

    std::cout << "\t" << "charge = " << pu_50_matchCharge_HE << " fC" << std::endl;
    std::cout << "\t" << "full   = ";
    for (int i_sample = 0; i_sample < 10; ++i_sample){
      float charge = pu_50_tree -> Charge[pu_50_matchCharge_HE_iHBHE][i_sample];
      std::cout << charge << " ";
      int bin = h_pu_50_maxChargeHE -> FindBin(i_sample);
      h_pu_50_maxChargeHE -> SetBinContent(bin, charge);
    }
    std::cout << std::endl;
    
    std::cout << std::endl;

  }
    
}
