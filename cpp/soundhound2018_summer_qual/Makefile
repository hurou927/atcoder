# CXX=g++
CXX=g++-8
CXXFLAGS=-O2 -g -W -std=c++17
CXXLIBS=
CXXSRC=$(wildcard *.cpp)
CXXTARGET=$(basename $(CXXSRC))

all:$(CXXTARGET)
$(CXXTARGET):%:%.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS) $(CXXLIBS)
# static pattern rule
# targets... : target-pattern : dep-patterns...

testa:
	./a < case/a1.txt
	./a < case/a2.txt
	./a < case/a3.txt

testb:
	./b < case/b1.txt
	./b < case/b2.txt
	./b < case/b3.txt

testc:
	./c < case/c1.txt
	./c < case/c2.txt
	./c < case/c3.txt

testd:
	./d < case/d1.txt
	./d < case/d2.txt
	# ./d < case/d3.txt