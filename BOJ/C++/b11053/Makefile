DEPS=b11053.cc# .cc
OBJ=$(patsubst %.cc,%.o,$(DEPS))
pgm:	$(OBJ)
	g++ -Wall -lm -O2 -static -std=gnu++14 -o $@ $^ -DONLINE_JUDGE -DBOJ
	del $^