CXX= g++
#CXXFLAGS = -g `/opt/local/bin/pkg-config gtkmm-2.4 --cflags --libs`
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = DeckGUI.o View.o Main.o UIMenu.o UIPlayerOption.o UIPlayerOptions.o UITableCards.o UIPlayerCards.o
EXEC = other

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)

DeckGUI.o: DeckGUI.h DeckGUI.cc
View.o: View.h View.cc
Main.o: View.h Main.cc
UIMenu.o: UIMenu.h UIMenu.cc
UIPlayerOption.o: UIPlayerOption.cc UIPlayerOption.h
UIPlayerOptions.o: UIPlayerOptions.cc UIPlayerOptions.h
UITableCards.o: UITableCards.cc UITableCards.h
UIPlayerCards.o: UIPlayerCards.cc UIPlayerCards.h

clean:
	rm $(EXEC) $(OBJS)
