#!/bin/bash
NBR_COUNT=100
##
NBR="14 39 36 58 62 34 38 20 91 82 89 64 41 15 13 47 49 67 7 65 18 83 5 6 40 63 27 76 28 51 71 24 87 33 45 37 92 93 86 61 46 55 90 59 9 72 66 100 53 80 23 74 50 21 84 52 48 97 43 8 42 16 12 70 31 4 98 57 96 26 35 69 99 19 54 79 25 3 56 68 30 44 95 77 85 1 22 81 11 10 94 73 75 78 88 29 17 60 32 2"
RES=OK
while [ "$(./push_swap $NBR | ./checker_linux $NBR)" = "OK" ]
do
	NBR=$(seq 1 $NBR_COUNT | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev)
	./push_swap $NBR | wc -l
	./push_swap $NBR | ./checker_linux $NBR
done

CMD=$( ./push_swap $NBR)
echo "NBR [$NBR]"
#echo "Operations: $CMD"
