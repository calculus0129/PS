#Makefile For Windows
DEPS=b2023.c# .cc
OBJ=$(patsubst %.c,%.o,$(DEPS))
pgm:	$(OBJ)
	gcc -Wall -lm -O2 -static -std=gnu99 -o $@ $^ -DONLINE_JUDGE -DBOJ
	del $^