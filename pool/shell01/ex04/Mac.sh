#!/bin/sh

ifconfig | grep "ether " | cut -f2 -d$'\t' | sed 's/ether //g'
