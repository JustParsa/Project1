CXX = g++ 			
CXXFLAGS = -g -Wall -MMD `pkg-config gtkmm-2.4 --cflags` -std=c++0x
LDFLAGS=`pkg-config gtkmm-2.4 --libs`
OBJECTS = Card.o Command.o ComputerPlayer.o Game.o HumanPlayer.o GameHarness.o Player.o PlayedCards.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = straights

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} $(LDFLAGS) -o ${EXEC}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}	# reads the .d files and reruns dependencies
