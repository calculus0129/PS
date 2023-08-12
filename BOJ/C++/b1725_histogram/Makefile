DEPS = b1725_histogram.cc
OBJ = $(patsubst %.cc, %.o, $(DEPS))

pgm:	$(OBJ)
	g++ -Wall -O2 -o $@ $^ -std=gnu++17
	del $^
