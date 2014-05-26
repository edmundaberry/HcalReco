import ROOT as r

scale = True

r.gStyle.SetOptStat(0)

qcd_lo_file = r.TFile ("HcalNoise_QCD80to120_MC.root")
qcd_hi_file = r.TFile ("HcalNoise_QCD1800_MC.root")

hist_name = "ieta"

qcd_lo_hist = qcd_lo_file.Get(hist_name)
qcd_hi_hist = qcd_hi_file.Get(hist_name)

if scale:
    qcd_lo_hist.Scale(1.0 / qcd_lo_hist.Integral())
    qcd_hi_hist.Scale(1.0 / qcd_hi_hist.Integral())

qcd_lo_hist.SetFillColor(r.kRed)
qcd_hi_hist.SetFillColor(r.kBlue)
qcd_lo_hist.SetLineColor(r.kRed)
qcd_hi_hist.SetLineColor(r.kBlue)
qcd_lo_hist.SetFillStyle(3005)
qcd_hi_hist.SetFillStyle(3004)

qcd_lo_hist.GetYaxis().SetTitleOffset(1.5)
qcd_lo_hist.GetXaxis().SetTitleOffset(1.5)
qcd_lo_hist.GetYaxis().SetTitle("Entries [A.U.]")
qcd_lo_hist.GetXaxis().SetTitle("ieta")

canvas = r.TCanvas()

qcd_lo_hist.Draw()
qcd_hi_hist.Draw("SAME")

legend = r.TLegend(0.6,0.7,0.9,0.9)
legend.SetFillColor(r.kWhite)
legend.SetBorderSize(1)
legend.SetShadowColor(10)
legend.SetMargin(0.2)
legend.SetTextFont(132)
legend.AddEntry(qcd_lo_hist,"QCD Pt 80-120: PU 0", "f")
legend.AddEntry(qcd_hi_hist,"QCD Pt 1800: PU 0", "f")

legend.Draw("SAME")

if scale:
    canvas.SaveAs("ieta_comparison_scaled.png")
else:
    canvas.SaveAs("ieta_comparison_unscaled.png")

