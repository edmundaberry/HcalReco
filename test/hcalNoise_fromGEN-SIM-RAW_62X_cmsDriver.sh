cmsDriver.py RECO \
--filein "dcache:/pnfs/cms/WAX/11/store/mc/Fall13dr/QCD_Pt-1800_Tune4C_13TeV_pythia8/GEN-SIM-RAW/castor_tsg_PU40bx25_POSTLS162_V2-v2/00000/000F9230-CAB0-E311-B972-02163E00EB68.root" \
-s RAW2DIGI,L1Reco,RECO \
--conditions auto:mc \
-n 3 \
--no_exec \
--fileout MinBias_RECO.root
