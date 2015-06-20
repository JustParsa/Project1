
#ifndef TABLE_H
#define	TABLE_H

#include <deque>
#include <vector>
#include "Card.h"

class PlayedCards {
public:
	PlayedCards();
	bool isValidPlay(Card* card) const;
	void pushCard(Card* card);
	bool isEmpty() const;
	void newRound();
	std::deque<Card*> getCardsOnTableOfSuit(int suit) const;
private:
	std::deque<Card*> playedCards_[4];
};

#endif	/* TABLE_H */

