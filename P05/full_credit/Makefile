
CXXFLAGS += --std=c++17

Gate: Gate.o main.o *.h
	$(CXX) $(CXXFLAGS) -o Gate Gate.o main.o
Gate.o: Gate.cpp *.h
	$(CXX) $(CXXFLAGS) -c Gate.cpp
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
clean:
	-rm -f *.o *.gch *~ Gate

