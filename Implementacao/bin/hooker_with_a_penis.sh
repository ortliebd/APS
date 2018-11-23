#!/bin/bash

EXEC=$1

for i in {0..10}
do
    ./$EXEC < $i.txt >> $EXEC.txt
done

    
