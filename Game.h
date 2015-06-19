#ifndef GAME_H
#define	GAME_H

#include "Card.h"
#include "Player.h"
#include <vector>

class Game {
public:
	Game(std::vector<bool> humanPlayers, int);		//Initialises the deck, the players, shuffles the deck, distributes the cards
	//virtual ~Game();
	//void next();
	//void restart();
	void initDeck();
	void initPlayerCards();
	int findFirstPlayer();
	void shuffle();
	bool numPointsGreaterThanEighty() const;
	void nextPlayer();
	//Action humanPlaysCard(Card card);
	//Action humanDiscardsCard(Card card);
	//Action computerPerformsMove();
	//void humanRageQuit();
	bool isGameOver() const;
	bool isCurrentPlayerHuman() const;
	int addAllPlayerPoints() const;
	void printCards() const;
	//int getCurrentPlayer() const;
	//std::vector<Card*> getDeck() const;
	//std::vector<Card*> getCardsOnTable(Suit suit) const;
	//std::vector<Card*> getCurrentPlayerHand() const;
	//std::vector<Card*> getCurrentPlayerLegalPlays() const;
	//std::vector<Card*> getPlayerDiscardedCards(int player) const;
private:
	Card* cards_[52]; //all cards of the deck
	Player* players_[4]; //players of the game
	std::vector<Card*> playedCards_;
	int currentPlayer_; //index of current player
	int numCardsPlayed_; //number of cards played
	int seed_;
	//Table* table; //table of cards
};

#endif	/* GAME_H */

