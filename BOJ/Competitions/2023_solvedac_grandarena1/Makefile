#Makefile For Windows
DEPS=A.cc# .cc
OBJ=$(patsubst %.cc,%.o,$(DEPS))
pgm:	$(OBJ)
	g++ -Wall -lm -O2 -static -std=gnu++17 -o $@ $^ -DONLINE_JUDGE -DBOJ
#del $^
.PHONY:	clean
clean:
	del $(OBJ)