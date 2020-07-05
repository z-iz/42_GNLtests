#!/bin/bash

gcc ../get_next_line.c ../get_next_line_utils.c -I.. main.c -D BUFFER_SIZE=10 -D ERRMAN -g -Wall -Wextra -Werror -o test.out && ./test.out

gcc ../get_next_line.c ../get_next_line_utils.c -I.. main.c -D BUFFER_SIZE=10 -D MALLOC -g -Wall -Wextra -Werror -o test.out && ./test.out

gcc ../get_next_line.c ../get_next_line_utils.c -I.. main.c -D BUFFER_SIZE=0 -D BUF0 -g -Wall -Wextra -Werror -o test.out && ./test.out

gcc ../get_next_line.c ../get_next_line_utils.c -I.. main.c -D BUFFER_SIZE=1 -D BUF1 -g -Wall -Wextra -Werror -o test.out && ./test.out

gcc ../get_next_line.c ../get_next_line_utils.c -I.. main.c -D BUFFER_SIZE=4 -D BUF4 -g -Wall -Wextra -Werror -o test.out && ./test.out

gcc ../get_next_line.c ../get_next_line_utils.c -I.. main.c -D BUFFER_SIZE=9999 -D BUF9999 -g -Wall -Wextra -Werror -o test.out && ./test.out

gcc ../get_next_line.c ../get_next_line_utils.c -I.. main.c -D BUFFER_SIZE=10000000 -D BUF10000000 -g -Wall -Wextra -Werror -o test.out && ./test.out

gcc ../get_next_line.c ../get_next_line_utils.c -I.. main.c -D BUFFER_SIZE=43 -D BUFLINE -g -Wall -Wextra -Werror -o test.out && ./test.out

gcc ../get_next_line.c ../get_next_line_utils.c -I.. main.c -D BUFFER_SIZE=32 -D HUGE_FILE -g -Wall -Wextra -Werror -o test.out && ./test.out
if diff test_warandpeace test_warandpeace_out >> diff.txt ; then
	echo -e "\033[1;32mOK\033[0m" && echo "No Diff" >> diff.txt
else
	echo -e "\033[1;31mKO\033[0m"
fi
