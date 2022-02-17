#! /bin/bash
#mpsim.x -w -c1 -F0,1 --ds 12 --dt 1 --is 13 --it 2


for F in {8..10}
do
    mpsim.x -w -c1 -F0,$F --ds 12 --dt 1 --is 13 --it 2
    echo "Frequency divider = "$F >> Sweep_Freq.txt
    source SEARCH_STATS.sh >> Sweep_Freq.txt

done
