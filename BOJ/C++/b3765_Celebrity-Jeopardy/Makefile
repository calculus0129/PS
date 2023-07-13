#Makefile For Windows
DEPS=b3765.c
OBJ=$(patsubst %.c,%.o,$(DEPS))
pgm:	$(OBJ)
	gcc -Wall -lm -O2 -static -std=gnu99 -o $@ $^ -DONLINE_JUDGE -DBOJ
