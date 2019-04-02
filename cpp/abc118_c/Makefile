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

test:
	./main < ex1.txt
	./main < ex2.txt
	./main < ex3.txt