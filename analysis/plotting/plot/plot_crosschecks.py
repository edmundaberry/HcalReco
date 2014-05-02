import ROOT as r

file = r.TFile("data/output/QCD1800MC_PU_vs_NoPU_validate/output.root");

functions = [ "a1", "a2", "a3", "a0" ]
detectors = ["HB", "HE"]

for detector in detectors:
    for function in functions:
        canv = r.TCanvas()
        canv.SetLogy()
        hist = file.Get("crosscheck_" + function + "_" + detector)
        
        hist.GetYaxis().SetTitle("Entries");
        if function == "a0": 
            hist.GetXaxis().SetTitle("TS3 - a0(TS4) #times TS4 (" + detector + ")")
        elif function == "a1":
            hist.GetXaxis().SetTitle("TS5 - a1(TS4) #times TS4 (" + detector + ")")
        elif function == "a2":
            hist.GetXaxis().SetTitle("TS6 - a2(TS4) #times TS4 (" + detector + ")")
        elif function == "a3":
            hist.GetXaxis().SetTitle("TS7 - a3(TS4) #times TS4 (" + detector + ")")
        
        hist.Draw();
        canv.SaveAs("png/crosscheck_" + function + "_" + detector + ".png")

                        
    
