#!/bin/bash
while true ;do
	#printf "233"
	./Tree_Produce > data.in
	./517-16-C <data.in > out2.out
	./test <data.in > out1.out
	if diff out1.out out2.out ; then
		printf "AC\n"
	else
		printf "WA\n"
		exit 0
	fi
	#sleep 0.2s
done
