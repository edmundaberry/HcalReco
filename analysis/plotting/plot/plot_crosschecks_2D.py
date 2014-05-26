import ROOT as r

# file = r.TFile("data/output/QCD1800MC_PU_vs_NoPU_validate/output.root");
file = r.TFile("test1800.root")

functions = [ "a1", "a2", "a3", "a0" ]
rings = [ "0", "1", "2", "3", "4", "5" ]

for function in functions:
    for ring in rings:
        canv = r.TCanvas()
        canv.SetGridx()
        canv.SetGridy()
        hist = file.Get("TS4_vs_crosscheck_"+function+"_ring" + ring)
        
        if function == "a0": hist.GetYaxis().SetTitle("(TS3 [true] - TS3 [pred.]) / TS3 [true]");
        if function == "a1": hist.GetYaxis().SetTitle("(TS5 [true] - TS5 [pred.]) / TS5 [true]");
        if function == "a2": hist.GetYaxis().SetTitle("(TS6 [true] - TS6 [pred.]) / TS6 [true]");
        if function == "a3": hist.GetYaxis().SetTitle("(TS7 [true] - TS7 [pred.]) / TS7 [true]");
        hist.GetXaxis().SetTitle("TS4 [true] [fC]")
        
        hist.Draw("COLZ");
        canv.SaveAs("png/crosscheck_" + function + "_" + ring + ".png")


for function in functions:
    for ring in rings:
        canv = r.TCanvas()
        canv.SetGridx()
        canv.SetGridy()
        hist = file.Get("TS4_vs_crosscheck_over500_"+function+"_ring" + ring)
        
        if function == "a0": hist.GetYaxis().SetTitle("(TS3 [true] - TS3 [pred.]) / TS3 [true]");
        if function == "a1": hist.GetYaxis().SetTitle("(TS5 [true] - TS5 [pred.]) / TS5 [true]");
        if function == "a2": hist.GetYaxis().SetTitle("(TS6 [true] - TS6 [pred.]) / TS6 [true]");
        if function == "a3": hist.GetYaxis().SetTitle("(TS7 [true] - TS7 [pred.]) / TS7 [true]");
        hist.GetXaxis().SetTitle("TS4 [true] [fC]")
        
        hist.Draw("COLZ");
        canv.SaveAs("png/crosscheck_over500_" + function + "_" + ring + ".png")

                        
  
for function in functions:
    for ring in rings:
        canv = r.TCanvas()
        canv.SetGridx()
        canv.SetGridy()
        hist = file.Get("TS4_vs_crosscheck_over50_"+function+"_ring" + ring)
        
        if function == "a0": hist.GetYaxis().SetTitle("(TS3 [true] - TS3 [pred.]) / TS3 [true]");
        if function == "a1": hist.GetYaxis().SetTitle("(TS5 [true] - TS5 [pred.]) / TS5 [true]");
        if function == "a2": hist.GetYaxis().SetTitle("(TS6 [true] - TS6 [pred.]) / TS6 [true]");
        if function == "a3": hist.GetYaxis().SetTitle("(TS7 [true] - TS7 [pred.]) / TS7 [true]");
        hist.GetXaxis().SetTitle("TS4 [true] [fC]")
        
        hist.Draw("COLZ");
        canv.SaveAs("png/crosscheck_over50_" + function + "_" + ring + ".png")

                        
    
                        
    
