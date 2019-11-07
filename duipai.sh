#!/bin/bash
while true ;do
	#printf "233"
	./Tree_Produce > data.in
	./NOIP2014D1T2 <data.in > out1.out
	./test <data.in > out2.out
	if diff out1.out out2.out ; then
		printf "AC\n"
	else
		printf "WA\n"
		exit 0
	fi
	#sleep 0.2s
done
