#Makefile For Windows
#Refer to https://regexone.com/lesson/wildcards_dot
BOJ_NUM=10171# e.g. 1000
DEPS=$(wildcard b$(BOJ_NUM)[^0-9]*.cc) # .cc
OBJ=$(patsubst %.cc,%.o,$(DEPS))
pgm:	$(OBJ)
	g++ -Wall -lm -O2 -static -std=gnu++17 -o $@ $^ -DONLINE_JUDGE -DBOJ
	del $^