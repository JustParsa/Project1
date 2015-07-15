
#include "HumanPlayer.h"
#include "Player.h"
#include <vector>

using namespace std;

HumanPlayer::HumanPlayer(bool isPlayerHuman, int playerNumber) : Player(isPlayerHuman, playerNumber) {};

HumanPlayer::~HumanPlayer() {}

bool HumanPlayer::performMove(PlayedCards& playedCards, Card* card, string typeOfAction) {
	printAction(card, typeOfAction);
	if (typeOfAction == "plays") {
		return HumanPlayer::playCard(playedCards, card);
	}
	else if (typeOfAction == "discards") {
		return HumanPlayer::discardCard(playedCards, card);
	}
	return false;
}

bool HumanPlayer::playCard(PlayedCards& playedCards, Card* card) {
	
	if (!hasCard(card)) {
		cerr << "You don't have that card!!!!" << endl;
		return false;
	}
	try{
		playedCards.pushCard(card);
		removeCard(card);
	}
	catch (exception e){
		cout << e.what() << endl;
		return false;
	}
	return true;
}

bool HumanPlayer::discardCard(PlayedCards& playedCards, Card* card) {
	vector<Card*> legalPlays = getLegalPlays(playedCards);
	if (legalPlays.size() != 0){
		cerr << "You cannot discard a card, you can still play a card!!!\n";
		return false;
	}
	try{
		removeCard(card);
		pushDiscardedDeck(card);
		addPoints(card);
	}
	catch (exception e){
		cout << e.what() << endl;
		return false;
	}
	return true;
}
