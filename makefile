CXX = g++ 			
CXXFLAGS = -g -Wall -MMD `pkg-config gtkmm-2.4 --cflags` -std=c++0x -w
LDFLAGS=`pkg-config gtkmm-2.4 --libs`
OBJECTS = Card.o ComputerPlayer.o Controller.o DeckGUI.o Game.o HumanPlayer.o Main.o Observer.o PlayedCards.o Player.o Subject.o UIMenu.o UIPlayerCards.o UIPlayerOption.o UIPlayerOptions.o UITableCards.o View.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = straights

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} $(LDFLAGS) -o ${EXEC}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}	# reads the .d files and reruns dependencies
