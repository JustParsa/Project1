#include <iostream>
#include <deque>
#include <cstdlib>
#include "Command.h"
#include "Player.h"
#include "Game.h"

using namespace std;

inline bool isInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
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
	Command c;
	while (!g.isGameOver()){



	}

}

/*
void printHumanPlayerOutput(Player *player) {
	//Print cards on table
	cout << "Cards on the table:" << endl;
	for (int suit = 0; suit < SUIT_COUNT; ++suit) {
		cout << suitNames[suit] << ":";
		deque<Card> cards = game.getCardsOnTable((Suit)suit);
		for (deque<Card>::const_iterator itr = cards.begin(); itr < cards.end(); ++itr) {
			cout << " " << rankNames[itr->getRank()];
		}
		cout << endl;
	}

	//Print current player's hand
	cout << "Your hand:";
	deque<Card> hand = game.getCurrentPlayerHand();
	for (deque<Card>::const_iterator itr = hand.begin(); itr < hand.end(); ++itr) {
		cout << " " << *itr;
	}
	cout << endl;

	//Print current player's legal plays
	cout << "Legal Plays:";
	deque<Card> legalPlays = game.getCurrentPlayerLegalPlays();
	for (deque<Card>::const_iterator itr = legalPlays.begin(); itr < legalPlays.end(); ++itr) {
		cout << " " << *itr;
	}
	cout << endl;
}
*/