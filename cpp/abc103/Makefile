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

testc:
	./c < c1.txt
	./c < c2.txt
	./c < c3.txt