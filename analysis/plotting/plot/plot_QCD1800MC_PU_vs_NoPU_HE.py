import ROOT as r

r.gStyle.SetOptStat(0)

file = r.TFile("data/output/QCD1800MC_PU_vs_NoPU/output.root")

no_pu_plot = file.Get("no_pu_maxChargeHE")
pu_50_plot = file.Get("pu_50_maxChargeHE")

c = r.TCanvas()

no_pu_plot.GetXaxis().SetTitle("Time sample");
no_pu_plot.GetYaxis().SetTitle("Charge [fC]");

no_pu_plot.GetYaxis().SetTitleOffset(1.5)
no_pu_plot.GetXaxis().SetTitleOffset(1.5)

maximum = max(no_pu_plot.GetMaximum(), pu_50_plot.GetMaximum())

no_pu_plot.SetMaximum(maximum*1.1)
pu_50_plot.SetMaximum(maximum*1.1)
no_pu_plot.SetMinimum(-1.0)
pu_50_plot.SetMinimum(-1.0)


no_pu_plot.SetFillColor(r.kBlue)
pu_50_plot.SetFillColor(r.kRed)
no_pu_plot.SetLineColor(r.kBlue)
pu_50_plot.SetLineColor(r.kRed)
no_pu_plot.SetFillStyle(3004)
pu_50_plot.SetFillStyle(3005)

legend = r.TLegend()

legend = r.TLegend(0.6,0.7,0.9,0.9)
legend.SetFillColor(r.kWhite)
legend.SetBorderSize(1)
legend.SetShadowColor(10)
legend.SetMargin(0.2)
legend.SetTextFont(132)
legend.AddEntry(no_pu_plot,"QCD Pt 1800: PU 0", "f");
legend.AddEntry(pu_50_plot,"QCD Pt 1800: PU 50, BX 25", "f");

latex = r.TLatex()
latex.SetTextAlign(12)
latex.SetTextFont(132)
latex.SetTextSize(0.065)
latex.SetTextSize(0.041)
latex.SetNDC()

no_pu_plot.Draw()
pu_50_plot.Draw("SAME")
legend.Draw("SAME")
latex.DrawLatex(0.6,0.65,"HE(29,15,1)")
latex.DrawLatex(0.6,0.60,"Run 1, Event 4463, LS 47")

c.SaveAs("png/pulse_QCD1800MC_PU_vs_NoPU_HE.png")
