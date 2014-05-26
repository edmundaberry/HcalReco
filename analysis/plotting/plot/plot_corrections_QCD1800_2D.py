import ROOT as r

file = r.TFile("test1800.root")

rings = [ "0", "1", "2", "3", "4", "5" ]

for ring in rings:
    canv = r.TCanvas()
    canv.SetGridx()
    canv.SetGridy()
    hist = file.Get("TS4_vs_delta_uncorrected_ring" + ring)
    hist.GetXaxis().SetRangeUser(0, 1000)
    hist.GetYaxis().SetTitle("(TS45 [true] - TS45 [pred.]) / TS45 [true]");
    hist.GetXaxis().SetTitle("TS45 [true] [fC]")
    hist.Draw("COLZ");
    canv.Update()
    line = r.TLine(canv.GetUxmin(), 0., canv.GetUxmax(), 0.)
    line.SetLineColor(r.kRed)
    line.SetLineWidth(3)
    line.SetLineStyle(r.kDashed)
    line.Draw("SAME")
    canv.SaveAs("png/delta_uncorrected_QCD1800_ring_" + ring + ".png")

for ring in rings:
    canv = r.TCanvas()
    canv.SetGridx()
    canv.SetGridy()
    hist = file.Get("TS4_vs_delta_corrected_ring" + ring)
    hist.GetXaxis().SetRangeUser(0, 1000)
    hist.GetYaxis().SetTitle("(TS45 [true] - TS45 [pred.]) / TS45 [true]");
    hist.GetXaxis().SetTitle("TS45 [true] [fC]")
    hist.Draw("COLZ");
    canv.Update()
    line = r.TLine(canv.GetUxmin(), 0., canv.GetUxmax(), 0.)
    line.SetLineColor(r.kRed)
    line.SetLineWidth(3)
    line.SetLineStyle(r.kDashed)
    line.Draw("SAME")
    canv.SaveAs("png/delta_corrected_QCD1800_ring_" + ring + ".png")

for ring in rings:
    canv = r.TCanvas()
    canv.SetGridx()
    canv.SetGridy()
    hist = file.Get("TS4_vs_delta_uncorrected_over500_ring" + ring)
    hist.GetXaxis().SetRangeUser(0, 1000)
    hist.GetYaxis().SetTitle("(TS45 [true] - TS45 [pred.]) / TS45 [true]");
    hist.GetXaxis().SetTitle("TS45 [true] [fC]")
    hist.Draw("COLZ");
    canv.Update()
    line = r.TLine(canv.GetUxmin(), 0., canv.GetUxmax(), 0.)
    line.SetLineColor(r.kRed)
    line.SetLineWidth(3)
    line.SetLineStyle(r.kDashed)
    line.Draw("SAME")
    canv.SaveAs("png/delta_uncorrected_QCD1800_over500_ring_" + ring + ".png")

for ring in rings:
    canv = r.TCanvas()
    canv.SetGridx()
    canv.SetGridy()
    hist = file.Get("TS4_vs_delta_corrected_over500_ring" + ring)
    hist.GetXaxis().SetRangeUser(0, 1000)
    hist.GetYaxis().SetTitle("(TS45 [true] - TS45 [pred.]) / TS45 [true]");
    hist.GetXaxis().SetTitle("TS45 [true] [fC]")
    hist.Draw("COLZ");
    canv.Update()
    line = r.TLine(canv.GetUxmin(), 0., canv.GetUxmax(), 0.)
    line.SetLineColor(r.kRed)
    line.SetLineWidth(3)
    line.SetLineStyle(r.kDashed)
    line.Draw("SAME")
    canv.SaveAs("png/delta_corrected_QCD1800_over500_ring_" + ring + ".png")

