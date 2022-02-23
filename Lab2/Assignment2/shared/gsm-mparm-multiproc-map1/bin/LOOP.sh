#! /bin/bash
#mpsim.x -w -c1 -F0,1 --ds 12 --dt 1 --is 13 --it 2
# init
source /courses/TDTS07/sw/mparm/go_mparm_bash.sh

# txtfile="Sweep_Freq.txt"
# echo "Writing to file:"$txtfile
#
# > $txtfile #clears textfile
# for F in {5..15}
# do
#     mpsim.x -w -c1 -F0,$F --ds 12 --dt 1 --is 13 --it 2
#     echo "Frequency divider = "$F >> $txtfile
#     source SEARCH_STATS.sh >> $txtfile
#
# done


# txtfile="Sweep_Data_Cache_Size.txt"
# echo "Writing to file:"$txtfile
#
# #> $txtfile #clears textfile
# for DS in {8..14}
# do
#     mpsim.x -w -c1 -F0,12 --ds $DS --dt 1 --is 14 --it 1
#     echo "Data Cache Size = "$DS >> $txtfile
#     source SEARCH_STATS.sh >> $txtfile
#
# done

# txtfile="Sweep_Associativy.txt"
# echo "Writing to file:"$txtfile
#
# > $txtfile #clears textfile
# for DT in {1..8}
# do
#     for IT in {1..8}
#     do
#         mpsim.x -w -c1 -F0,12 --ds 10 --dt $DT --is 10 --it $IT
#         echo "Data Cache associativy = "$DT >> $txtfile
#         echo "Inst Cache associativy = "$IT >> $txtfile
#         source SEARCH_STATS.sh >> $txtfile
#
#     done
# done


txtfile="Test.txt"
echo "Writing to file:"$txtfile
#> $txtfile #clears textfile


for FC in {2..8}
do
  for ((FCC=1;$FCC<$FC;FCC++))
  do
      echo $FCC
      mpsim.x -w -c3 -F0,$FC -F1,$FCC -F2,$FCC
      echo "Frequency = "$FC >> $txtfile
      source SEARCH_STATS.sh >> $txtfile
  done
done
