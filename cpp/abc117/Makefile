CXX=g++
CXXFLAGS=-O2 -g -W -std=c++11
CXXLIBS=
CXXSRC=$(wildcard *.cpp)
CXXTARGET=$(basename $(CXXSRC))

all:$(CXXTARGET)
$(CXXTARGET):%:%.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS) $(CXXLIBS)
# static pattern rule
# targets... : target-pattern : dep-patterns...

testa:
	./a < a1.txt
	./a < a2.txt
	./a < a3.txt

testb:
	./b < b1.txt
	./b < b2.txt
	./b < b3.txt

testc:
	./c < c1.txt
	./c < c2.txt
	./c < c3.txt

testd:
	./d < d1.txt
	./d < d2.txt
	./d < d3.txt