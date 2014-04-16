//------------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------------

#include "TFile.h"
#include "TH2F.h"
#include "TF1.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TStyle.h"

//------------------------------------------------------------------------------------
// Set important variables for the user to tinker with
//------------------------------------------------------------------------------------

Int_t    min_function = 1;
Int_t    max_function = 3;
Int_t    min_ring     = 0;
Int_t    max_ring     = 5;
Int_t    rebinx       = 5;
Int_t    rebiny       = 1;
Double_t fit_xmin     = 5.;
Double_t fit_xmax     = 1500.;
Double_t plot_xmin    = 0.;
Double_t plot_xmax    = 1500.;
bool     draw_pieces  = false;

//------------------------------------------------------------------------------------
// Define boundaries per ring
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
// Define polynomials
//------------------------------------------------------------------------------------

Double_t pol1(Double_t x, Double_t par0, Double_t par1){
  Double_t retval = 0.;
  retval += par0;
  retval += ( par1 * x );
  return retval;
}

Double_t pol3(Double_t x, Double_t par0, Double_t par1, Double_t par2, Double_t par3 ){
  Double_t retval = 0.;
  retval += par0;
  retval += ( par1 * x );
  retval += ( par2 * x * x );
  retval += ( par3 * x * x * x );
  return retval;
}

Double_t pol4(Double_t x, Double_t par0, Double_t par1, Double_t par2, Double_t par3, Double_t par4 ){
  Double_t retval = 0.;
  retval += par0;
  retval += ( par1 * x );
  retval += ( par2 * x * x );
  retval += ( par3 * x * x * x );
  retval += ( par4 * x * x * x * x );
  return retval;
}

//------------------------------------------------------------------------------------
// Define "offsets": y-intercepts of polynomials that ensure that the polynomials
// all fit together at the boundaries
//------------------------------------------------------------------------------------ 

Double_t getOffset1 ( TF1 * tmp_func ){
  Double_t limits0 = tmp_func -> GetParameter(0);
  Double_t par5    = tmp_func -> GetParameter(5);
  Double_t par6    = tmp_func -> GetParameter(6);
  Double_t par7    = tmp_func -> GetParameter(7);
  Double_t par8    = tmp_func -> GetParameter(8);
  Double_t par9    = tmp_func -> GetParameter(9);
  Double_t par10   = tmp_func -> GetParameter(10);
  Double_t par11   = tmp_func -> GetParameter(11);
  Double_t par12   = tmp_func -> GetParameter(12);
  Double_t par13   = tmp_func -> GetParameter(13);
  Double_t offset1 = pol4(limits0, par5, par6, par7, par8, par9) - (pol4(limits0, 0.0, par10, par11, par12, par13));
  return offset1;
}

Double_t getOffset2 ( TF1 * tmp_func ){
  Double_t limits1 = tmp_func -> GetParameter(1);
  Double_t par10   = tmp_func -> GetParameter(10);
  Double_t par11   = tmp_func -> GetParameter(11);
  Double_t par12   = tmp_func -> GetParameter(12);
  Double_t par13   = tmp_func -> GetParameter(13);
  Double_t par14   = tmp_func -> GetParameter(14);
  Double_t par15   = tmp_func -> GetParameter(15);
  Double_t par16   = tmp_func -> GetParameter(16);
  Double_t offset1 = getOffset1(tmp_func);
  Double_t offset2 = pol4(limits1, offset1, par10, par11, par12, par13) - pol3(limits1, 0.0, par14, par15, par16);
  return offset2;
}

Double_t getOffset3 ( TF1 * tmp_func ){
  Double_t limits2 = tmp_func -> GetParameter(2);
  Double_t par14   = tmp_func -> GetParameter(14);
  Double_t par15   = tmp_func -> GetParameter(15);
  Double_t par16   = tmp_func -> GetParameter(16);
  Double_t par17   = tmp_func -> GetParameter(17);
  Double_t par18   = tmp_func -> GetParameter(18);
  Double_t par19   = tmp_func -> GetParameter(19);
  Double_t offset2 = getOffset2(tmp_func);
  Double_t offset3 = pol3(limits2, offset2, par14, par15, par16) - pol3(limits2, 0.0, par17, par18, par19);
  return offset3;
}

Double_t getOffset4 ( TF1 * tmp_func ){
  Double_t limits3 = tmp_func -> GetParameter(3);
  Double_t par17   = tmp_func -> GetParameter(17);
  Double_t par18   = tmp_func -> GetParameter(18);
  Double_t par19   = tmp_func -> GetParameter(19);
  Double_t par20   = tmp_func -> GetParameter(20);
  Double_t offset3 = getOffset3(tmp_func);
  Double_t offset4 = pol3(limits3, offset3, par17, par18, par19) - pol1(limits3, 0.0, par20);
  return offset4;
}

Double_t getOffset5 ( TF1 * tmp_func ){
  Double_t limits4 = tmp_func -> GetParameter(4);
  Double_t par20   = tmp_func -> GetParameter(20);
  Double_t par21   = tmp_func -> GetParameter(21);
  Double_t offset4 = getOffset4(tmp_func);
  Double_t offset5 = pol1(limits4, offset4, par20) - pol1(limits4, 0.0, par21);
  return offset5;
}

//------------------------------------------------------------------------------------ 
// Define the fit function
//------------------------------------------------------------------------------------ 

Double_t fitf(Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t limits[5] = { par[0], par[1], par[2], par[3], par[4] };
  Double_t offset1 = pol4(limits[0], par[5], par[6], par[7], par[8], par[9]) - pol4(limits[0], 0.0 , par[10], par[11], par[12], par[13]);
  Double_t offset2 = pol4(limits[1], offset1, par[10], par[11], par[12], par[13]) - pol3(limits[1], 0.0, par[14], par[15], par[16]);
  Double_t offset3 = pol3(limits[2], offset2, par[14], par[15], par[16]) - pol3(limits[2], 0.0, par[17], par[18], par[19]);
  Double_t offset4 = pol3(limits[3], offset3, par[17], par[18], par[19]) - pol1(limits[3], 0.0, par[20]);
  Double_t offset5 = pol1(limits[4], offset4, par[20]) - pol1(limits[4], 0.0, par[21]);

  if      (                    xx < limits[0] ) return pol4(xx, par[5] , par[6] , par[7] , par[8] , par[9] );
  else if ( limits[0] <= xx && xx < limits[1] ) return pol4(xx, offset1, par[10], par[11], par[12], par[13]);
  else if ( limits[1] <= xx && xx < limits[2] ) return pol3(xx, offset2, par[14], par[15], par[16]);
  else if ( limits[2] <= xx && xx < limits[3] ) return pol3(xx, offset3, par[17], par[18], par[19]);
  else if ( limits[3] <= xx && xx < limits[4] ) return pol1(xx, offset4, par[20]);
  else if ( limits[4] <= xx                   ) return pol1(xx, offset5, par[21]);
  else return 0.;
}

//------------------------------------------------------------------------------------ 
// Perform the fit
//------------------------------------------------------------------------------------ 

void fit(){

  //------------------------------------------------------------------------------------ 
  // Fill boundaries
  //------------------------------------------------------------------------------------ 

  Double_t boundaries[3][6][5] = { 
    { {28., 60., 190., 435., 1330.}, {23., 65., 190., 850. , 1640.}, {23., 68., 190., 880. , 1500.}, 
      {23., 68., 190., 410., 1320.}, {27., 68., 190., 1050., 1550.}, {23., 60., 190., 850. , 970. } },
    { {23., 68., 190., 515., 1240.}, {23., 68., 190., 1000., 1380.}, {22., 68., 190., 955. , 1550.}, 
      {23., 68., 190., 425., 1250.}, {24., 68., 220., 975. , 1450.}, {30., 70., 190., 975. , 1300.} },
    { {23., 68., 190., 515., 1200.}, {20., 68., 215., 1000., 1350.}, {33., 68., 190., 1025., 1450.},
      {23., 68., 190., 515., 1150.}, {23., 68., 190., 970. , 1300.}, {19., 68., 190., 905. , 1450.} }
  };

  //------------------------------------------------------------------------------------ 
  // Open the file 
  //------------------------------------------------------------------------------------ 
  
  TFile * file = new TFile("HcalNoise_QCD1800_MC.root");

  //------------------------------------------------------------------------------------ 
  // Style the canvas
  //------------------------------------------------------------------------------------ 
  
  TCanvas * canv = new TCanvas();
  gStyle -> SetOptFit(0);
  gStyle -> SetOptStat(0);

  //------------------------------------------------------------------------------------ 
  // Declare the fit function.  Set its parameter names and hold the boundaries constant
  //------------------------------------------------------------------------------------ 

  TF1 * func = new TF1("func", fitf, fit_xmin, fit_xmax, 21);
  
  func -> SetParName(0 , "Limit1");
  func -> SetParName(1 , "Limit2");
  func -> SetParName(2 , "Limit3");
  func -> SetParName(3 , "Limit4");
  func -> SetParName(4 , "Limit5");
  
  func -> SetParName(5 , "a41_0");
  func -> SetParName(6 , "a41_1");
  func -> SetParName(7 , "a41_2");
  func -> SetParName(8 , "a41_3");
  func -> SetParName(9 , "a41_4");
  
  func -> SetParName(10, "a42_1");
  func -> SetParName(11, "a42_2");
  func -> SetParName(12, "a42_3");
  func -> SetParName(13, "a42_4");
  
  func -> SetParName(14, "a31_1");
  func -> SetParName(15, "a31_2");
  func -> SetParName(16, "a31_3");
  
  func -> SetParName(17, "a32_1");
  func -> SetParName(18, "a32_2");
  func -> SetParName(19, "a32_3");
  
  func -> SetParName(20, "a11_1");
  
  func -> SetParLimits(0, 3, 2);
  func -> SetParLimits(1, 3, 2);
  func -> SetParLimits(2, 3, 2);
  func -> SetParLimits(3, 3, 2);
  func -> SetParLimits(4, 3, 2);

  //------------------------------------------------------------------------------------ 
  // Style the line
  //------------------------------------------------------------------------------------ 

  func -> SetLineColor(kRed);

  //------------------------------------------------------------------------------------ 
  // Loop over the rings/functions and fit each one
  //------------------------------------------------------------------------------------ 
  
  char hist_name[100];
  char save_name[100];
    
  for (int function = min_function; function <= max_function; ++function){
    for (int ring = min_ring; ring <= max_ring; ++ring){
      
      //------------------------------------------------------------------------------------ 
      // Do string manipulation
      //------------------------------------------------------------------------------------ 
      
      sprintf(hist_name, "a%d_ring%d"    , function, ring);
      sprintf(save_name, "a%d_ring%d.png", function, ring);
      
      //------------------------------------------------------------------------------------ 
      // Get the 2D histogram and rebin it if necessary
      //------------------------------------------------------------------------------------ 
      
      TH2D* hist  = (TH2D*) file  -> Get(hist_name);
      TH2D* hist1 = (TH2D*) hist  -> RebinX(rebinx);
      TH2D* hist2 = (TH2D*) hist1 -> RebinY(rebiny);
      
      //------------------------------------------------------------------------------------ 
      // Get the TProfile.  Options are described here:
      // http://root.cern.ch/root/html/TProfile.html#TProfile:BuildOptions
      //------------------------------------------------------------------------------------ 
      
      TProfile * prof = hist2 -> ProfileX("_pfx", 1, -1, "i");
      
      //------------------------------------------------------------------------------------ 
      // Set the range of the TProfile
      //------------------------------------------------------------------------------------ 
      
      prof -> SetMarkerStyle(20);
      prof -> SetMarkerColor(kBlue);
      prof -> Draw("P");
      prof -> GetXaxis() -> SetRangeUser(plot_xmin, plot_xmax);
      
      //------------------------------------------------------------------------------------ 
      // Set the break points of the fit function
      //------------------------------------------------------------------------------------ 
      
      func -> SetParameter(0, boundaries[function - 1][ring][0]);
      func -> SetParameter(1, boundaries[function - 1][ring][1]);
      func -> SetParameter(2, boundaries[function - 1][ring][2]);
      func -> SetParameter(3, boundaries[function - 1][ring][3]);
      func -> SetParameter(4, boundaries[function - 1][ring][4]);
      
      //------------------------------------------------------------------------------------ 
      // Fit the profile
      //------------------------------------------------------------------------------------ 
      
      prof -> Fit("func");
      
      //------------------------------------------------------------------------------------ 
      // Make the piece-wise fit functions and draw them (if requested)
      //------------------------------------------------------------------------------------ 
      
      if ( draw_pieces ){
	TF1 * func1 = new TF1("func1", "pol4", fit_xmin, func -> GetParameter(0));
	func1 -> SetParameter(0, func -> GetParameter(5));
	func1 -> SetParameter(1, func -> GetParameter(6));
	func1 -> SetParameter(2, func -> GetParameter(7));
	func1 -> SetParameter(3, func -> GetParameter(8));
	func1 -> SetParameter(4, func -> GetParameter(9));
	func1 -> SetLineColor(kRed);
	func1 -> SetLineStyle(kDashed);
	func1 -> Draw("SAME");
	
	TF1 * func2 = new TF1("func2", "pol4", func -> GetParameter(0), func -> GetParameter(1));
	func2 -> SetParameter(0, getOffset1(func));
	func2 -> SetParameter(1, func -> GetParameter(10));
	func2 -> SetParameter(2, func -> GetParameter(11));
	func2 -> SetParameter(3, func -> GetParameter(12));
	func2 -> SetParameter(4, func -> GetParameter(13));
	func2 -> SetLineColor(kYellow);
	func2 -> SetLineStyle(kDashed);
	func2 -> Draw("SAME");
	
	TF1 * func3 = new TF1("func3", "pol3", func -> GetParameter(1), func -> GetParameter(2));
	func3 -> SetParameter(0, getOffset2(func));
	func3 -> SetParameter(1, func -> GetParameter(14));
	func3 -> SetParameter(2, func -> GetParameter(15));
	func3 -> SetParameter(3, func -> GetParameter(16));
	func3 -> SetLineColor(kCyan);
	func3 -> SetLineStyle(kDashed);
	func3 -> Draw("SAME");
	
	TF1 * func4 = new TF1("func4", "pol3", func -> GetParameter(2), func -> GetParameter(3));
	func4 -> SetParameter(0, getOffset3(func));
	func4 -> SetParameter(1, func -> GetParameter(17));
	func4 -> SetParameter(2, func -> GetParameter(18));
	func4 -> SetParameter(3, func -> GetParameter(19));
	func4 -> SetLineColor(kGreen);
	func4 -> SetLineStyle(kDashed);
	func4 -> Draw("SAME");
	
	TF1 * func5 = new TF1("func5", "pol1", func -> GetParameter(3), func -> GetParameter(4));
	func5 -> SetParameter(0, getOffset4(func));
	func5 -> SetParameter(1, func -> GetParameter(20));
	func5 -> SetLineColor(kPink);
	func5 -> SetLineStyle(kDashed);
	func5 -> Draw("SAME");
	
	TF1 * func6 = new TF1("func6", "pol1", func -> GetParameter(4), fit_xmax);
	func6 -> SetParameter(0, getOffset5(func));
	func6 -> SetParameter(1, func -> GetParameter(21));
	func6 -> SetLineColor(kYellow);
	func6 -> SetLineStyle(kDashed);
	func6 -> Draw("SAME");
      }
	
      //------------------------------------------------------------------------------------ 
      // Save the canvas
      //------------------------------------------------------------------------------------ 
      
      canv -> SaveAs(save_name);

    }
  }
}
