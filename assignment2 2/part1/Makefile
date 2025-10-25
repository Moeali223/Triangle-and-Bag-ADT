CXX = g++
CXXFLAGS = -std=gnu++17 -O2 -Wall -Wextra -pedantic

all: triangle

triangle: Triangle.o main.o
	$(CXX) $(CXXFLAGS) -o triangle Triangle.o main.o

Triangle.o: Triangle.cpp Triangle.h
	$(CXX) $(CXXFLAGS) -c Triangle.cpp

main.o: main.cpp Triangle.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o triangle
