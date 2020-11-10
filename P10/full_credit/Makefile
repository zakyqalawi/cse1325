CXXFLAGS = --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`


all: manga

debug: CXXFLAGS += -g
debug: manga

manga: store.o product.o plant.o tool.o mulch.o Mainwin.o main.o entrydialog.o customer.o *.h
	$(CXX) $(CXXFLAGS)  store.o product.o plant.o tool.o mulch.o Mainwin.o main.o entrydialog.o customer.o $(GTKFLAGS) -o manga
Mainwin.o: Mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c Mainwin.cpp $(GTKFLAGS) -o Mainwin.o
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o
store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp -o store.o
product.o: product.cpp *.h
	$(CXX) $(CXXFLAGS) -c product.cpp -o product.o
plant.o: plant.cpp *.h
	$(CXX) $(CXXFLAGS) -c plant.cpp -o plant.o
tool.o: tool.cpp *.h
	$(CXX) $(CXXFLAGS) -c tool.cpp -o tool.o
mulch.o: mulch.cpp *.h
	$(CXX) $(CXXFLAGS) -c mulch.cpp -o mulch.o
entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o
customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp $(GTKFLAGS) -o customer.o
item.o: item.cpp *.h
	$(CXX) $(CXXFLAGS) -c item.cpp $(GTKFLAGS) -o item.o

clean:
	rm -f *.o *.gch ~* a.out manga
