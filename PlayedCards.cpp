#include <deque>
#include <array>
#include <iostream>
#include "Card.h"
#include "PlayedCards.h"
using namespace std;

PlayedCards::PlayedCards(){}
bool PlayedCards::isEmpty() const{
	for (int x = 0; x < 4; x++){
		if (playedCards_[x].size() != 0){
			return false;
		}
	}
	return true;

}

bool PlayedCards::isValidPlay(Card* card) const {
	if (card->getRank() == SEVEN && card->getSuit() != SPADE) {
		return true;
	}
	if (isEmpty()){
		return false;
	}
	if (card->getRank() == SEVEN){
		return true;
	}

	if (playedCards_[card->getSuit()].size() == 0)
		return false;

	if (card->getRank() != ACE && playedCards_[card->getSuit()].front()->getRank() - 1 == card->getRank())
		return true;

	if (card->getRank() != KING && playedCards_[card->getSuit()].front()->getRank() + 1 == card->getRank())
		return true;
	return false;
}

void PlayedCards::pushCard(Card* card) {
	
	if (card->getRank() == SEVEN && card->getSuit() == SPADE) {
		playedCards_[card->getSuit()].push_back(card);
	}
	else if (isEmpty()){
		throw exception("You cannot play that card! You must start with the 7 of Spades!");
	}
	else if (card->getRank() == SEVEN){
		playedCards_[card->getSuit()].push_back(card);
	}
	else if (playedCards_[card->getSuit()].size() == 0){
		throw exception("There are no cards for that specific suit. You cannot do that!");
	}
	else if (card->getRank() != ACE && playedCards_[card->getSuit()].front()->getRank() - 1 == card->getRank()) {
		playedCards_[card->getSuit()].push_back(card);
	}
	else if (card->getRank() != KING && playedCards_[card->getSuit()].front()->getRank() + 1 == card->getRank() == true) {
		playedCards_[card->getSuit()].push_front(card);
	}
}

deque<Card*> PlayedCards::getCardsOnTableOfSuit(int suit) const {
	return playedCards_[suit];
}

void PlayedCards::newRound(){
	for (int x = 0; x < 4; x++)
		playedCards_[x].clear();

}
