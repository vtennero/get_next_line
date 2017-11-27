#!/bin/bash

# 1/ CHOOSE YOUR BUFFSIZE
# 2/ CHOOSE YOUR TEST FILE

sed -i -e 's/BUFF_SIZE .*/BUFF_SIZE '$1'/g' get_next_line.h
make re
#cat -e $2
#echo "\n--------"
./test_gnl tests/$2 | cat -e
rm get_next_line.h.gch
rm get_next_line.h-e
