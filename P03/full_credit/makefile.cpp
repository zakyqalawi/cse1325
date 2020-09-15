 CXXFLAGS = --std=c++17

tile: tile.o board.o main.o
    $(CXX) $(CXXFLAGS) tile.o board.o main.o -o tile

tile.o: tile.cpp *.h
    $(CXX) $(CXXFLAGS) -c tile.cpp -o tile.o

board.o board.cpp *.h
    $(CXX) $(CXXFLAGS) -c board.cpp -o board.o

main.o main.cpp *.h
    $(CXX) $(CXXFLAGS) -c main.cpp -o main.o
