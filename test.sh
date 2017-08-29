#!/bin/bash

OK="\e[32mOK\e[0m"
ERROR="\e[31mERROR\e[0m"
OKS=0

for ((i = 0; i < 960; i++)); do
	echo -n "$i -> "
	POSITION=$(./frcc $i)
	echo -n "$POSITION "
	if [ "$(./frcc $POSITION)" == "$i" ]; then 
		echo -e "$OK"
		((OKS++))
	else
		echo -e "$ERROR"
	fi
done

if [[ $OKS == 960 ]]; then
	echo -e "All $OK"
else
	echo -e "$ERROR: There where some errors"
fi
