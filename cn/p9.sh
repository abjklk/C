#!/bin/bash
echo "The Interfaces that are UP are:"
ip a|grep "UP"|cut -d ":" -f 2
