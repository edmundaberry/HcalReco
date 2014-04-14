import ROOT as r

file = r.TFile("/Users/eberry/Code/HcalReco/analysis/data/output/output.root")

plot = file.Get("a1_ring0")

profile = plot.ProfileX()

canvas = r.TCanvas()

profile.Draw()

canvas.SaveAs("plot.png")
