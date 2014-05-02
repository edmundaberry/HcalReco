import ROOT as r

r.gStyle.SetOptStat(0)

file = r.TFile("data/output/QCD1800MC_PU_vs_NoPU_validate/output.root");

hist1 = file.Get("delta_corrected")
hist2 = file.Get("delta_uncorrected")

canv = r.TCanvas()
# canv.SetLogy()

maximum = 1.05 * max(hist1.GetMaximum(), hist2.GetMaximum())

hist1.SetMaximum(maximum)
hist2.SetMaximum(maximum)

print "corrected mean   =", hist1.GetMean()
print "corrected RMS    =", hist1.GetRMS()
print "uncorrected mean =", hist2.GetMean()
print "uncorrected RMS  =", hist2.GetRMS()


hist1.SetFillColor(r.kBlue)
hist2.SetFillColor(r.kRed)
hist1.SetLineColor(r.kBlue)
hist2.SetLineColor(r.kRed)
hist1.SetFillStyle(3004)
hist2.SetFillStyle(3005)


legend = r.TLegend(0.6,0.7,0.9,0.9)
legend.SetFillColor(r.kWhite)
legend.SetBorderSize(1)
legend.SetShadowColor(10)
legend.SetMargin(0.2)
legend.SetTextFont(132)
legend.AddEntry(hist1,"TS45 with pileup corrected", "f");
legend.AddEntry(hist2,"TS45 without pileup corrected", "f");


hist1.GetXaxis().SetTitle("TS45 with pileup - TS45 without pileup")
hist1.Draw()
hist2.Draw("SAME")
legend.Draw("SAME")

canv.SaveAs("png/correction_comparison_linear.png")


# float delta_uncorrected = pu_50_TS45       - no_pu_TS45;
# float delta_corrected   = pu_50_TS45_prime - no_pu_TS45;
# float correction        = pu_50_TS45_prime - pu_50_TS45;
	
