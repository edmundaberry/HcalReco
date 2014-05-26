import ROOT as r

def main():

  #------------------------------------------------------------
  # Style canvas
  #------------------------------------------------------------

  canv = r.TCanvas();
  canv.cd();
  canv.SetLogy();
  canv.SetRightMargin(0.3);

  #------------------------------------------------------------
  # Set important variables
  #------------------------------------------------------------

  rebin = 1;
  xmin = -200.;
  xmax =  200.;

  sample_names = [ "80to120", "1800" ]

  function_name = { 
    0: "a_1",
    1: "a1" ,
    2: "a2" ,
    3: "a3" 
  }

  ring_name = { 
    0: "HB",
    1: "HE 17:20" ,
    2: "HE 21:23" ,
    3: "HE 24:25" ,
    4: "HE 26:27" ,
    5: "HE 28:28" 
  }

  xtitle = {
    0: "TS3 true - TS3 predicted",
    1: "TS5 true - TS5 predicted",
    2: "TS6 true - TS6 predicted",
    3: "TS7 true - TS7 predicted"
  }

  file_names = [
      "test80to120.root",
      "test1800.root"
  ]

  hist_name_templates = [
    "TS4_vs_crosscheck_nonrel_aFUNCTION_ringRING"         ,
    "TS4_vs_crosscheck_nonrel_over50_aFUNCTION_ringRING"  ,
    "TS4_vs_crosscheck_nonrel_under50_aFUNCTION_ringRING" ,
    "TS4_vs_crosscheck_nonrel_over500_aFUNCTION_ringRING" ,
    "TS4_vs_crosscheck_nonrel_under500_aFUNCTION_ringRING",
  ]

  save_name_templates = [
      "png/crosscheck_1D_sampleSAMPLE_aFUNCTION_ringRING.png",
      "png/crosscheck_1D_sampleSAMPLE_aFUNCTION_over50_ringRING.png",
      "png/crosscheck_1D_sampleSAMPLE_aFUNCTION_under50_ringRING.png",
      "png/crosscheck_1D_sampleSAMPLE_aFUNCTION_over500_ringRING.png",
      "png/crosscheck_1D_sampleSAMPLE_aFUNCTION_under500_ringRING.png"
  ] 

  #------------------------------------------------------------
  # Loop through templates
  #------------------------------------------------------------

  for sample in range (0, 2):
      file_name   = file_names  [sample]
      sample_name = sample_names[sample]

      #------------------------------------------------------------
      # Open file
      #------------------------------------------------------------
      
      file = r.TFile(file_name)

      #------------------------------------------------------------
      # Loop through templates (i.e. plots)
      #------------------------------------------------------------
      
      for template in range (0, 5):
    
          hist_name_template = hist_name_templates[template]
          save_name_template = save_name_templates[template]

          #------------------------------------------------------------
          # Loop through functions
          #------------------------------------------------------------

          for function in range(0, 4):
        
              #------------------------------------------------------------
              # Loop through rings
              #------------------------------------------------------------
        
              for ring in range(0, 6):
        
                  #------------------------------------------------------------
                  # Get TH1Fs
                  #------------------------------------------------------------
            
                  hist_name = hist_name_template  .replace("RING", str(ring)).replace("FUNCTION", str(function))
                  
                  plot = file.Get(hist_name);
                  proj = plot.ProjectionY();
                  proj.Rebin(rebin);
                  proj.GetXaxis().SetRangeUser(xmin, xmax);

                  #------------------------------------------------------------
                  # Style TH1Fs
                  #------------------------------------------------------------
            
                  proj.SetName("Function " + function_name[function] + ", " + ring_name[ring] )
                  proj.SetLineColor(r.kBlue);
                  proj.SetFillColor(r.kBlue);
                  proj.SetFillStyle(3004);
              
                  proj.GetXaxis().SetTitle(xtitle[function])
                  proj.GetYaxis().SetTitle("Entries");
                  
                  proj.Draw();
    
                  #------------------------------------------------------------
                  # Update the pad
                  #------------------------------------------------------------
    
                  r.gPad.Update();
    
                  #------------------------------------------------------------
                  # Draw a line
                  #------------------------------------------------------------
    
                  line = r.TLine(0., 10.**(canv.GetUymin()), 0., 10.**(canv.GetUymax()))
                  line.SetLineColor(r.kRed)
                  line.SetLineStyle(r.kDashed)
                  line.SetLineWidth(3)
                  line.Draw();
                  
                  #------------------------------------------------------------
                  # Fetch TPaveStats
                  #------------------------------------------------------------
            
                  stats = proj.FindObject("stats");
                  
                  #------------------------------------------------------------
                  # Style and draw TPaveStats
                  #------------------------------------------------------------
        
                  # stats.SetShadowColor(0);
                  # stats.SetTextColor(r.kBlue);
                  # stats.SetX1NDC(0.75);
                  # stats.SetX2NDC(0.95);
                  # stats.SetY1NDC(0.17);
                  # stats.SetY2NDC(0.55);
                  # stats.Draw();
                  
                  stats.SetShadowColor(0);
                  stats.SetTextColor(r.kBlue);
                  stats.SetX1NDC(0.75);
                  stats.SetX2NDC(0.95);
                  stats.SetY1NDC(0.57);
                  stats.SetY2NDC(0.95);
                  stats.Draw();
                  
                  #------------------------------------------------------------
                  # Save canvas
                  #------------------------------------------------------------
            
                  save_name = save_name_template.replace("RING", str(ring)).replace("SAMPLE", sample_name).replace("FUNCTION",str(function))
            
                  canv.SaveAs(save_name);

if __name__ == "__main__":
    main()
