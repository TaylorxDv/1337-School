#!/bin/sh

first_base=`echo $FT_NBR1 | sed 'y/'\''\\\"?!/01234/'`
second_base=`echo $FT_NBR2 | sed 'y/mrdoc/01234/'`
base5=`echo "ibase=5;$first_base+$second_base" | bc` 

echo "obase=13;$base5" | bc | sed 'y/0123456789ABC/gtaio luSnemf/'
