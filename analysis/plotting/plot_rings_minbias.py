import ROOT as r
import sys

file = r.TFile("HcalNoise_MinBias_MC.root")
rings = range(0,6)
functions = range(1,4)

d_ring_name = {
    0: "HB",
    1: "HE, 17:20",
    2: "HE, 21:23",
    3: "HE, 24:25",
    4: "HE, 26:27",
    5: "HE, 28:28"
}

d_function_name = {
    1: "TS3/TS4",
    2: "TS2/TS4",
    3: "TS1/TS4"
}

for function in functions:
    for ring in rings:
        plot = file.Get("a" +str(function) + "_ring" + str(ring))
        profile = plot.ProfileX()
        canvas = r.TCanvas()
        
        profile.Draw()
        profile.GetXaxis().SetTitle("TS4 [fC], for ring = " + d_ring_name[ring]);
        profile.GetYaxis().SetTitle(d_function_name[function]);
        profile.Draw()
        
        canvas.SaveAs("a"+str(function)+"_ring" + str(ring) + ".png")

