
CXXFLAGS += --std=c++17

Modulo: Modulo.o main.o *.h
	$(CXX) $(CXXFLAGS) -o Modulo Modulo.o main.o
Modulo.o: Modulo.cpp *.h
	$(CXX) $(CXXFLAGS) -c Modulo.cpp
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
clean:
	-rm -f *.o *.gch *~ Modulo



