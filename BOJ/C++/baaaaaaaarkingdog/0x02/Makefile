#Makefile For Windows
#Refer to https://regexone.com/lesson/wildcards_dot
BOJ_NUM=1267# e.g. 1000
DEPS=$(wildcard b$(BOJ_NUM)[^0-9]*.cc) # .cc
OBJ=$(patsubst %.cc,%.o,$(DEPS))
pgm:	$(OBJ)
	g++ -Wall -lm -O2 -static -std=gnu++17 -o $@ $^ -DONLINE_JUDGE -DBOJ
	del $^
#.phony: $(wildcard 0-9+)
#$(wildcard 0-9+):
#	BOJ_NUM=$@
#	make pgm