
#include "HumanPlayer.h"
#include "Player.h"
#include <vector>

using namespace std;

HumanPlayer::HumanPlayer(bool isPlayerHuman, int playerNumber) : Player(isPlayerHuman, playerNumber) {};

HumanPlayer::~HumanPlayer() {}

bool HumanPlayer::performMove(PlayedCards& playedCards, Player& player, Card* card, string typeOfAction) {
	if (typeOfAction == "play") {
		return HumanPlayer::playCard(playedCards, player, card);
	}
	else if (typeOfAction == "discard") {
		return HumanPlayer::discardCard(playedCards, player, card);
	}
    return false;
}

bool HumanPlayer::playCard(PlayedCards& playedCards, Player& player, Card* card) {
	
	if (!player.hasCard(card)) {
		cerr << "You don't have that card!!!!" << endl;
		return false;
	}
	try{
		playedCards.pushCard(card);
		player.removeCard(card);
	}
	catch (exception e){
		cout << e.what() << endl;
		return false;
	}
	return true;
}

bool HumanPlayer::discardCard(PlayedCards& playedCards, Player& player, Card* card) {
	vector<Card*> legalPlays = player.getLegalPlays(playedCards);
	if (legalPlays.size() != 0){
		cerr << "You cannot discard a card, you can still play a card!!!\n";
		return false;
	}
	try{
		player.removeCard(card);
		player.pushDiscardedDeck(card);
		player.addPoints(card);
	}
	catch (exception e){
		cout << e.what() << endl;
		return false;
	}
	return true;
}
