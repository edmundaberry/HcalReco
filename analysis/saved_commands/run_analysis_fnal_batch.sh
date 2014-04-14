python scripts/launch_analysis.py \
-x $PWD/main \
-w $PWD/data/output/MinBiasMCAnalysis/ \
-n 100 \
-i $PWD/config/input_lists/MinBiasMC_onFNALEOS/inputListAll.txt \
-t $PWD/config/tree_lists/tree_list.txt \
-o HcalNoise_MinBias_MC \
-q 1nh \
-e /eos/uscms/store/user/eberry/MinBiasMCAnalysis/ \
-s yes
