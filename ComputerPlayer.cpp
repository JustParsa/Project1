#include "ComputerPlayer.h"
#include "Player.h"
#include <deque>


using namespace std;

ComputerPlayer::ComputerPlayer() {
}

ComputerPlayer::~ComputerPlayer() {
}

void ComputerPlayer::performMove(PlayedCards&, Player&, Card*){
	deque<Card> availablePlays = player.getLegalPlays(table);

	if (availablePlays.empty()) {
		return discardCard(table, action, player);
	}
	else {
		return playCard(table, action, player);
	}
}

Action ComputerPlayer::playCard(PlayedCards&, Player&, Card*) {
	deque<Card> availablePlays = player.getLegalPlays(table);
	Card playCard = availablePlays.front();
	//remove the card from player and add it to the cards on table
	player.removeCard(playCard);
	table.addCard(playCard);
	return Action(PLAY_ACTION, playCard);
}

Action ComputerPlayer::discardCard(Table& table, Action action, Player& player) {
	deque<Card> curHand = player.getHand();
	Card playCard = curHand.front();
	//remove the card from player and add it to the player's discarded card list
	player.addPoints(playCard);
	player.removeCard(playCard);
	player.addDiscardedCard(playCard);
	return Action(DISCARD_ACTION, playCard);
}
