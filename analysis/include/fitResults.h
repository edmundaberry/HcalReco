#ifndef FIT_RESULTS_H
#define FIT_RESULTS_H

#include "TMath.h"

class fitResults{

 public:
  
  static Double_t a0_HB   (Double_t * x, Double_t * par);
  static Double_t a1_HB   (Double_t * x, Double_t * par);
  static Double_t a2_HB   (Double_t * x, Double_t * par);
  static Double_t a3_HB   (Double_t * x, Double_t * par);

  static Double_t a0_1720 (Double_t * x, Double_t * par);
  static Double_t a1_1720 (Double_t * x, Double_t * par);
  static Double_t a2_1720 (Double_t * x, Double_t * par);
  static Double_t a3_1720 (Double_t * x, Double_t * par);

  static Double_t a0_2123 (Double_t * x, Double_t * par);
  static Double_t a1_2123 (Double_t * x, Double_t * par);
  static Double_t a2_2123 (Double_t * x, Double_t * par);
  static Double_t a3_2123 (Double_t * x, Double_t * par);
  
  static Double_t a0_2425 (Double_t * x, Double_t * par);
  static Double_t a1_2425 (Double_t * x, Double_t * par);
  static Double_t a2_2425 (Double_t * x, Double_t * par);
  static Double_t a3_2425 (Double_t * x, Double_t * par);

  static Double_t a0_2627 (Double_t * x, Double_t * par);
  static Double_t a1_2627 (Double_t * x, Double_t * par);
  static Double_t a2_2627 (Double_t * x, Double_t * par);
  static Double_t a3_2627 (Double_t * x, Double_t * par);
  
  static Double_t a0_28   (Double_t * x, Double_t * par);
  static Double_t a1_28   (Double_t * x, Double_t * par);
  static Double_t a2_28   (Double_t * x, Double_t * par);
  static Double_t a3_28   (Double_t * x, Double_t * par);
  
};

#endif
