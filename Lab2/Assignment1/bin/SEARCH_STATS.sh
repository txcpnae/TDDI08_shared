#! /bin/bash

VAR="$(grep 'Total simulated master system cycles: ' stats.txt)"
TIME=${VAR#*(}
TIME=${TIME%*)}

#echo "Check timing withing 20 ms"
#echo "20000000 ns"
echo "Execution time: $TIME"
#echo ""
#echo "Energy estimation"
grep -m 1 'Total:' stats.txt
echo ""
