#------------------------------------------------------------------------------------
# Imports
#------------------------------------------------------------------------------------

import ROOT as r
import array

def getProfile ( hist, min_combined_bin_content ):

    nbinsx = hist.GetXaxis().GetNbins()
    nbinsy = hist.GetXaxis().GetNbins()

    combined_bins = []
    combined_integral = 0.0
    
    combined_bins.append ( hist.GetXaxis().GetXmax() )

    for bin in reversed(range(1, nbinsx + 1)):
        integral  = hist.Integral(bin, bin, 1, nbinsy)
        low_edge  = hist.GetXaxis().GetBinLowEdge(bin)
        high_edge = hist.GetXaxis().GetBinUpEdge (bin)
    
        combined_integral += integral
    
        if combined_integral > min_combined_bin_content or bin < 10: 
            combined_bins.append ( low_edge )
            combined_integral = 0.

    combined_bins.reverse()

    a_bins = array.array("d", combined_bins)
    n_bins = len(combined_bins) - 1

    hist_name_x = hist.GetName() + "_RebinX"

    prof = hist.ProfileX("_pfx", 1, -1, "i");
    prof = prof.Rebin(n_bins, hist_name_x, a_bins)

    return prof

def draw_lines ( canv, func ):
    
    lines = []
    canv.Update()
    for iline in range(0,5):
        xmin = func.GetParameter(iline)
        xmax = func.GetParameter(iline)
        ymin = canv.GetUymin()
        ymax = canv.GetUymax()

        if canv.GetLogy() == 1:
            ymin = 10**(ymin)
            ymax = 10**(ymax)

        line = r.TLine(xmin, ymin, xmax, ymax)
        
        line.SetLineColor(r.kRed)
        line.SetLineStyle(r.kDashed)
        line.Draw("SAME")
        lines.append ( line ) 
    return lines

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
    exp_const   = par[4];
    pol = pol1_offset + pol1_slope * xx;
    expo = exp_const * r.TMath.Exp(exp_arg1 + exp_arg2 * xx)
    retval = pol + expo
    return retval


def fitf0_v2 ( x,par):
    xx = x[0];
    expo1 = par[0] * r.TMath.Exp(par[1] + par[2] * xx);
    pol1 = par[3] + par[4] * xx;
    if (xx < par[6]):
        return expo1 + pol1;

    else:
        offset_expo = par[0] * r.TMath.Exp(par[1] + par[2] * par[6]);
        offset_pol1 = par[3] + par[4] * par[6];
        offset = offset_expo + offset_pol1;
        retval = offset + par[5] * ( xx - par[6]);
        return retval;

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
# Make a function
#------------------------------------------------------------------------------------

def make_function_poly ( func_name, xmin, xmax, function, ring, boundaries, min_val ):

    func = r.TF1(func_name, fitf, xmin, xmax, 22);
    func.SetLineColor(r.kRed);
    
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


    func.SetParameter(0, boundaries[function - 1][ring][0]);
    func.SetParameter(1, boundaries[function - 1][ring][1]);
    func.SetParameter(2, boundaries[function - 1][ring][2]);
    func.SetParameter(3, boundaries[function - 1][ring][3]);
    func.SetParameter(4, boundaries[function - 1][ring][4]);
    
    func.SetParLimits(0, 3, 2);
    func.SetParLimits(1, 3, 2);
    func.SetParLimits(2, 3, 2);
    func.SetParLimits(3, 3, 2);
    func.SetParLimits(4, 3, 2);
    
    func.SetParameter(5, min_val)
    func.SetParLimits(5, min_val / 2.0, min_val * 2.0)
    func.SetParLimits(20,-1e-8, 0.0)
    func.SetParLimits(21,-1e-8, 0.0)
    
    return func

def make_function_expo (func_name, xmin, xmax ):
    
    func = r.TF1 (func_name, fitf0, fit_xmin, fit_xmax_a0, 5)
    func.SetLineColor(r.kRed);
    func.SetParameter(0,0.02756);
    func.SetParLimits(0,0.001, 0.05);
    func.SetParameter(1,8.553e-6);
    func.SetParLimits(1,-1.0,1.0);
    func.SetParameter(2,-2.125);
    func.SetParLimits(2,-4.0, 0.0);
    func.SetParameter(3,-0.08089);
    func.SetParLimits(3,-0.2, 0.0);
    func.SetParameter(4,0.2);
    func.SetParLimits(4,0.0, 1.0);

    return func
    
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
    max_ring       = 5;
    # fit_xmin       = 5.;
    # fit_xmax       = 3000.;

    fit_xmin       = 5.;
    fit_xmax       = 3000.;

    fit_xmax_a0    = 350.;
    plot_xmin      = 0;
    plot_xmax      = 3000.;
    draw_pieces    = False;
    tex_preamble   = False;
    do_print       = False;
    file_name      = "HcalNoise_QCD1800_MC.root";
    data_card_path = "data/data_cards/data_card_2014-04-17.txt";

    max_parameters = [  9,
                        13,
                        16,
                        19,
                        20,
                        21 ]

    d_ring_name = {
        0: "HB",
        1: "HE, 17:20",
        2: "HE, 21:23",
        3: "HE, 24:25",
        4: "HE, 26:27",
        5: "HE, 28:28"
        }
    

    d_ring_funcname = {
        0: "HB",
        1: "HE1720",
        2: "HE2123",
        3: "HE2425",
        4: "HE2627",
        5: "HE2828"
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
    #canv.SetLogx();
    #canv.SetLogy();
    r.gStyle.SetOptFit(0);
    r.gStyle.SetOptStat(0);
    
    #------------------------------------------------------------------------------------ 
    # Loop over the rings/functions and fit each one
    #------------------------------------------------------------------------------------ 
    
    hist_name = ""

    out_file = r.TFile ("profiles.root","RECREATE")
    
    for function in range(min_function, max_function + 1):
        
        for ring in range(min_ring, max_ring + 1):

            print "Fitting function:", function, "ring:", ring
            
            #------------------------------------------------------------------------------------ 
            # Do string manipulation
            #------------------------------------------------------------------------------------ 
      
            func_name = "func" + str(function) + str(ring)
            hist_name = "a%d" % function + "_ring%d"     % ring
            save_name = "png/a%d" % function + "_ring%d.png" % ring
            tex_name  = "tex/a%d" % function + "_ring%d.tex" % ring
            
            #------------------------------------------------------------------------------------ 
            # Get the 2D histogram and rebin it if necessary
            #------------------------------------------------------------------------------------ 
            
            hist  = file.Get(hist_name);
            
            #------------------------------------------------------------------------------------ 
            # Get the TProfile.  Options are described here:
            # http:#root.cern.ch/root/html/TProfile.html#TProfile:BuildOptions
            #------------------------------------------------------------------------------------ 
            
            prof = getProfile ( hist, 5. )
            out_file.cd()
            prof.Write()

            #------------------------------------------------------------------------------------ 
            # Get some values from the TProfile
            #------------------------------------------------------------------------------------ 
            
            min_bin = prof.FindBin(fit_xmin)
            min_val = prof.GetBinContent(min_bin)
            
            #------------------------------------------------------------------------------------ 
            # Declare the fit function.  Set its parameter names and hold the boundaries constant
            #------------------------------------------------------------------------------------ 
            
            if function > 0:
                func = make_function_poly (func_name, fit_xmin, fit_xmax, function, ring, a123_boundaries, min_val)
            else:
                func = make_function_expo (func_name, fit_xmin, fit_xmax)

            #------------------------------------------------------------------------------------ 
            # Style the TProfile
            #------------------------------------------------------------------------------------ 

            prof.SetMarkerStyle(20);
            prof.SetMarkerColor(r.kBlue);
            
            #------------------------------------------------------------------------------------ 
            # Set the range of the TProfile
            #------------------------------------------------------------------------------------ 
            
            prof.Draw("P");
            prof.GetXaxis().SetRangeUser(plot_xmin, plot_xmax);
            prof.GetXaxis().SetTitle("TS4 [fC], for " + d_ring_name[ring]);
            prof.GetYaxis().SetTitle(d_function_name[function]);
            
            #------------------------------------------------------------------------------------ 
            # Set the break points of the fit function for a1, a2, a3 (depends on the ring)
            #------------------------------------------------------------------------------------  
            
            if function  > 0:
                
                max_bin   = prof.GetMaximumBin()
                max_value = prof.GetBinContent(max_bin)

                sub_functions = []
                last_sub_function_parameters = []
                last_sub_function_par_errors = []
                
                for region in range(0,6):
                    
                    print "\tFitting range =", region + 1, "/", 6

                    if region == 3: continue
                    if region == 4: continue

                    sub_function_name = func_name + "_sub" + str(region)
                    region_xmin = fit_xmin
                    if region == 5:
                        region_xmax = fit_xmax
                    else:
                        region_xmax = a123_boundaries[function - 1][ring][region]
                        
                    sub_function = make_function_poly (sub_function_name, region_xmin, region_xmax, function, ring, a123_boundaries, min_val)
                    
                    for i_parameter in range(0,len(last_sub_function_parameters)):
                        parameter_number = i_parameter
                        
                        mean  = last_sub_function_parameters[i_parameter]
                        error = last_sub_function_par_errors[i_parameter]
                        leniancy = 5.0
                        fix = True

                        sub_function.SetParameter(parameter_number, mean)
                        sub_function.SetParLimits(parameter_number, mean - (leniancy * error), mean + (leniancy * error) )
                        
                        if fix:
                            sub_function.SetParLimits(parameter_number, 3, 2)
                        
                    if region == 5:
                        prof.Fit(sub_function_name,"MRQ")
                    else:
                        prof.Fit(sub_function_name,"MRQ")


                    # if region == 5 and sub_function.GetChisquare > 100.:
                    #     print "refitting..."
                    #     sub_function.SetParameter(21, 0.0)
                    #     sub_function.SetParLimits(21, 3, 2)
                    #     prof.Fit(sub_function_name,"MR")
                    # 
                    # 
                    # if region == 5 and sub_function.GetChisquare > 100.:
                    #     print "refitting..."
                    #     sub_function.SetParameter(21, 0.0)
                    #     sub_function.SetParLimits(21, 3, 2)
                    #     prof.Fit(sub_function_name,"MR")

                    last_sub_function_parameters = []
                    last_sub_function_par_errors = []

                    for parameter_number in range(0, max_parameters[region] + 1):
                        mean  = sub_function.GetParameter(parameter_number)
                        error = sub_function.GetParError (parameter_number)
                        last_sub_function_parameters.append(mean)
                        last_sub_function_par_errors.append(error)

                    sub_functions.append(sub_function)

                    canv.Clear()
                    prof.Draw()
                    sub_function.Draw("SAME")

                    lines = draw_lines ( canv, sub_function )
                    
                    tmp_save_name = save_name.replace(".png", "_sub" + str(region) + ".png")
                    canv.SaveAs(tmp_save_name)
                

                #------------------------------------------------------------------------------------ 
                # Fit the profile
                #------------------------------------------------------------------------------------ 
                    
                last_function = sub_functions[-1]
                last_function.SetRange(plot_xmin, plot_xmax)
                last_function.SetLineColor(r.kRed)

                print "chi^2 =", last_function.GetChisquare()
                print "ndof  =", last_function.GetNDF()
                print "ratio =", last_function.GetChisquare() / last_function.GetNDF()
                
                canv.Clear()
                prof.Draw()
                lines = draw_lines ( canv, last_function )
                last_function.Draw("SAME")
            
            #------------------------------------------------------------------------------------ 
            # Save the canvas
            #------------------------------------------------------------------------------------ 
            
            canv.SaveAs(save_name);


if __name__ == "__main__":
    main()
    
