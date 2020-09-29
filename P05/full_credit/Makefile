
CXXFLAGS += --std=c++17

Gate: Gate.o main.o and.o or.o *.h
	$(CXX) $(CXXFLAGS) -o Gate Gate.o main.o and.o
Gate.o: Gate.cpp *.h
	$(CXX) $(CXXFLAGS) -c Gate.cpp
and.o: and.cpp *.h
	$(CXX) $(CXXFLAGS) -c and.cpp
or.o: or.cpp *.h
	$(CXX) $(CXXFLAGS) -c or.cpp
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
clean:
	-rm -f *.o *.gch *~ Gate

