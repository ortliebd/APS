#!/bin/bash

for i in {0..10}
do
    echo $i" iteracao" >> binary_search.txt
    INPUT=$i"merge_sort.txt"
    for j in {1..5}
    do
	KEY=$(($RANDOM%2000))
	COND=$((RANDOM%2))
	if [ "$COND" -eq "0" ]; then
	    KEY=`expr $KEY \* -1`
	fi
	./binary_search < $INPUT $KEY >> binary_search.txt
    done
    echo >> binary_search.txt
done
