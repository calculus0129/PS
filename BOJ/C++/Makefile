#Makefile For Windows
#BOJ_NUM=6086
#DEPS=$(wildcard b$(BOJ_NUM)[^0-9]*.cc)# .cc
#OBJ=$(patsubst %.cc,%.o,$(DEPS))
#pgm:	$(OBJ)
#b6086.cc

# BOJ_NUM?=6086
# DEPS=$(wildcard b$(BOJ_NUM)[^0-9]*.cc)# .cc

# Example: make DEPS=b6086.cc

DEPS?=b6086.cc

CXX=g++
SANFLAGS = -fsanitize=address
LDFLAGS+=$(SANFLAGS)
CXXFLAGS += -Wall -g -O2 -static -std=c++17
OBJ=$(patsubst %.cc,%.o,$(DEPS))
TARGET=pgm

$(TARGET):	$(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)
	echo "DEPS: $(DEPS)"
.phony:	clean
clean:
	$(RM) $(TARGET) *.o
