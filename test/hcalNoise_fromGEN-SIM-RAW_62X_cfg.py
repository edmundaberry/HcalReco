
# Auto generated configuration file
# using: 
# Revision: 1.20 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: RECO --filein dcache:/pnfs/cms/WAX/11/store/mc/Fall13dr/QCD_Pt-1800_Tune4C_13TeV_pythia8/GEN-SIM-RAW/castor_tsg_PU40bx25_POSTLS162_V2-v2/00000/000F9230-CAB0-E311-B972-02163E00EB68.root -s RAW2DIGI,L1Reco,RECO --conditions auto:mc -n 3 --no_exec --fileout MinBias_RECO.root
import FWCore.ParameterSet.Config as cms

process = cms.Process('RECO')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.RawToDigi_cff')
process.load('Configuration.StandardSequences.L1Reco_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(3)
)

# Input source
process.source = cms.Source("PoolSource",
    secondaryFileNames = cms.untracked.vstring(),
    fileNames = cms.untracked.vstring(
        #FILENAMES
    )
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.20 $'),
    annotation = cms.untracked.string('RECO nevts:3'),
    name = cms.untracked.string('Applications')
)

# Output definition

# Additional output definition

process.HBHENoiseFilterResultProducer = cms.EDProducer(
   'HBHENoiseFilterResultProducer',
   noiselabel = cms.InputTag('hcalnoise'),
   minRatio = cms.double(-999),
   maxRatio = cms.double(999),
   minHPDHits = cms.int32(17),
   minRBXHits = cms.int32(999),
   minHPDNoOtherHits = cms.int32(10),
   minZeros = cms.int32(10),
   minHighEHitTime = cms.double(-9999.0),
   maxHighEHitTime = cms.double(9999.0),
   maxRBXEMF = cms.double(-999.0),
   minNumIsolatedNoiseChannels = cms.int32(10),
   minIsolatedNoiseSumE = cms.double(50.0),
   minIsolatedNoiseSumEt = cms.double(25.0),
   useTS4TS5 = cms.bool(True),
   IgnoreTS4TS5ifJetInLowBVRegion = cms.bool(True),
   jetlabel = cms.InputTag('ak5PFJets'),
   maxjetindex = cms.int32(0),
   maxNHF = cms.double(0.9)
   )
process.TFileService = cms.Service("TFileService",
   fileName = cms.string("OUTPUTFILENAME.root")
   )
process.ExportTree = cms.EDAnalyzer("HcalNoiseAnalyzer",
   HBHERecHitCollection = cms.untracked.string('hbhereco')
   )

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'GLOBALTAG', '')

# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.L1Reco_step = cms.Path(process.L1Reco)
process.reconstruction_step = cms.Path(process.reconstruction)
process.endjob_step = cms.EndPath(process.endOfProcess * process.HBHENoiseFilterResultProducer * process.ExportTree)

# Schedule definition
process.schedule = cms.Schedule(process.raw2digi_step,process.L1Reco_step,process.reconstruction_step,process.endjob_step)

