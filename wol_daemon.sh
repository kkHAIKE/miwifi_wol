#!/bin/ash

while [ 1 ] ; do
	out=`ps | grep "wol" | grep -v "grep\|daemon"`
	if [ -z "$out" ]; then
		 ./wol
	fi
	./sleep 20
done
