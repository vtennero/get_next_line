#!/bin/bash

# 1/ CHOOSE YOUR BUFFSIZE
# 2/ CHOOSE YOUR TEST FILE

sed -i -e 's/BUFF_SIZE .*/BUFF_SIZE '$1'/g' get_next_line.h
make re

./test_gnl tests/$2 | cat -e
rm -rf get_next_line.h.gch
rm -rf get_next_line.h-e
