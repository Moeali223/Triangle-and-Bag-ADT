CXX = g++
CXXFLAGS = -std=gnu++17 -O2 -Wall -Wextra -pedantic

all: bags

bags: ArrayBag.o main.o
	$(CXX) $(CXXFLAGS) -o bags ArrayBag.o main.o

ArrayBag.o: ArrayBag.cpp ArrayBag.h
	$(CXX) $(CXXFLAGS) -c ArrayBag.cpp

main.o: main.cpp ArrayBag.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o bags
