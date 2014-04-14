cmsDriver.py RECO \
--filein "dcache:/pnfs/cms/WAX/11/store/mc/Summer13/MinBias_TuneZ2star_13TeV-pythia6/GEN-SIM/START53_V7C-v1/10000/FEE47FCF-A5CF-E211-9663-0025904C7DF0.root" \
-s DIGI,L1,DIGI2RAW,HLT:8E33v2,RAW2DIGI,L1Reco,RECO \
--conditions auto:mc \
-n 3 \
--no_exec \
--fileout MinBias_RECO.root
