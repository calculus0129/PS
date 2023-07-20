#Makefile For Windows
DEPS=b14940_easy-least-length.cc
OBJ=$(patsubst %.cc,%.o,$(DEPS))
pgm:	$(OBJ)
	g++ -Wall -lm -O2 -static -std=gnu++17 -o $@ $^ -DONLINE_JUDGE -DBOJ
	del $^