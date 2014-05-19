#include "analysisClass.h"
#include "fitResults.h"
#include "HcalNoiseTree.h"

#include "TF1.h"
#include "TH1F.h"
#include "TChain.h"
#include "TMath.h"

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
  if ( 28 <= absIeta && absIeta <= 29 ) return 5;
  return -1;
}

void analysisClass::loop(){

  //--------------------------------------------------------------------------------
  // Declare functions
  //--------------------------------------------------------------------------------
  
  TF1 * f_a0_HB     = new TF1( "a0_HB"    , fitResults::a0_HB  , 0 , 10000, 0);
  TF1 * f_a1_HB     = new TF1( "a1_HB"    , fitResults::a1_HB  , 0 , 10000, 0);
  TF1 * f_a2_HB     = new TF1( "a1_HB"    , fitResults::a2_HB  , 0 , 10000, 0);
  TF1 * f_a3_HB     = new TF1( "a1_HB"    , fitResults::a3_HB  , 0 , 10000, 0);
  
  TF1 * f_a0_HE1720 = new TF1( "a0_HE1720", fitResults::a0_1720, 0 , 10000, 0);
  TF1 * f_a1_HE1720 = new TF1( "a1_HE1720", fitResults::a1_1720, 0 , 10000, 0);
  TF1 * f_a2_HE1720 = new TF1( "a2_HE1720", fitResults::a2_1720, 0 , 10000, 0);
  TF1 * f_a3_HE1720 = new TF1( "a3_HE1720", fitResults::a3_1720, 0 , 10000, 0);

  TF1 * f_a0_HE2123 = new TF1( "a0_HE2123", fitResults::a0_2123, 0 , 10000, 0);
  TF1 * f_a1_HE2123 = new TF1( "a1_HE2123", fitResults::a1_2123, 0 , 10000, 0);
  TF1 * f_a2_HE2123 = new TF1( "a2_HE2123", fitResults::a2_2123, 0 , 10000, 0);
  TF1 * f_a3_HE2123 = new TF1( "a3_HE2123", fitResults::a3_2123, 0 , 10000, 0);

  TF1 * f_a0_HE2425 = new TF1( "a0_HE2425", fitResults::a0_2425, 0 , 10000, 0);
  TF1 * f_a1_HE2425 = new TF1( "a1_HE2425", fitResults::a1_2425, 0 , 10000, 0);
  TF1 * f_a2_HE2425 = new TF1( "a2_HE2425", fitResults::a2_2425, 0 , 10000, 0);
  TF1 * f_a3_HE2425 = new TF1( "a3_HE2425", fitResults::a3_2425, 0 , 10000, 0);

  TF1 * f_a0_HE2627 = new TF1( "a0_HE2627", fitResults::a0_2627, 0 , 10000, 0);
  TF1 * f_a1_HE2627 = new TF1( "a1_HE2627", fitResults::a1_2627, 0 , 10000, 0);
  TF1 * f_a2_HE2627 = new TF1( "a2_HE2627", fitResults::a2_2627, 0 , 10000, 0);
  TF1 * f_a3_HE2627 = new TF1( "a3_HE2627", fitResults::a3_2627, 0 , 10000, 0);

  TF1 * f_a0_HE2828 = new TF1( "a0_HE2828", fitResults::a0_28  , 0 , 10000, 0);
  TF1 * f_a1_HE2828 = new TF1( "a1_HE2828", fitResults::a1_28  , 0 , 10000, 0);
  TF1 * f_a2_HE2828 = new TF1( "a2_HE2828", fitResults::a2_28  , 0 , 10000, 0);
  TF1 * f_a3_HE2828 = new TF1( "a3_HE2828", fitResults::a3_28  , 0 , 10000, 0);

  std::vector<TF1*> v_a0, v_a1, v_a2, v_a3;
  
  v_a0.push_back(f_a0_HB    );
  v_a0.push_back(f_a0_HE1720);
  v_a0.push_back(f_a0_HE2123);
  v_a0.push_back(f_a0_HE2425);
  v_a0.push_back(f_a0_HE2627);
  v_a0.push_back(f_a0_HE2828);
  
  v_a1.push_back(f_a1_HB    );
  v_a1.push_back(f_a1_HE1720);
  v_a1.push_back(f_a1_HE2123);
  v_a1.push_back(f_a1_HE2425);
  v_a1.push_back(f_a1_HE2627);
  v_a1.push_back(f_a1_HE2828);
  
  v_a2.push_back(f_a2_HB    );
  v_a2.push_back(f_a2_HE1720);
  v_a2.push_back(f_a2_HE2123);
  v_a2.push_back(f_a2_HE2425);
  v_a2.push_back(f_a2_HE2627);
  v_a2.push_back(f_a2_HE2828);

  v_a3.push_back(f_a3_HB    );
  v_a3.push_back(f_a3_HE1720);
  v_a3.push_back(f_a3_HE2123);
  v_a3.push_back(f_a3_HE2425);
  v_a3.push_back(f_a3_HE2627);
  v_a3.push_back(f_a3_HE2828);
  
  //--------------------------------------------------------------------------------
  // Declare HCAL trees
  //--------------------------------------------------------------------------------

  HcalNoiseTree * no_pu_tree = getTree<HcalNoiseTree>("noise_tree", "no_pu_files" );
  HcalNoiseTree * pu_50_tree = getTree<HcalNoiseTree>("noise_tree", "pu_50_files" );
  
  int n_events = TMath::Min( no_pu_tree -> fChain -> GetEntries(),
			     pu_50_tree -> fChain -> GetEntries());
  
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

  TH1F * h_correction        = makeTH1F("correction"       , 200, -200, 200);
  TH1F * h_delta_corrected   = makeTH1F("delta_corrected"  , 200, -200, 200);
  TH1F * h_delta_uncorrected = makeTH1F("delta_uncorrected", 200, -200, 200);
  TH1F * h_cross_check_a0    = makeTH1F("crosscheck_a0"    , 200, -200, 200);
  TH1F * h_cross_check_a1    = makeTH1F("crosscheck_a1"    , 200, -200, 200);
  TH1F * h_cross_check_a2    = makeTH1F("crosscheck_a2"    , 200, -200, 200);
  TH1F * h_cross_check_a3    = makeTH1F("crosscheck_a3"    , 200, -200, 200);

  TH1F * h_cross_check_a0_HB = makeTH1F("crosscheck_a0_HB" , 200, -200, 200);
  TH1F * h_cross_check_a1_HB = makeTH1F("crosscheck_a1_HB" , 200, -200, 200);
  TH1F * h_cross_check_a2_HB = makeTH1F("crosscheck_a2_HB" , 200, -200, 200);
  TH1F * h_cross_check_a3_HB = makeTH1F("crosscheck_a3_HB" , 200, -200, 200);
  
  TH1F * h_cross_check_a0_HE = makeTH1F("crosscheck_a0_HE" , 200, -200, 200);
  TH1F * h_cross_check_a1_HE = makeTH1F("crosscheck_a1_HE" , 200, -200, 200);
  TH1F * h_cross_check_a2_HE = makeTH1F("crosscheck_a2_HE" , 200, -200, 200);
  TH1F * h_cross_check_a3_HE = makeTH1F("crosscheck_a3_HE" , 200, -200, 200);

  TH1F * h_cross_check_a0_HE1720 = makeTH1F("crosscheck_a0_HE1720" , 200, -200, 200);
  TH1F * h_cross_check_a1_HE1720 = makeTH1F("crosscheck_a1_HE1720" , 200, -200, 200);
  TH1F * h_cross_check_a2_HE1720 = makeTH1F("crosscheck_a2_HE1720" , 200, -200, 200);
  TH1F * h_cross_check_a3_HE1720 = makeTH1F("crosscheck_a3_HE1720" , 200, -200, 200);

  TH1F * h_cross_check_a0_HE2123 = makeTH1F("crosscheck_a0_HE2123" , 200, -200, 200);
  TH1F * h_cross_check_a1_HE2123 = makeTH1F("crosscheck_a1_HE2123" , 200, -200, 200);
  TH1F * h_cross_check_a2_HE2123 = makeTH1F("crosscheck_a2_HE2123" , 200, -200, 200);
  TH1F * h_cross_check_a3_HE2123 = makeTH1F("crosscheck_a3_HE2123" , 200, -200, 200);
  
  TH1F * h_cross_check_a0_HE2425 = makeTH1F("crosscheck_a0_HE2425" , 200, -200, 200);
  TH1F * h_cross_check_a1_HE2425 = makeTH1F("crosscheck_a1_HE2425" , 200, -200, 200);
  TH1F * h_cross_check_a2_HE2425 = makeTH1F("crosscheck_a2_HE2425" , 200, -200, 200);
  TH1F * h_cross_check_a3_HE2425 = makeTH1F("crosscheck_a3_HE2425" , 200, -200, 200);

  TH1F * h_cross_check_a0_HE2627 = makeTH1F("crosscheck_a0_HE2627" , 200, -200, 200);
  TH1F * h_cross_check_a1_HE2627 = makeTH1F("crosscheck_a1_HE2627" , 200, -200, 200);
  TH1F * h_cross_check_a2_HE2627 = makeTH1F("crosscheck_a2_HE2627" , 200, -200, 200);
  TH1F * h_cross_check_a3_HE2627 = makeTH1F("crosscheck_a3_HE2627" , 200, -200, 200);

  TH1F * h_cross_check_a0_HE2828 = makeTH1F("crosscheck_a0_HE2828" , 200, -200, 200);
  TH1F * h_cross_check_a1_HE2828 = makeTH1F("crosscheck_a1_HE2828" , 200, -200, 200);
  TH1F * h_cross_check_a2_HE2828 = makeTH1F("crosscheck_a2_HE2828" , 200, -200, 200);
  TH1F * h_cross_check_a3_HE2828 = makeTH1F("crosscheck_a3_HE2828" , 200, -200, 200);

  char hist_name[100];

  std::vector<TH2F*> h_TS4_vs_delta_uncorrected;
  std::vector<TH2F*> h_TS4_vs_delta_corrected;

  std::vector<TH2F*> h_TS4_vs_delta_uncorrected_over50;
  std::vector<TH2F*> h_TS4_vs_delta_corrected_over50;

  std::vector<TH2F*> h_TS4_vs_delta_uncorrected_over500;
  std::vector<TH2F*> h_TS4_vs_delta_corrected_over500;

  std::vector<TH2F*> h_TS4_vs_cross_check_a0;
  std::vector<TH2F*> h_TS4_vs_cross_check_a1;
  std::vector<TH2F*> h_TS4_vs_cross_check_a2;
  std::vector<TH2F*> h_TS4_vs_cross_check_a3;

  std::vector<TH2F*> h_TS4_vs_cross_check_over50_a0;
  std::vector<TH2F*> h_TS4_vs_cross_check_over50_a1;
  std::vector<TH2F*> h_TS4_vs_cross_check_over50_a2;
  std::vector<TH2F*> h_TS4_vs_cross_check_over50_a3;

  std::vector<TH2F*> h_TS4_vs_cross_check_over500_a0;
  std::vector<TH2F*> h_TS4_vs_cross_check_over500_a1;
  std::vector<TH2F*> h_TS4_vs_cross_check_over500_a2;
  std::vector<TH2F*> h_TS4_vs_cross_check_over500_a3;

  std::vector<TH2F*> h_TS4_vs_delta0;
  std::vector<TH2F*> h_TS4_vs_delta1;
  std::vector<TH2F*> h_TS4_vs_delta2;
  std::vector<TH2F*> h_TS4_vs_delta3;
  std::vector<TH2F*> h_TS4_vs_delta4;
  std::vector<TH2F*> h_TS4_vs_delta5;
  std::vector<TH2F*> h_TS4_vs_delta6;
  std::vector<TH2F*> h_TS4_vs_delta7;
  std::vector<TH2F*> h_TS4_vs_delta8;
  std::vector<TH2F*> h_TS4_vs_delta9;

  std::vector<TH2F*> h_TS4_vs_delta0_over100;
  std::vector<TH2F*> h_TS4_vs_delta1_over100;
  std::vector<TH2F*> h_TS4_vs_delta2_over100;
  std::vector<TH2F*> h_TS4_vs_delta3_over100;
  std::vector<TH2F*> h_TS4_vs_delta4_over100;
  std::vector<TH2F*> h_TS4_vs_delta5_over100;
  std::vector<TH2F*> h_TS4_vs_delta6_over100;
  std::vector<TH2F*> h_TS4_vs_delta7_over100;
  std::vector<TH2F*> h_TS4_vs_delta8_over100;
  std::vector<TH2F*> h_TS4_vs_delta9_over100;

  for (int iring = 0; iring < 6; ++iring){
    
    sprintf(hist_name, "TS4_vs_delta0_ring%d"                   , iring); h_TS4_vs_delta0                    .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
    sprintf(hist_name, "TS4_vs_delta1_ring%d"                   , iring); h_TS4_vs_delta1                    .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
    sprintf(hist_name, "TS4_vs_delta2_ring%d"                   , iring); h_TS4_vs_delta2                    .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
    sprintf(hist_name, "TS4_vs_delta3_ring%d"                   , iring); h_TS4_vs_delta3                    .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
    sprintf(hist_name, "TS4_vs_delta4_ring%d"                   , iring); h_TS4_vs_delta4                    .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
    sprintf(hist_name, "TS4_vs_delta5_ring%d"                   , iring); h_TS4_vs_delta5                    .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
    sprintf(hist_name, "TS4_vs_delta6_ring%d"                   , iring); h_TS4_vs_delta6                    .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
    sprintf(hist_name, "TS4_vs_delta7_ring%d"                   , iring); h_TS4_vs_delta7                    .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
    sprintf(hist_name, "TS4_vs_delta8_ring%d"                   , iring); h_TS4_vs_delta8                    .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
    sprintf(hist_name, "TS4_vs_delta9_ring%d"                   , iring); h_TS4_vs_delta9                    .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
    
    sprintf(hist_name, "TS4_vs_delta0_over100_ring%d"           , iring); h_TS4_vs_delta0_over100            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -2, 2));
    sprintf(hist_name, "TS4_vs_delta1_over100_ring%d"           , iring); h_TS4_vs_delta1_over100            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -2, 2));
    sprintf(hist_name, "TS4_vs_delta2_over100_ring%d"           , iring); h_TS4_vs_delta2_over100            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -2, 2));
    sprintf(hist_name, "TS4_vs_delta3_over100_ring%d"           , iring); h_TS4_vs_delta3_over100            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -2, 2));
    sprintf(hist_name, "TS4_vs_delta4_over100_ring%d"           , iring); h_TS4_vs_delta4_over100            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -2, 2));
    sprintf(hist_name, "TS4_vs_delta5_over100_ring%d"           , iring); h_TS4_vs_delta5_over100            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -2, 2));
    sprintf(hist_name, "TS4_vs_delta6_over100_ring%d"           , iring); h_TS4_vs_delta6_over100            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -2, 2));
    sprintf(hist_name, "TS4_vs_delta7_over100_ring%d"           , iring); h_TS4_vs_delta7_over100            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -2, 2));
    sprintf(hist_name, "TS4_vs_delta8_over100_ring%d"           , iring); h_TS4_vs_delta8_over100            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -2, 2));
    sprintf(hist_name, "TS4_vs_delta9_over100_ring%d"           , iring); h_TS4_vs_delta9_over100            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -2, 2));
    
    sprintf(hist_name, "TS4_vs_crosscheck_a0_ring%d"            , iring); h_TS4_vs_cross_check_a0            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
    sprintf(hist_name, "TS4_vs_crosscheck_a1_ring%d"            , iring); h_TS4_vs_cross_check_a1            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
    sprintf(hist_name, "TS4_vs_crosscheck_a2_ring%d"            , iring); h_TS4_vs_cross_check_a2            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
    sprintf(hist_name, "TS4_vs_crosscheck_a3_ring%d"            , iring); h_TS4_vs_cross_check_a3            .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -200, 200));
							        					     
    sprintf(hist_name, "TS4_vs_crosscheck_over50_a0_ring%d"     , iring); h_TS4_vs_cross_check_over50_a0     .push_back ( makeTH2F ( hist_name, 200, 50, 5000, 200, -10  , 10 ));
    sprintf(hist_name, "TS4_vs_crosscheck_over50_a1_ring%d"     , iring); h_TS4_vs_cross_check_over50_a1     .push_back ( makeTH2F ( hist_name, 200, 50, 5000, 200, -10  , 10 ));
    sprintf(hist_name, "TS4_vs_crosscheck_over50_a2_ring%d"     , iring); h_TS4_vs_cross_check_over50_a2     .push_back ( makeTH2F ( hist_name, 200, 50, 5000, 200, -10  , 10 ));
    sprintf(hist_name, "TS4_vs_crosscheck_over50_a3_ring%d"     , iring); h_TS4_vs_cross_check_over50_a3     .push_back ( makeTH2F ( hist_name, 200, 50, 5000, 200, -10  , 10 ));
							        					     
    sprintf(hist_name, "TS4_vs_crosscheck_over500_a0_ring%d"    , iring); h_TS4_vs_cross_check_over500_a0    .push_back ( makeTH2F ( hist_name, 200, 500, 5000, 200, -10 , 10 ));
    sprintf(hist_name, "TS4_vs_crosscheck_over500_a1_ring%d"    , iring); h_TS4_vs_cross_check_over500_a1    .push_back ( makeTH2F ( hist_name, 200, 500, 5000, 200, -10 , 10 ));
    sprintf(hist_name, "TS4_vs_crosscheck_over500_a2_ring%d"    , iring); h_TS4_vs_cross_check_over500_a2    .push_back ( makeTH2F ( hist_name, 200, 500, 5000, 200, -10 , 10 ));
    sprintf(hist_name, "TS4_vs_crosscheck_over500_a3_ring%d"    , iring); h_TS4_vs_cross_check_over500_a3    .push_back ( makeTH2F ( hist_name, 200, 500, 5000, 200, -10 , 10 ));
    							        					     
    sprintf(hist_name, "TS4_vs_delta_uncorrected_ring%d"        , iring); h_TS4_vs_delta_uncorrected         .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -10, 10));
    sprintf(hist_name, "TS4_vs_delta_corrected_ring%d"          , iring); h_TS4_vs_delta_corrected           .push_back ( makeTH2F ( hist_name, 200, 0  , 5000, 200, -10, 10));

    sprintf(hist_name, "TS4_vs_delta_uncorrected_over50_ring%d" , iring); h_TS4_vs_delta_uncorrected_over50  .push_back ( makeTH2F ( hist_name, 200, 50 , 5000, 200, -1, 1));
    sprintf(hist_name, "TS4_vs_delta_corrected_over50_ring%d"   , iring); h_TS4_vs_delta_corrected_over50    .push_back ( makeTH2F ( hist_name, 200, 50 , 5000, 200, -1, 1));

    sprintf(hist_name, "TS4_vs_delta_uncorrected_over500_ring%d", iring); h_TS4_vs_delta_uncorrected_over500 .push_back ( makeTH2F ( hist_name, 200, 500, 5000, 200, -1, 1));
    sprintf(hist_name, "TS4_vs_delta_corrected_over500_ring%d"  , iring); h_TS4_vs_delta_corrected_over500   .push_back ( makeTH2F ( hist_name, 200, 500, 5000, 200, -1, 1));
  }

  //--------------------------------------------------------------------------------
  // Loop over the events
  //--------------------------------------------------------------------------------
  
  for (int iEvent = 0; iEvent < 2300; ++iEvent){
  // for (int iEvent = 0; iEvent < n_events; ++iEvent){

    //--------------------------------------------------------------------------------
    // Tell the user where we are
    //--------------------------------------------------------------------------------

    if (iEvent%100 == 0) std::cout << "Processing event " << iEvent << "/" << n_events << std::endl;
    
    //--------------------------------------------------------------------------------
    // Get each entry in the event
    //--------------------------------------------------------------------------------

    no_pu_tree -> GetEntry(iEvent);
    pu_50_tree -> GetEntry(iEvent);

    //--------------------------------------------------------------------------------
    // Assert that we're on the same event
    //--------------------------------------------------------------------------------

    if (no_pu_tree -> EventNumber != pu_50_tree -> EventNumber){
      std::cout << "PU 50 run number   = " << pu_50_tree -> RunNumber << std::endl;
      std::cout << "No PU run number   = " << no_pu_tree -> RunNumber << std::endl; 
      std::cout << "PU 50 event number = " << pu_50_tree -> EventNumber << std::endl;
      std::cout << "No PU event number = " << no_pu_tree -> EventNumber << std::endl;
    }

    assert(no_pu_tree -> RunNumber   == pu_50_tree -> RunNumber  );
    assert(no_pu_tree -> EventNumber == pu_50_tree -> EventNumber);
    assert(no_pu_tree -> LumiSection == pu_50_tree -> LumiSection);

    //--------------------------------------------------------------------------------
    // Loop over digis
    //--------------------------------------------------------------------------------

    int pu_50_nHBHE = pu_50_tree -> PulseCount;
    int no_pu_nHBHE = no_pu_tree -> PulseCount;

    for(int pu_50_iHBHE = 0; pu_50_iHBHE < pu_50_nHBHE; ++pu_50_iHBHE){
      // for(int pu_50_iHBHE = 10; pu_50_iHBHE < 11; ++pu_50_iHBHE){
      
      int pu_50_ieta  = pu_50_tree -> IEta [pu_50_iHBHE];
      int pu_50_iphi  = pu_50_tree -> IPhi [pu_50_iHBHE];
      int pu_50_depth = pu_50_tree -> Depth[pu_50_iHBHE];
      int pu_50_ring  = getRing ( pu_50_ieta );
      
      float pu_50_TS0 = pu_50_tree -> Charge[pu_50_iHBHE][0];
      float pu_50_TS1 = pu_50_tree -> Charge[pu_50_iHBHE][1];
      float pu_50_TS2 = pu_50_tree -> Charge[pu_50_iHBHE][2];
      float pu_50_TS3 = pu_50_tree -> Charge[pu_50_iHBHE][3];
      float pu_50_TS4 = pu_50_tree -> Charge[pu_50_iHBHE][4];
      float pu_50_TS5 = pu_50_tree -> Charge[pu_50_iHBHE][5];
      float pu_50_TS6 = pu_50_tree -> Charge[pu_50_iHBHE][6];
      float pu_50_TS7 = pu_50_tree -> Charge[pu_50_iHBHE][7];
      float pu_50_TS8 = pu_50_tree -> Charge[pu_50_iHBHE][8];
      float pu_50_TS9 = pu_50_tree -> Charge[pu_50_iHBHE][9];

      float pu_50_TS45 = pu_50_TS4 + pu_50_TS5;

      float pu_50_TS3_prime  = TMath::Max(0.,pu_50_TS3        - (v_a0[pu_50_ring] -> Eval(pu_50_TS4)        * pu_50_TS4));
      float pu_50_TS3_prime2 = TMath::Max(0.,pu_50_TS3_prime  - (v_a1[pu_50_ring] -> Eval(pu_50_TS2)        * pu_50_TS2));
      float pu_50_TS4_prime  = pu_50_TS4        - (v_a1[pu_50_ring] -> Eval(pu_50_TS3_prime2) * pu_50_TS3_prime2) - (v_a2[pu_50_ring] -> Eval(pu_50_TS2) * pu_50_TS2);
      float pu_50_TS5_prime  = pu_50_TS5        - (v_a2[pu_50_ring] -> Eval(pu_50_TS3_prime2) * pu_50_TS3_prime2) - (v_a3[pu_50_ring] -> Eval(pu_50_TS2) * pu_50_TS2);
      float pu_50_TS45_prime = pu_50_TS4_prime  + pu_50_TS5_prime;

      for(int no_pu_iHBHE = 0; no_pu_iHBHE < no_pu_nHBHE; ++no_pu_iHBHE){
      // for(int no_pu_iHBHE = 6; no_pu_iHBHE < 7; ++no_pu_iHBHE){
	
	int no_pu_ieta  = no_pu_tree -> IEta [no_pu_iHBHE];
	int no_pu_iphi  = no_pu_tree -> IPhi [no_pu_iHBHE];
	int no_pu_depth = no_pu_tree -> Depth[no_pu_iHBHE];
	int no_pu_ring  = getRing ( no_pu_ieta );
	
	if (no_pu_ieta  != pu_50_ieta ) continue;
	if (no_pu_iphi  != pu_50_iphi ) continue;
	if (no_pu_depth != pu_50_depth) continue;
	
	bool isHB = (no_pu_ring == 0);
	bool isHE = (no_pu_ring != 0);

	float no_pu_TS0 = no_pu_tree -> Charge[no_pu_iHBHE][0];
	float no_pu_TS1 = no_pu_tree -> Charge[no_pu_iHBHE][1];
	float no_pu_TS2 = no_pu_tree -> Charge[no_pu_iHBHE][2];
	float no_pu_TS3 = no_pu_tree -> Charge[no_pu_iHBHE][3];
	float no_pu_TS4 = no_pu_tree -> Charge[no_pu_iHBHE][4];
	float no_pu_TS5 = no_pu_tree -> Charge[no_pu_iHBHE][5];
	float no_pu_TS6 = no_pu_tree -> Charge[no_pu_iHBHE][6];
	float no_pu_TS7 = no_pu_tree -> Charge[no_pu_iHBHE][7];
	float no_pu_TS8 = no_pu_tree -> Charge[no_pu_iHBHE][8];
	float no_pu_TS9 = no_pu_tree -> Charge[no_pu_iHBHE][9];

	float no_pu_TS45 = no_pu_TS4 + no_pu_TS5;
	
	float delta0 = (pu_50_TS0 - no_pu_TS0) / no_pu_TS0;
	float delta1 = (pu_50_TS1 - no_pu_TS1) / no_pu_TS1;
	float delta2 = (pu_50_TS2 - no_pu_TS2) / no_pu_TS2;
	float delta3 = (pu_50_TS3 - no_pu_TS3) / no_pu_TS3;
	float delta4 = (pu_50_TS4 - no_pu_TS4) / no_pu_TS4;
	float delta5 = (pu_50_TS5 - no_pu_TS5) / no_pu_TS5;
	float delta6 = (pu_50_TS6 - no_pu_TS6) / no_pu_TS6;
	float delta7 = (pu_50_TS7 - no_pu_TS7) / no_pu_TS7;
	float delta8 = (pu_50_TS8 - no_pu_TS8) / no_pu_TS8;
	float delta9 = (pu_50_TS9 - no_pu_TS9) / no_pu_TS9;

	float cross_check_a0 = (no_pu_TS3 - (v_a0[no_pu_ring] -> Eval(no_pu_TS4) * no_pu_TS4)) / no_pu_TS3;
	float cross_check_a1 = (no_pu_TS5 - (v_a1[no_pu_ring] -> Eval(no_pu_TS4) * no_pu_TS4)) / no_pu_TS5;
	float cross_check_a2 = (no_pu_TS6 - (v_a2[no_pu_ring] -> Eval(no_pu_TS4) * no_pu_TS4)) / no_pu_TS6;
	float cross_check_a3 = (no_pu_TS7 - (v_a3[no_pu_ring] -> Eval(no_pu_TS4) * no_pu_TS4)) / no_pu_TS7;

	float delta_uncorrected = (pu_50_TS45       - no_pu_TS45) / no_pu_TS45;
	float delta_corrected   = (pu_50_TS45_prime - no_pu_TS45) / no_pu_TS45;
	float correction        = (pu_50_TS45_prime - pu_50_TS45);
	
	/*
	std::cout << "no pu" << "\t" << "pu 50" << std::endl;
	for (int i = 0; i < 10; ++i){
	  std::cout << i << "\t" << no_pu_tree -> Charge[no_pu_iHBHE][i] << "\t" << pu_50_tree -> Charge[pu_50_iHBHE][i] << std::endl;
	}
	
	std::cout << "3'\t"  << pu_50_TS3_prime  << std::endl;
	std::cout << "3''\t" << pu_50_TS3_prime2 << std::endl;
	std::cout << "4'\t"  << pu_50_TS4_prime  << std::endl;
	std::cout << "5'\t"  << pu_50_TS5_prime  << std::endl;
	std::cout << "45'\t" << pu_50_TS45_prime << std::endl;
	std::cout << "45 \t" << pu_50_TS45       << std::endl;

	std::cout << "Predicted time slew from TS4 into TS3     (take from TS3):\t" << v_a0[pu_50_ring] -> Eval(pu_50_TS4) * pu_50_TS4 << "\t" << "Argument = TS4 = " << pu_50_TS4 << std::endl;
	std::cout << "Predicted contamination from TS2 into TS3 (take from TS3):\t" << v_a1[pu_50_ring] -> Eval(pu_50_TS2) * pu_50_TS2 << "\t" << "Argument = TS2 = " << pu_50_TS2 << std::endl;
	*/
	
	h_correction        -> Fill(correction);
	h_delta_corrected   -> Fill(delta_corrected);
	h_delta_uncorrected -> Fill(delta_uncorrected);
	
	h_cross_check_a0    -> Fill(cross_check_a0);
	h_cross_check_a1    -> Fill(cross_check_a1);
	h_cross_check_a2    -> Fill(cross_check_a2);
	h_cross_check_a3    -> Fill(cross_check_a3);

	h_TS4_vs_delta0[no_pu_ring] -> Fill(pu_50_TS4, delta0);
	h_TS4_vs_delta1[no_pu_ring] -> Fill(pu_50_TS4, delta1);
	h_TS4_vs_delta2[no_pu_ring] -> Fill(pu_50_TS4, delta2);
	h_TS4_vs_delta3[no_pu_ring] -> Fill(pu_50_TS4, delta3);
	h_TS4_vs_delta4[no_pu_ring] -> Fill(pu_50_TS4, delta4);
	h_TS4_vs_delta5[no_pu_ring] -> Fill(pu_50_TS4, delta5);
	h_TS4_vs_delta6[no_pu_ring] -> Fill(pu_50_TS4, delta6);
	h_TS4_vs_delta7[no_pu_ring] -> Fill(pu_50_TS4, delta7);
	h_TS4_vs_delta8[no_pu_ring] -> Fill(pu_50_TS4, delta8);
	h_TS4_vs_delta9[no_pu_ring] -> Fill(pu_50_TS4, delta9);

	if ( pu_50_TS4 > 100. ){

	  h_TS4_vs_delta0_over100[no_pu_ring] -> Fill(pu_50_TS4, delta0);
	  h_TS4_vs_delta1_over100[no_pu_ring] -> Fill(pu_50_TS4, delta1);
	  h_TS4_vs_delta2_over100[no_pu_ring] -> Fill(pu_50_TS4, delta2);
	  h_TS4_vs_delta3_over100[no_pu_ring] -> Fill(pu_50_TS4, delta3);
	  h_TS4_vs_delta4_over100[no_pu_ring] -> Fill(pu_50_TS4, delta4);
	  h_TS4_vs_delta5_over100[no_pu_ring] -> Fill(pu_50_TS4, delta5);
	  h_TS4_vs_delta6_over100[no_pu_ring] -> Fill(pu_50_TS4, delta6);
	  h_TS4_vs_delta7_over100[no_pu_ring] -> Fill(pu_50_TS4, delta7);
	  h_TS4_vs_delta8_over100[no_pu_ring] -> Fill(pu_50_TS4, delta8);
	  h_TS4_vs_delta9_over100[no_pu_ring] -> Fill(pu_50_TS4, delta9);

	}

	h_TS4_vs_cross_check_a0[no_pu_ring] -> Fill (no_pu_TS4, cross_check_a0);
	h_TS4_vs_cross_check_a1[no_pu_ring] -> Fill (no_pu_TS4, cross_check_a1);
	h_TS4_vs_cross_check_a2[no_pu_ring] -> Fill (no_pu_TS4, cross_check_a2);
	h_TS4_vs_cross_check_a3[no_pu_ring] -> Fill (no_pu_TS4, cross_check_a3);


	h_TS4_vs_delta_uncorrected[no_pu_ring] -> Fill(no_pu_TS45, delta_uncorrected);
	h_TS4_vs_delta_corrected  [no_pu_ring] -> Fill(no_pu_TS45, delta_corrected  );

	if ( no_pu_TS4 > 50 ){
	  h_TS4_vs_cross_check_over50_a0[no_pu_ring] -> Fill (no_pu_TS4, cross_check_a0);
	  h_TS4_vs_cross_check_over50_a1[no_pu_ring] -> Fill (no_pu_TS4, cross_check_a1);
	  h_TS4_vs_cross_check_over50_a2[no_pu_ring] -> Fill (no_pu_TS4, cross_check_a2);
	  h_TS4_vs_cross_check_over50_a3[no_pu_ring] -> Fill (no_pu_TS4, cross_check_a3);
	  
	  h_TS4_vs_delta_uncorrected_over50[no_pu_ring] -> Fill(no_pu_TS45, delta_uncorrected);
	  h_TS4_vs_delta_corrected_over50  [no_pu_ring] -> Fill(no_pu_TS45, delta_corrected  );
	}

	if ( no_pu_TS4 > 500 ){
	  h_TS4_vs_cross_check_over500_a0[no_pu_ring] -> Fill (no_pu_TS4, cross_check_a0);
	  h_TS4_vs_cross_check_over500_a1[no_pu_ring] -> Fill (no_pu_TS4, cross_check_a1);
	  h_TS4_vs_cross_check_over500_a2[no_pu_ring] -> Fill (no_pu_TS4, cross_check_a2);
	  h_TS4_vs_cross_check_over500_a3[no_pu_ring] -> Fill (no_pu_TS4, cross_check_a3);

	  h_TS4_vs_delta_uncorrected_over500[no_pu_ring] -> Fill(no_pu_TS45, delta_uncorrected);
	  h_TS4_vs_delta_corrected_over500  [no_pu_ring] -> Fill(no_pu_TS45, delta_corrected  );
	}

	if (isHB){
	  h_cross_check_a0_HB -> Fill(cross_check_a0);
	  h_cross_check_a1_HB -> Fill(cross_check_a1);
	  h_cross_check_a2_HB -> Fill(cross_check_a2);
	  h_cross_check_a3_HB -> Fill(cross_check_a3);
	}

	if (isHE){
	  h_cross_check_a0_HE -> Fill(cross_check_a0);
	  h_cross_check_a1_HE -> Fill(cross_check_a1);
	  h_cross_check_a2_HE -> Fill(cross_check_a2);
	  h_cross_check_a3_HE -> Fill(cross_check_a3);
	}
	
      }
    }
  }
}
