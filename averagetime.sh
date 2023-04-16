#!/bin/bash

#chmod +x averagetime.sh


read -p 'Enter a dictionary file name and a grid file name: ' DictionaryFile GridFile

RUNNING_TIME1=`./a.out $DictionaryFile $GridFile| tail -1`
RUNNING_TIME2=`./a.out $DictionaryFile $GridFile| tail -1`
RUNNING_TIME3=`./a.out $DictionaryFile $GridFile| tail -1`
RUNNING_TIME4=`./a.out $DictionaryFile $GridFile| tail -1`
RUNNING_TIME5=`./a.out $DictionaryFile $GridFile| tail -1`

AVERAGE=$(((RUNNING_TIME1 + RUNNING_TIME2 + RUNNING_TIME3 + RUNNING_TIME4 + RUNNING_TIME5) / 5))

echo $AVERAGE


#seconds or milliseconds as unit
