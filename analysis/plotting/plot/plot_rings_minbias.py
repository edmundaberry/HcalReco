import ROOT as r
import sys

file = r.TFile("HcalNoise_MinBias_MC.root")
rings = range(0,6)
functions = range(0,4)

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

rebinx = 5;
rebiny = 1;

for function in functions:
    for ring in rings:

        plot = file.Get("a" +str(function) + "_ring" + str(ring))
        plot1 = plot .RebinX(rebinx);
        plot2 = plot1.RebinY(rebiny);
        profile = plot2.ProfileX("_pfx", 1, -1, "i");
        profile.SetMarkerStyle(20);
        profile.SetMarkerColor(r.kBlue);
        profile.Draw("P");

        canvas = r.TCanvas()
        
        profile.Draw()
        profile.GetXaxis().SetTitle("TS4 [fC], for " + d_ring_name[ring]);
        profile.GetYaxis().SetTitle(d_function_name[function]);
        profile.Draw()
        
        canvas.SaveAs("png/a"+str(function)+"_ring" + str(ring) + "_MinBias.png")

