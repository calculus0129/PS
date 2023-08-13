DEPS=b1395.cc
OBJ=$(patsubst %.cc,%.o,$(DEPS))
pgm:	$(OBJ)
	g++ -Wall -O2 -o $@ $^ -std=gnu++17 -DONLINE_JUDGE -DBOJ
.PHONY:	clean
clean:
	rm *.o
