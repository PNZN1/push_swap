#!/bin/sh

PUSH_SWAP=./push_swap
CHECKER=./checker_Mac

if [ "$#" -lt 3 ] || [ "$#" -gt 4 ]
then
	printf "\nusage: test.sh arg1 arg2 arg3 [--pargs]\n"
	printf "       arg1  - start number (random value from .. ).\n"
	printf "       arg2  - finish number ( .. random value to).\n"
	printf "       arg3  - how many times run a test.\n"
	printf "       -pnum - print the random numbers\n\n"

	exit
fi

NC='\033[0m'
BLUE='\033[0;34m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
GRAY='\033[0;37m'

if [ "$4" = "-pnum" ]
then
	from=$1
	to=$2
	count=$3
else
	from=$1
	to=$2
	count=$3
fi

for ((i = 0; i < $count; i++))
	do
	ARG=`ruby -e "puts ($from..$to).to_a.shuffle.join(' ')"`
	moves=$($PUSH_SWAP $ARG | wc -l)
	checkerm=$($PUSH_SWAP $ARG | $CHECKER $ARG)
	if [ "$4" = "-pnum" ]
	then
		echo "${GRAY}TEST${NC} ${i}: ${GREEN}${checkerm}${NC}${CYAN}${moves}${NC}  moves    RANDOM NUM: ${GRAY}$ARG${NC}"
	else
		echo "TEST ${i}: ${GREEN}${checkerm}${NC}${CYAN}${moves}${NC}  moves"
	fi
done

