

#include "ComputerPlayer.h"
#include "Player.h"
#include <vector>

using namespace std;

ComputerPlayer::ComputerPlayer(bool isPlayerHuman, int playerNumber) : Player(isPlayerHuman, playerNumber) {};

ComputerPlayer::~ComputerPlayer() {}
ComputerPlayer::ComputerPlayer(Player& p) : Player(p) {}

bool ComputerPlayer::performMove(PlayedCards& playedCards, Card* card, string typeofMove) {
	vector<Card*> legalPlays = getLegalPlays(playedCards);
	vector<Card*> currentHand = getHand();
	if (legalPlays.size() != 0){
		printAction(legalPlays.at(0), "plays");
		return ComputerPlayer::playCard(playedCards, legalPlays.at(0));
	}
	else{
		printAction(currentHand.at(0), "discards");
		return ComputerPlayer::discardCard(playedCards, currentHand.at(0));
	}
}




bool ComputerPlayer::playCard(PlayedCards& playedCards, Card* card) {
	vector<Card*> legalPlays = getLegalPlays(playedCards);
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

bool ComputerPlayer::discardCard(PlayedCards& playedCards, Card* card) {

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


