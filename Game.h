#ifndef GAME_H
#define	GAME_H

#include "Card.h"
#include "Player.h"
#include "PlayedCards.h"
#include "Subject.h"
#include <vector>
#include <string>


class Game : public Subject {
public:
	Game();		//Initialises the deck, the players, shuffles the deck, distributes the cards

	//virtual ~Game();
	void newRound();
	void initDeck();
	void initPlayerCards();
	int findFirstPlayer();
	void shuffle();
	bool numPointsGreaterThanEighty() const;
	void nextPlayer();
	void playCard(Card*);
	//bool discardCard(Card *card, std::string);
	void humanRageQuit();
	bool isGameOver() const;
	bool isCurrentPlayerHuman() const;
	int addAllPlayerPoints() const;
	void printCards() const;
	void printHumanGameplay();
	void getPlayerCards();
	int getPlayerPoints(int);
	int getPlayerTotalPoints(int);
	Card* getPointerToCard(Card);
	int getCurrentPlayer() const;
	void changePlayerType(int, bool);
	void changeSeed(int seed);
	void newGame();
	void endGame();
	void computerPlayerAction();
	std::vector<Card*> getDiscardedCards(int) const;
	void printScore();
	std::deque<Card*> getPlayedCards();
	std::vector<Card*> getCurrentPlayersHand();
	std::vector<Card*> getCurrentPlayersLegalPlays();
	bool isGameRunning();
	bool canRageQuit(int);
	void updateGameState();
	bool isSelectedPlayerHuman(int);
private:
	Card* cards_[52]; //all cards of the deck
	Player* players_[4]; //all the players of the game
	PlayedCards playedCards; //The cards on the table
	bool playerType_[4];
	int currentPlayer_; //The current player
	int seed_;
	bool isGameRunning_;
};

#endif	/* GAME_H */

