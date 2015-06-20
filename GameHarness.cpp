#include <iostream>
#include <deque>
#include <cstdlib>
#include "Command.h"
#include "Player.h"
#include "Game.h"

using namespace std;


/*
 this may be unnecessary if
 bad input is never given
 */
bool isInteger(const std::string & s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))){
        return false;
    }

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

/*
 prints the score for all players
 */
void printScore(Game& g) {
	for (int x = 1; x <= 4; x++) {
		cout << "Player " << x << "'s discards:";
		vector<Card*> discardedCards = g.getDiscardedCards(x);
		for (int y = 0; y < discardedCards.size(); y++) {
			cout << " " << discardedCards.at(y);
		}
		cout << endl;

		cout << "Player " << x << "'s score: " << g.getPlayerTotalPoints(x - 1) << " + " << g.getPlayerPoints(x - 1) << " = " << g.getPlayerTotalPoints(x - 1) + g.getPlayerPoints(x) << endl;
	}
}

void printStartGamePlay(int firstPlayer) {
	cout << "A new round begins. It's player " << firstPlayer << "'s turn to play." << endl;
}

int main(int argc, char** argv) {
	int seed = 0;
	if (argc >= 2) {
		string stringSeed = string(argv[1]);
		int seed;
		if (isInteger(stringSeed)) {
			seed = atoi(stringSeed.c_str());
		}
		else {
			cerr << "Invalid string argument." << endl;
			seed = 0;
		}
	}

	vector <bool> humanPlayers;
	for (int x = 1; x <= 4; x++){
		char input;
		cout << "Is player " << x << " a human(h) or a computer(c)?" << endl << ">";
		cin >> input;
		if (input == 'h'){
			humanPlayers.push_back(true);
		}
		else if (input == 'h'){
			humanPlayers.push_back(false);
		}
		else{
			cerr << "Invalid user type." << endl;
			return 0;
		}
	}
	Game g = Game(humanPlayers, seed);
	Command currentCommand;
	printStartGamePlay(g.findFirstPlayer());
	do{
		if (g.isGameOver()) {

			printScore(g);
			int winner = g.addAllPlayerPoints();
			if (winner >= 0) {
				//there is a winner
				cout << "Player " << winner + 1 << " wins!" << endl;
				return 0;
			}
			//there are no winners
			//g.restart();
			printStartGamePlay(g.findFirstPlayer());
		}
	} while (true);
}

/*
int main(int argc, char** argv) {
	do {
		if (g.isGameOver()) {

			printScore(game);
			int winner = game.addPointsAndGetWinner();
			if (winner >= 0) {
				//there is a winner
				cout << "Player " << winner + 1 << " wins!" << endl;
				return 0;
			}
			//there are no winners
			game.restart();
			printNewGameMessage(game);
		}
		else {
			if (game.isCurrentPlayerHuman()) {
				//get input for human player
				if (printMessage) {
					printHumanPlayerMessage(game);
				}
				cout << ">";
				cin >> inputCommand;
				switch (inputCommand.type) {
				case QUIT:
					return 0;
				case DECK:
					printDeck(game);
					proceedToNextPlayer = false;
					break;
				case PLAY:
					proceedToNextPlayer = humanPlayValidation(game, inputCommand.card);
					break;
				case DISCARD:
					proceedToNextPlayer = humanDiscardValidation(game, inputCommand.card);
					break;
				case RAGEQUIT:
					game.humanRageQuit();
					cout << "Player " << game.getCurrentPlayer() + 1 << " ragequits. A computer will now take over." << endl;
					startComputerAction(game);
					proceedToNextPlayer = true;
				}
				printMessage = false;
			}
			else {
				//computer player performs move
				startComputerAction(game);
			}
			if (proceedToNextPlayer) {
				game.next();
				printMessage = true;
			}
		}
	} while (inputCommand.type != QUIT);

	return 0;
}
*/