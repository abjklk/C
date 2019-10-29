#!/bin/bash
for i in {1..20}
do
fping 192.168.1.$i  >> res1.txt &
done
cat res1.txt|grep "unreachable"|cut -d " " -f 1
