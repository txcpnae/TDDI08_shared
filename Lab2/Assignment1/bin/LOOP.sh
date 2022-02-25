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
#     rm stats.txt
# done


# txtfile="Sweep_Cache_Sizes.txt"
# echo "Writing to file:"$txtfile
#
# > $txtfile #clears textfile
# for IS in {8..14}
# do
#     for DS in {8..14}
#     do
#         mpsim.x -w -c1 -F0,12 --ds $DS --dt 1 --is $IS --it 1
#         echo "Inst Cache Size = "$IS >> $txtfile
#         echo "Data Cache Size = "$DS >> $txtfile
#         source SEARCH_STATS.sh >> $txtfile
#         rm stats.txt
#     done
# done
# txtfile="Sweep_Associativy.txt"
# echo "Writing to file:"$txtfile
#
# > $txtfile #clears textfile
# for DT in {1,2,4,8}
# do
#     for IT in {1,2,4,8}
#     do
#         mpsim.x -w -c1 -F0,12 --ds 10 --dt $DT --is 10 --it $IT
#         echo "Data Cache associativy = "$DT >> $txtfile
#         echo "Inst Cache associativy = "$IT >> $txtfile
#         source SEARCH_STATS.sh >> $txtfile
#         rm stats.txt
#     done
# done


# txtfile="Test.txt"
# echo "Writing to file:"$txtfile
#
# for DS in {9..11}
# do
#     for IS in {9..10}
#     do
#         mpsim.x -w -c1 -F0,11 --ds $DS --dt 2 --is $IS --it 1
#         echo "Data Cache size = "$DS >> $txtfile
#         echo "Inst Cache size = "$IS >> $txtfile
#         source SEARCH_STATS.sh >> $txtfile
#         rm stats.txt
#     done
# done
txtfile="TestF10.txt"
echo "Writing to file:"$txtfile

for DS in {9..13}
do
    for IS in {9..13}
    do
        mpsim.x -w -c1 -F0,10 --ds $DS --dt 2 --is $IS --it 1
        echo "Data Cache size = "$DS >> $txtfile
        echo "Inst Cache size = "$IS >> $txtfile
        source SEARCH_STATS.sh >> $txtfile
        rm stats.txt
    done
done

# txtfile="TestF11.txt"
# echo "Writing to file:"$txtfile
#
# for DS in {9..13}
# do
#     for IS in {9..13}
#     do
#         mpsim.x -w -c1 -F0,11 --ds $DS --dt 2 --is $IS --it 1
#         echo "Data Cache size = "$DS >> $txtfile
#         echo "Inst Cache size = "$IS >> $txtfile
#         source SEARCH_STATS.sh >> $txtfile
#         rm stats.txt
#     done
# done
#
# txtfile="TestF12.txt"
# echo "Writing to file:"$txtfile
#
# for DS in {9..13}
# do
#     for IS in {9..13}
#     do
#         mpsim.x -w -c1 -F0,12 --ds $DS --dt 2 --is $IS --it 1
#         echo "Data Cache size = "$DS >> $txtfile
#         echo "Inst Cache size = "$IS >> $txtfile
#         source SEARCH_STATS.sh >> $txtfile
#         rm stats.txt
#     done
# done
