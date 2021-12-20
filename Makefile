SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=obj/%.o)

all: txtdb

txtdb: $(OBJ)
	@mkdir -p $(@D)
	g++ -std=c++14 -g -o $@ $^

obj/%.o: %.cpp $(wildcard *.hpp) Makefile
	@mkdir -p $(@D)
	g++ -c -std=c++14 -g -o $@ $<

clear:
	@rm -r obj txtdb 2> /dev/null || true

.PHONY: all clear
