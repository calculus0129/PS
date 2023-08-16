DEPS=b1275.cc #$(wildcard b$(BOJ_NUM)[^0-9]*.cc)# .cc
OBJ=$(patsubst %.cc,%.o,$(DEPS))
pgm:	$(OBJ)
	g++ -Wall -lm -O2 -static -std=gnu++17 -o $@ $^ -DONLINE_JUDGE -DBOJ
#del $^
.PHONY:	clean
clean:
	del $(OBJ)