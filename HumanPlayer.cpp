
#include "HumanPlayer.h"
#include "Player.h"
#include <vector>

using namespace std;

HumanPlayer::HumanPlayer(bool isPlayerHuman, int playerNumber) : Player(isPlayerHuman, playerNumber) {};

HumanPlayer::~HumanPlayer() {}

void HumanPlayer::performMove(PlayedCards& playedCards, Player& player, Card* card, string typeOfAction) {
	if (typeOfAction == "play") {
		HumanPlayer::playCard(playedCards, player, card);
	}
	else if (typeOfAction == "discard") {
		HumanPlayer::discardCard(playedCards, player, card);
	}
}

void HumanPlayer::playCard(PlayedCards& playedCards, Player& player, Card* card) {
	
	if (!player.hasCard(card)) {
		throw exception("You don'thave that card!!!!");
		return;
	}
	playedCards.pushCard(card);
	player.removeCard(card);
}

void HumanPlayer::discardCard(PlayedCards& playedCards, Player& player, Card* card) {
	//vector<Card*> legalPlays = player.getLegalPlays(playedCards);
	player.addPoints(card);
	player.removeCard(card);
	player.pushDiscardedDeck(card);
}
