#------------------------------------------------------------------------------------
# Imports
#------------------------------------------------------------------------------------

import ROOT as r

#------------------------------------------------------------------------------------
# Read data values
#------------------------------------------------------------------------------------

def read_data_values ( data_card_path ):
    d_function_ring_region_parameters = {}
    data_card = open ( data_card_path )
    for line in data_card:
        if line.strip() == "": continue
        fields = line.split()
        function   = int(fields[0])
        ring       = int(fields[1])
        region     = str(fields[2])
        parameters = fields[3:]
        
        if function not in d_function_ring_region_parameters.keys():
            d_function_ring_region_parameters[function] = {}
        if ring not in d_function_ring_region_parameters[function].keys():
            d_function_ring_region_parameters[function][ring] = {}
        d_function_ring_region_parameters[function][ring][region] = parameters

    return d_function_ring_region_parameters
    

#------------------------------------------------------------------------------------
# Define polynomials
#------------------------------------------------------------------------------------

def pol1(x, par0, par1):
    retval  = 0.;
    retval += par0;
    retval += ( par1 * x );
    return retval;

def pol3(x, par0, par1, par2, par3 ):
    retval  = 0.;
    retval += par0;
    retval += ( par1 * x );
    retval += ( par2 * x * x );
    retval += ( par3 * x * x * x );
    return retval;

def pol4(x, par0, par1, par2, par3, par4 ):
    retval  = 0.;
    retval += par0;
    retval += ( par1 * x );
    retval += ( par2 * x * x );
    retval += ( par3 * x * x * x );
    retval += ( par4 * x * x * x * x );
    return retval;

#------------------------------------------------------------------------------------
# Define "offsets": y-intercepts of polynomials that ensure that the polynomials
# all fit together at the boundaries
#------------------------------------------------------------------------------------ 

def getOffset1 ( tmp_func ):
    limits0 = tmp_func.GetParameter(0);
    par5    = tmp_func.GetParameter(5);
    par6    = tmp_func.GetParameter(6);
    par7    = tmp_func.GetParameter(7);
    par8    = tmp_func.GetParameter(8);
    par9    = tmp_func.GetParameter(9);
    par10   = tmp_func.GetParameter(10);
    par11   = tmp_func.GetParameter(11);
    par12   = tmp_func.GetParameter(12);
    par13   = tmp_func.GetParameter(13);
    offset1 = pol4(limits0, par5, par6, par7, par8, par9) - pol4(limits0, 0.0, par10, par11, par12, par13);
    return offset1;

def getOffset2 ( tmp_func ):
    limits1 = tmp_func.GetParameter(1);
    par10   = tmp_func.GetParameter(10);
    par11   = tmp_func.GetParameter(11);
    par12   = tmp_func.GetParameter(12);
    par13   = tmp_func.GetParameter(13);
    par14   = tmp_func.GetParameter(14);
    par15   = tmp_func.GetParameter(15);
    par16   = tmp_func.GetParameter(16);
    offset1 = getOffset1(tmp_func);
    offset2 = pol4(limits1, offset1, par10, par11, par12, par13) - pol3(limits1, 0.0, par14, par15, par16);
    return offset2;

def getOffset3 ( tmp_func ):
    limits2 = tmp_func.GetParameter(2);
    par14   = tmp_func.GetParameter(14);
    par15   = tmp_func.GetParameter(15);
    par16   = tmp_func.GetParameter(16);
    par17   = tmp_func.GetParameter(17);
    par18   = tmp_func.GetParameter(18);
    par19   = tmp_func.GetParameter(19);
    offset2 = getOffset2(tmp_func);
    offset3 = pol3(limits2, offset2, par14, par15, par16) - pol3(limits2, 0.0, par17, par18, par19);
    return offset3;

def getOffset4 ( tmp_func ):
    limits3 = tmp_func.GetParameter(3);
    par17   = tmp_func.GetParameter(17);
    par18   = tmp_func.GetParameter(18);
    par19   = tmp_func.GetParameter(19);
    par20   = tmp_func.GetParameter(20);
    offset3 = getOffset3(tmp_func);
    offset4 = pol3(limits3, offset3, par17, par18, par19) - pol1(limits3, 0.0, par20);
    return offset4;


def getOffset5 ( tmp_func ):
    limits4 = tmp_func.GetParameter(4);
    par20   = tmp_func.GetParameter(20);
    par21   = tmp_func.GetParameter(21);
    offset4 = getOffset4(tmp_func);
    offset5 = pol1(limits4, offset4, par20) - pol1(limits4, 0.0, par21);
    return offset5;

#------------------------------------------------------------------------------------ 
# Define the fit function for a0
#------------------------------------------------------------------------------------ 

def fitf0(x,par):
    xx = x[0]
    pol1_offset = par[0];
    pol1_slope  = par[1];
    exp_arg1    = par[2];
    exp_arg2    = par[3];
    pol = pol1_offset + pol1_slope * xx;
    expo = r.TMath.Exp(exp_arg1 + exp_arg2 * xx)
    retval = pol + expo
    return retval

#------------------------------------------------------------------------------------ 
# Define the fit function for a1, a2, a3
#------------------------------------------------------------------------------------ 

def fitf(x, par):
    xx = x[0];
    limits = [ par[0], par[1], par[2], par[3], par[4] ]
    offset1 = pol4(limits[0], par[5], par[6], par[7], par[8], par[9]) - pol4(limits[0], 0.0 , par[10], par[11], par[12], par[13]);
    offset2 = pol4(limits[1], offset1, par[10], par[11], par[12], par[13]) - pol3(limits[1], 0.0, par[14], par[15], par[16]);
    offset3 = pol3(limits[2], offset2, par[14], par[15], par[16]) - pol3(limits[2], 0.0, par[17], par[18], par[19]);
    offset4 = pol3(limits[3], offset3, par[17], par[18], par[19]) - pol1(limits[3], 0.0, par[20]);
    offset5 = pol1(limits[4], offset4, par[20]) - pol1(limits[4], 0.0, par[21]);
    
    if   (                     xx < limits[0] ): return pol4(xx, par[5] , par[6] , par[7] , par[8] , par[9] );
    elif ( limits[0] <= xx and xx < limits[1] ): return pol4(xx, offset1, par[10], par[11], par[12], par[13]);
    elif ( limits[1] <= xx and xx < limits[2] ): return pol3(xx, offset2, par[14], par[15], par[16]);
    elif ( limits[2] <= xx and xx < limits[3] ): return pol3(xx, offset3, par[17], par[18], par[19]);
    elif ( limits[3] <= xx and xx < limits[4] ): return pol1(xx, offset4, par[20]);
    elif ( limits[4] <= xx                    ): return pol1(xx, offset5, par[21]);
    else: return 0.;
    
#------------------------------------------------------------------------------------ 
# Perform the fit
#------------------------------------------------------------------------------------ 

def main():
    
    #------------------------------------------------------------------------------------
    # Set important variables for the user to tinker with
    #------------------------------------------------------------------------------------
    
    min_function   = 1;
    max_function   = 3;
    min_ring       = 0;
    max_ring       = 1;
    rebinx         = 5;
    rebiny         = 1;
    fit_xmin       = 0.;
    fit_xmax       = 1350.;
    plot_xmin      = 0.;
    plot_xmax      = 1350.;
    draw_pieces    = True;
    tex_preamble   = False;
    file_name      = "HcalNoise_QCD1800_MC.root";
    data_card_path = "data/data_cards/data_card_2014-04-17.txt";
    
    d_ring_name = {
        0: "HB",
        1: "HE, 17:20",
        2: "HE, 21:23",
        3: "HE, 24:25",
        4: "HE, 26:27",
        5: "HE, 28:28"
        }
    
    d_function_name = {
        0: "TS3/TS4",
        1: "TS5/TS4",
        2: "TS6/TS4",
        3: "TS7/TS4"
        }

    #------------------------------------------------------------------------------------ 
    # Get data values
    #------------------------------------------------------------------------------------ 

    d_function_ring_region_parameters = read_data_values ( data_card_path ) 
 
    #------------------------------------------------------------------------------------ 
    # Open the file 
    #------------------------------------------------------------------------------------ 
  
    file = r.TFile(file_name);

    #------------------------------------------------------------------------------------ 
    # Fill boundaries
    #------------------------------------------------------------------------------------ 
    
    a123_boundaries = [
        [ [28., 60., 190., 435., 1330.], [23., 65., 190., 850. , 1640.], [23., 68., 190., 880. , 1500.], 
          [23., 68., 190., 410., 1320.], [27., 68., 190., 1050., 1550.], [23., 60., 190., 850. , 970. ] ],
        [ [23., 68., 190., 515., 1240.], [23., 68., 190., 1000., 1380.], [22., 68., 190., 955. , 1550.], 
          [23., 68., 190., 425., 1250.], [24., 68., 220., 975. , 1450.], [30., 70., 190., 975. , 1300.] ],
        [ [23., 68., 190., 515., 1200.], [20., 68., 215., 1000., 1350.], [33., 68., 190., 1025., 1450.],
          [23., 68., 190., 515., 1150.], [23., 68., 190., 970. , 1300.], [19., 68., 190., 905. , 1450.] ]
        ]
    
    a123_values = [
        
        ]
    
    #------------------------------------------------------------------------------------ 
    # Style the canvas
    #------------------------------------------------------------------------------------ 
    
    canv = r.TCanvas();
    r.gStyle.SetOptFit(0);
    r.gStyle.SetOptStat(0);
    
    #------------------------------------------------------------------------------------ 
    # Loop over the rings/functions and fit each one
    #------------------------------------------------------------------------------------ 
    
    hist_name = ""

    for function in range(min_function, max_function + 1):

        #------------------------------------------------------------------------------------ 
        # Declare the fit function.  Set its parameter names and hold the boundaries constant
        #------------------------------------------------------------------------------------ 

        if function > 0:
            
            if function == 3 and ring == 1:
                fit_xmax = 1350.
                plot_xmax = 1350.
            func = r.TF1("func", fitf, fit_xmin, fit_xmax, 22);
    
            func.SetParName(0 , "Limit1");
            func.SetParName(1 , "Limit2");
            func.SetParName(2 , "Limit3");
            func.SetParName(3 , "Limit4");
            func.SetParName(4 , "Limit5");
            
            func.SetParName(5 , "a41_0");
            func.SetParName(6 , "a41_1");
            func.SetParName(7 , "a41_2");
            func.SetParName(8 , "a41_3");
            func.SetParName(9 , "a41_4");
            
            func.SetParName(10, "a42_1");
            func.SetParName(11, "a42_2");
            func.SetParName(12, "a42_3");
            func.SetParName(13, "a42_4");
            
            func.SetParName(14, "a31_1");
            func.SetParName(15, "a31_2");
            func.SetParName(16, "a31_3");
            
            func.SetParName(17, "a32_1");
            func.SetParName(18, "a32_2");
            func.SetParName(19, "a32_3");
            
            func.SetParName(20, "a11_1");
            
            func.SetParName(21, "a21_1");
            
        else:
            func = r.TF1 ("func", fitf0, fit_xmin, fit_xmax, 4)
            func.SetParameter(0,0.02756);
            func.SetParLimits(0,0.01, 0.05);
            func.SetParameter(1,8.553e-6);
            func.SetParLimits(1,-1.0,1.0);
            func.SetParameter(2,-2.125);
            func.SetParLimits(2,-4.0, 0.0);
            func.SetParameter(3,-0.08089);
            func.SetParLimits(3,-0.2, 0.0);
            
        #------------------------------------------------------------------------------------ 
        # Style the line
        #------------------------------------------------------------------------------------ 

        func.SetLineColor(r.kRed);

        for ring in range(min_ring, max_ring + 1):
          
            #------------------------------------------------------------------------------------ 
            # Do string manipulation
            #------------------------------------------------------------------------------------ 
      
            hist_name = "a%d" % function + "_ring%d"     % ring
            save_name = "png/a%d" % function + "_ring%d.png" % ring
            tex_name  = "tex/a%d" % function + "_ring%d.tex" % ring
            
            #------------------------------------------------------------------------------------ 
            # Get the 2D histogram and rebin it if necessary
            #------------------------------------------------------------------------------------ 
            
            hist  = file.Get(hist_name);
            hist1 = hist .RebinX(rebinx);
            hist2 = hist1.RebinY(rebiny);
            
            #------------------------------------------------------------------------------------ 
            # Get the TProfile.  Options are described here:
            # http:#root.cern.ch/root/html/TProfile.html#TProfile:BuildOptions
            #------------------------------------------------------------------------------------ 
            
            prof = hist2.ProfileX("_pfx", 1, -1, "i");
            
            #------------------------------------------------------------------------------------ 
            # Set the range of the TProfile
            #------------------------------------------------------------------------------------ 
            
            prof.SetMarkerStyle(20);
            prof.SetMarkerColor(r.kBlue);
            prof.Draw("P");
            prof.GetXaxis().SetRangeUser(plot_xmin, plot_xmax);
            prof.GetXaxis().SetTitle("TS4 [fC], for " + d_ring_name[ring]);
            prof.GetYaxis().SetTitle(d_function_name[function]);
            
            #------------------------------------------------------------------------------------ 
            # Set the break points of the fit function for a1, a2, a3 (depends on the ring)
            #------------------------------------------------------------------------------------  
            
            if function  > 0:
                
                func.SetParameter(0, a123_boundaries[function - 1][ring][0]);
                func.SetParameter(1, a123_boundaries[function - 1][ring][1]);
                func.SetParameter(2, a123_boundaries[function - 1][ring][2]);
                func.SetParameter(3, a123_boundaries[function - 1][ring][3]);
                func.SetParameter(4, a123_boundaries[function - 1][ring][4]);
                
                func.SetParLimits(0, 3, 2);
                func.SetParLimits(1, 3, 2);
                func.SetParLimits(2, 3, 2);
                func.SetParLimits(3, 3, 2);
                func.SetParLimits(4, 3, 2);

                max_bin   = prof.GetMaximumBin()
                max_value = prof.GetBinContent(max_bin)

                if function == 3 and ring == 1:
                    func.SetParameter(5,0.321598327812)
                    func.SetParLimits(5,0.321444800797, 0.321751854827)
                    func.SetParameter(6,-0.0276337689358)
                    func.SetParLimits(6,-0.02764171405, -0.0276258238215)
                    func.SetParameter(7,0.000447197867143)
                    func.SetParLimits(7,0.000446795874674, 0.000447599859613)
                    func.SetParameter(8,4.81154319861e-05)
                    func.SetParLimits(8,4.80952185904e-05, 4.81356453819e-05)
                    func.SetParameter(9,-1.62800362277e-06)
                    func.SetParLimits(9,-1.62901765716e-06, -1.62698958837e-06)
                    func.SetParameter(10,-0.00252541689719)
                    func.SetParLimits(10,-0.00252925933634, -0.00252157445804)
                    func.SetParameter(11,2.5149592949e-05)
                    func.SetParLimits(11,2.51053396697e-05, 2.51938462283e-05)
                    func.SetParameter(12,1.69544994168e-07)
                    func.SetParLimits(12,1.68929320068e-07, 1.70160668268e-07)
                    func.SetParameter(13,-2.89409892983e-09)
                    func.SetParLimits(13,-2.90304377416e-09, -2.88515408551e-09)
                    
            #------------------------------------------------------------------------------------ 
            # Fit the profile
            #------------------------------------------------------------------------------------ 
            
            prof.Fit("func","R");
            
            #------------------------------------------------------------------------------------ 
            # Make the piece-wise fit functions for a1, a2, a3 and draw them (if requested)
            #------------------------------------------------------------------------------------ 
            
            if function > 0:

                for i in range(5, 22):
                    value = func.GetParameter(i)
                    error = func.GetParError (i)
                    if value == 0.0: continue
                    print "func.SetParameter(" + str(i) + ","  + str ( value ) + ")"
                    print "func.SetParLimits(" + str(i) + "," + str ( value - 2.0 * error ) + ", " + str(value+ 2.0 * error) + ")"
                    
                
                func1 = r.TF1("func1", "pol4", fit_xmin, func.GetParameter(0));
                func1.SetParameter(0, float(d_function_ring_region_parameters[function][ring]["0"][0]));
                func1.SetParameter(1, float(d_function_ring_region_parameters[function][ring]["0"][1]));
                func1.SetParameter(2, float(d_function_ring_region_parameters[function][ring]["0"][2]));
                func1.SetParameter(3, float(d_function_ring_region_parameters[function][ring]["0"][3]));
                func1.SetParameter(4, float(d_function_ring_region_parameters[function][ring]["0"][4]));

                func2 = r.TF1("func2", "pol4", func.GetParameter(0), func.GetParameter(1));
                func2.SetParameter(0, float(d_function_ring_region_parameters[function][ring]["1"][0]));
                func2.SetParameter(1, float(d_function_ring_region_parameters[function][ring]["1"][1]));
                func2.SetParameter(2, float(d_function_ring_region_parameters[function][ring]["1"][2]));
                func2.SetParameter(3, float(d_function_ring_region_parameters[function][ring]["1"][3]));
                func2.SetParameter(4, float(d_function_ring_region_parameters[function][ring]["1"][4]));
                
                func3 = r.TF1("func3", "pol3", func.GetParameter(1), func.GetParameter(2));
                func3.SetParameter(0, float(d_function_ring_region_parameters[function][ring]["2"][0]));
                func3.SetParameter(1, float(d_function_ring_region_parameters[function][ring]["2"][1]));
                func3.SetParameter(2, float(d_function_ring_region_parameters[function][ring]["2"][2]));
                func3.SetParameter(3, float(d_function_ring_region_parameters[function][ring]["2"][3]));
                
                func4 = r.TF1("func4", "pol3", func.GetParameter(2), func.GetParameter(3));
                func4.SetParameter(0, float(d_function_ring_region_parameters[function][ring]["3"][0]));
                func4.SetParameter(1, float(d_function_ring_region_parameters[function][ring]["3"][1]));
                func4.SetParameter(2, float(d_function_ring_region_parameters[function][ring]["3"][2]));
                func4.SetParameter(3, float(d_function_ring_region_parameters[function][ring]["3"][3]));
                
                func5 = r.TF1("func5", "pol1", func.GetParameter(3), func.GetParameter(4));
                func5.SetParameter(0, float(d_function_ring_region_parameters[function][ring]["4"][0]));
                func5.SetParameter(1, float(d_function_ring_region_parameters[function][ring]["4"][1]));
                
                func6 = r.TF1("func6", "pol1", func.GetParameter(4), fit_xmax);
                func6.SetParameter(0, float(d_function_ring_region_parameters[function][ring]["5"][0]));
                func6.SetParameter(1, float(d_function_ring_region_parameters[function][ring]["5"][1]));
            
                if draw_pieces:
                    func1.SetLineColor(r.kBlack);
                    func2.SetLineColor(r.kBlack);
                    func3.SetLineColor(r.kBlack);
                    func4.SetLineColor(r.kBlack);
                    func5.SetLineColor(r.kBlack);
                    func6.SetLineColor(r.kBlack);
                    
                    func1.SetLineStyle(r.kDashed);
                    func2.SetLineStyle(r.kDashed);
                    func3.SetLineStyle(r.kDashed);
                    func4.SetLineStyle(r.kDashed);
                    func5.SetLineStyle(r.kDashed);
                    func6.SetLineStyle(r.kDashed);
                    
                    func1.Draw("SAME");
                    func2.Draw("SAME");
                    func3.Draw("SAME");
                    func4.Draw("SAME");
                    func5.Draw("SAME");
                    func6.Draw("SAME");

            #------------------------------------------------------------------------------------ 
            # Save the canvas
            #------------------------------------------------------------------------------------ 
            
            canv.SaveAs(save_name);

if __name__ == "__main__":
    main()
    
