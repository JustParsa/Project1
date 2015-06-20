#include <deque>
#include <array>
#include <iostream>
#include "Card.h"
#include "PlayedCards.h"
using namespace std;

PlayedCards::PlayedCards(){}
bool PlayedCards::isEmpty() const{
	for (int x = 0; x < 4; x++)
		if (playedCards_[x].size() != 0)
			return false;

	return true;

}

bool PlayedCards::isValidPlay(Card* card) const {
	if (card->getRank() == SEVEN) {
		if (isEmpty() &&card->getSuit() != SPADE) {
			return false;
		}
		return true;
	}
	if (playedCards_[card->getRank()].size() == 0)
		return false;
	if (card->getRank() != ACE && playedCards_[card->getSuit()].front()->getRank() - 1 == card->getRank())
		return true;
	if (card->getRank() != KING && playedCards_[card->getSuit()].front()->getRank() + 1 == card->getRank())
		return true;
	return false;
}

void PlayedCards::pushCard(Card* card) {
	
	if (card->getRank() == SEVEN) {
		if (isEmpty() && card->getSuit() != SPADE) {
			cout << "WTF MAN" << endl;
		}
		//first card to be inserted
		playedCards_[card->getSuit()].push_back(card);
	}
	else if (card->getRank() != ACE && playedCards_[card->getSuit()].front()->getRank() - 1 == card->getRank()) {
		playedCards_[card->getSuit()].push_back(card);
	}
	else if (card->getRank() != KING && playedCards_[card->getSuit()].front()->getRank() + 1 == card->getRank() == true) {
		playedCards_[card->getSuit()].push_front(card);
	}
	else
		cout << "WTF" << endl;
}

deque<Card*> PlayedCards::getCardsOnTableOfSuit(int suit) const {
	return playedCards_[suit];
}
