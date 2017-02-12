#!/bin/bash

num=0
total=100
while [ $num -lt $total ]
do
	sleep 1
	/home/luna/workspace/mhyeagle/algorithm/sort/a.out
	num=`expr $num + 1`
done

