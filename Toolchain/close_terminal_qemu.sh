#!/bin/bash



PROCESS=Terminal;
number=$(ps aux | grep -v grep | grep -ci $PROCESS);

if [ $number -gt 0 ];
    then
        echo $PROCESS Running;
        echo lh1992524 | sudo -S  pkill -f $PROCESS 
fi

PROCESS=qemu-system-i386;
number=$(ps aux | grep -v grep | grep -ci $PROCESS);

if [ $number -gt 0 ];
    then
        echo $PROCESS Running;
        echo lh1992524 | sudo -S  pkill -f $PROCESS 
fi;
