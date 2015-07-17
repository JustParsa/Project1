CXX = g++ 			
CXXFLAGS = -g -Wall -MMD `pkg-config gtkmm-2.4 --cflags` -std=c++0x -w
LDFLAGS=`pkg-config gtkmm-2.4 --libs`
OBJECTS = Observer.o Card.o Command.o ComputerPlayer.o Exception.o Game.o HumanPlayer.o Player.o PlayedCards.o Controller.o View.o main.o CurrentHandDisplay.o CardImageLoader.o MenuDisplay.o TableDisplay.o PlayerInfoDisplay.o PlayerInfoDisplayPanel.o Notification.o Subject.o CardSelector.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = straights

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} $(LDFLAGS) -o ${EXEC}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}	# reads the .d files and reruns dependencies
