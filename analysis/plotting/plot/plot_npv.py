import ROOT as r

file = r.TFile("HcalNoise_QCD1800_MC.root")

profile = file.Get("npv")

canvas = r.TCanvas()

canvas.SetLogy()
profile.Draw()
profile.GetXaxis().SetTitle("NumberOfGoodPrimaryVertices")
profile.GetYaxis().SetTitle("Entries")
profile.Draw()

canvas.SaveAs("npv_QCD1800.png")
