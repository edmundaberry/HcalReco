#include "analysisClass.h"
#include "HcalNoiseTree.h"

#include "TH1F.h"
#include "TChain.h"

#include <iostream>
#include <assert.h>  
#include <cmath>

void analysisClass::loop(){

  //--------------------------------------------------------------------------------
  // Declare HCAL trees
  //--------------------------------------------------------------------------------

  HcalNoiseTree * noise_tree = getTree<HcalNoiseTree>("noise");

  //--------------------------------------------------------------------------------
  // How many events to cycle over? 
  // Is there a more elegant way to do this?
  //--------------------------------------------------------------------------------

  int n_events = noise_tree -> fChain -> GetEntries();

  //--------------------------------------------------------------------------------
  // Declare some important quantities
  //--------------------------------------------------------------------------------
  
  const int max_npv        =  50;
  const int n_trig_towers  =  64;
  const int max_trig_tower =  32;
  const int min_trig_tower = -32;
  const int abs_min_trig_tower = std::abs(min_trig_tower);

  //--------------------------------------------------------------------------------
  // Declare histograms
  //--------------------------------------------------------------------------------

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

    noise_tree -> GetEntry(iEvent);

    //--------------------------------------------------------------------------------
    // Fill sumETs vs NPV
    //--------------------------------------------------------------------------------

    int npv = noise_tree -> NumberOfGoodPrimaryVertices;

  }
}
