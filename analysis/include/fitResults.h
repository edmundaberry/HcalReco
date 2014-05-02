#ifndef FIT_RESULTS_H
#define FIT_RESULTS_H

#include "TMath.h"

class fitResults{

 public:
  
  static Double_t a0_HB     (Double_t * x, Double_t * par);
  static Double_t a1_HB     (Double_t * x, Double_t * par);
  static Double_t a2_HB     (Double_t * x, Double_t * par);
  static Double_t a3_HB     (Double_t * x, Double_t * par);

  static Double_t a0_HE1720 (Double_t * x, Double_t * par);
  static Double_t a1_HE1720 (Double_t * x, Double_t * par);
  static Double_t a2_HE1720 (Double_t * x, Double_t * par);
  static Double_t a3_HE1720 (Double_t * x, Double_t * par);

  static Double_t a0_HE2123 (Double_t * x, Double_t * par);
  static Double_t a1_HE2123 (Double_t * x, Double_t * par);
  static Double_t a2_HE2123 (Double_t * x, Double_t * par);
  static Double_t a3_HE2123 (Double_t * x, Double_t * par);
  
  static Double_t a0_HE2425 (Double_t * x, Double_t * par);
  static Double_t a1_HE2425 (Double_t * x, Double_t * par);
  static Double_t a2_HE2425 (Double_t * x, Double_t * par);
  static Double_t a3_HE2425 (Double_t * x, Double_t * par);

  static Double_t a0_HE2627 (Double_t * x, Double_t * par);
  static Double_t a1_HE2627 (Double_t * x, Double_t * par);
  static Double_t a2_HE2627 (Double_t * x, Double_t * par);
  static Double_t a3_HE2627 (Double_t * x, Double_t * par);
  
  static Double_t a0_HE2828 (Double_t * x, Double_t * par);
  static Double_t a1_HE2828 (Double_t * x, Double_t * par);
  static Double_t a2_HE2828 (Double_t * x, Double_t * par);
  static Double_t a3_HE2828 (Double_t * x, Double_t * par);
  
};

#endif
