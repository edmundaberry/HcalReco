import ROOT as r

file = r.TFile("data/output/QCD1800MC_PU_vs_NoPU_validate/output.root");
file = r.TFile("test.root")

rings = [ "0", "1", "2", "3", "4", "5" ]

for delta in range (3, 6):
    for ring in rings:
        canv = r.TCanvas()
        hist = file.Get("TS4_vs_delta"+str(delta)+"_over100_ring"+str(ring))
        
        y_axis = "(TS" + str(delta) + " [with pileup] - TS" + str(delta) + " [no pileup]) / TS4 [no pileup]"
        x_axis = "TS4 [no pileup] [fC]"

        hist.GetXaxis().SetTitle(x_axis)
        hist.GetYaxis().SetTitle(y_axis)

        hist.GetXaxis().SetTitle("TS"+str(delta)+" [no pileup] [fC]")
        
        hist.Draw("COLZ");
        canv.SaveAs("png/pulseshape_" + str(delta) + "_" + ring + ".png")
