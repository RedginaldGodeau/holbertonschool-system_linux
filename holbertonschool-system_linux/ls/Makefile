.PHONY: ci
ci:
	betty *.c
build: hls
	gcc -Wall -Werror -Wextra -pedantic *.c -o hls
