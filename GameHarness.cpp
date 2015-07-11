#include <iostream>
#include <deque>
#include <cstdlib>
#include <string>
#include "Command.h"
#include "Player.h"
#include "Game.h"
using namespace std;

/*
 prints the score for all players
 */

void printAction(int index, string actionPerformed, Card* c) {
	
	index++;
	cout << "Player " << index << " "<< actionPerformed << ": " <<  *c << "." << endl;
}

void printStartGamePlay(int firstPlayer) {
	cout << "A new round begins. It's player " << firstPlayer << "'s turn to play." << endl;
}

void isPlayersHuman(vector <bool> &humanPlayers) {
	for (int x = 1; x <= 4; x++){
		char input;
		cout << "Is player " << x << " a human(h) or a computer(c)?" << endl << ">";
		cin >> input;
		if (input == 'h'){
			humanPlayers.push_back(true);
		}
		else if (input == 'c'){
			humanPlayers.push_back(false);
		}
		else{
			cerr << "Invalid user type." << endl;
		}
	}
}

int main(int argc, char** argv) {
	int seed = 0;
	if (argc >= 2) {
		string stringSeed = string(argv[1]);
		seed = atoi(stringSeed.c_str());
	}

	vector <bool> humanPlayers;
	isPlayersHuman(humanPlayers);
	Game g = Game(humanPlayers, seed);
	printStartGamePlay(g.findFirstPlayer() + 1);
	Command currentCommand;
	bool proceedToNextPlayer = true;
	do{
		if (g.isGameOver()) {

			g.printScore();
			int winner = g.addAllPlayerPoints();
			if (winner >= 0) {
				cout << "Player " << winner << " wins!" << endl;
				return 0;
			}
			g.newRound();
			printStartGamePlay(g.findFirstPlayer() + 1);
		}

		if (g.isCurrentPlayerHuman()) {
			g.printHumanGameplay();

			//if (printMessage) {
				//g.printHumanGameplay();
			//}

			cout << ">";
			cin >> currentCommand;
			bool proceedToNextPlayer;
			bool printMessage;
			Card* pointerToCard;
			switch (currentCommand.type) {
			case QUIT:
				return 0;
			case DECK:
				g.printCards();
				proceedToNextPlayer = false;
				break;
			case PLAY:
				pointerToCard = g.getPointerToCard(currentCommand.card);
				g.playCard(pointerToCard, "play");
				break;
			case DISCARD:
				pointerToCard = g.getPointerToCard(currentCommand.card);
				g.discardCard(pointerToCard, "play");
				break;
				/*
			case RAGEQUIT:
			cout << "Player " << g.getCurrentPlayer() + 1 << " ragequits. A computer will now take over." << endl;
			proceedToNextPlayer = true;
			*/
			}
			
				printMessage = false;
		}
	} while (currentCommand.type != QUIT);
}