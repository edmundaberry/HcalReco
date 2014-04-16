import ROOT as r
import sys

file = r.TFile("HcalNoise_QCD1800_MC.root")
rings = range(0,6)
functions = range(1,2)


def fit_function_0(x,par):
    xx = x[0]
    pol1_offset = par[0];
    pol1_slope  = par[1];
    exp_arg1    = par[2];
    exp_arg2    = par[3];
    pol = pol1_offset + pol1_slope * xx;
    expo = r.TMath.Exp(exp_arg1 + exp_arg2 * xx)
    retval = pol + expo
    return retval

def fit_function_1(x,par):
    xx = x[0]
    range1_min = 0.
    range1_max = 28.
    range2_max = 60.
    range3_max = 190.
    range4_max = 410.

    range_1_function = (par[0] + 
                        (xx - range1_max)^1  * par[1] + 
                        (xx - range1_max)^2  * par[2] + 
                        (xx - range1_max)^3  * par[3] + 
                        (xx - range1_max)^4  * par[4])

    
    range_2_function = (par[0] + 
                        (xx - range1_min)^1  * par[1] + 
                        (xx - range1_min)^2  * par[2] + 
                        (xx - range1_min)^3  * par[3] + 
                        (xx - range1_min)^4  * par[4])

    

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

fit_xmin = 0
fit_xmax = 500.
plot_xmin = 0
plot_xmax =1500.

for function in functions:
    for ring in rings:
        plot_name = "a" +str(function) + "_ring" + str(ring)
        fit_name  = "fit_" + plot_name
        plot = file.Get(plot_name)
        profile = plot.ProfileX("_pfx", 1, -1, "i")
        canvas = r.TCanvas()
        
        profile.Draw()
        profile.GetXaxis().SetTitle("TS4 [fC], for ring = " + d_ring_name[ring]);
        profile.GetYaxis().SetTitle(d_function_name[function]);
        profile.Draw()
        
        if function == 0:
            fit = r.TF1 (fit_name, fit_function_0, fit_xmin, fit_xmax, 4)
            fit.SetParameter(0,0.02756);
            fit.SetParLimits(0,0.01, 0.05);
            fit.SetParameter(1,8.553e-6);
            fit.SetParLimits(1,-1.0,1.0);
            fit.SetParameter(2,-2.125);
            fit.SetParLimits(2,-4.0, 0.0);
            fit.SetParameter(3,-0.08089);
            fit.SetParLimits(3,-0.2, 0.0);
            
            profile.Fit(fit_name,"MR")
            profile.Draw()
            fit.SetRange(plot_xmin,plot_xmax)
            fit.Draw("SAME")
            
        canvas.SaveAs("a"+str(function)+"_ring" + str(ring) + ".png")

