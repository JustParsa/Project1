#include <iostream>
#include <cstdlib>
#include <random>
#include "Game.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Card.h"

const int CARD_COUNT = 52;

using namespace std;


/*
 Constructor for the game class;
 Does all the setup for the game
 to begin
 */

Game::Game(vector<bool> humanPlayers, int seed) : seed_(seed){

	for (int x = 0; x < 4; x++) {
		if (humanPlayers.at(x))
			players_[x] = new HumanPlayer(humanPlayers.at(x), x);
		else
			players_[x] = new ComputerPlayer(humanPlayers.at(x), x);
	}
	
	initDeck();
	shuffle();
	initPlayerCards();
	currentPlayer_ = findFirstPlayer();
		
}

// return appropriate string of suit based on suit object
const char* getSuit(enum Suit s)
{
	switch (s)
	{
	case CLUB: return "Clubs";
	case DIAMOND: return "Diamonds";
	case HEART: return "Hearts";
	case SPADE: return "Spades";
    default: return "";
	}
}

// return appropriate string of rank based Rank object
const char* getRank(enum Rank s)
{
	switch (s)
	{
	case ACE: return "Ace";
	case TWO: return "Two";
	case THREE: return "Three";
	case FOUR: return "Four";
	case FIVE: return "Five";
	case SIX: return "Six";
	case SEVEN: return "Seven";
	case EIGHT: return "Eight";
	case NINE: return "Nine";
	case TEN: return "Ten";
	case JACK: return "Jack";
	case QUEEN: return "Queen";
	case KING: return "King";
    default: return "";
	}
}

void Game::shuffle(){
	static mt19937 rng(seed_);

	int n = CARD_COUNT;

	while (n > 1) {
		int k = (int)(rng() % n);
		--n;
		Card *c = cards_[n];
		cards_[n] = cards_[k];
		cards_[k] = c;
	}
}

vector <Card*> Game::getDiscardedCards(int player) const{ 
	return players_[player]->getDiscardedCards();
}

/*
 initialize deck: for every suit create all ranks
 and populate the cards_ array with pointers
 to objects representing every card in the deck
 */
void Game::initDeck() {
	int i = 0;
	for (int suit = CLUB; suit < SUIT_COUNT; suit++) {
		for (int rank = ACE; rank < RANK_COUNT; rank++) {
			cards_[i] = new Card((Suit)suit, (Rank)rank);
			i++;
		}
	}
}

bool Game::isGameOver() const{
	int numCardsPlayed = playedCards.getCardsOnTableOfSuit(0).size() + playedCards.getCardsOnTableOfSuit(1).size() + playedCards.getCardsOnTableOfSuit(2).size() + playedCards.getCardsOnTableOfSuit(3).size() + players_[0]->getDiscardedCards().size() + players_[1]->getDiscardedCards().size() + players_[2]->getDiscardedCards().size() + players_[3]->getDiscardedCards().size();
	if (numCardsPlayed<52){
		return false;
	}
	return true;
}

/*
 Calculate the points of every single player,
 including the winner and returns it, if one exists
 */
int Game::addAllPlayerPoints() const{

	for (int x = 0; x < 4; x++){
		players_[x]->sumTotalPoints();
	}

	int winnerScore = players_[0]->getTotalPoints();
	int winner = 0;
	bool greaterThanEightyPoints = false;

	for (int x = 0; x < 4; x++)
		if (players_[x]->getTotalPoints() >= 80)
			greaterThanEightyPoints = true;

    if (greaterThanEightyPoints) {
        for (int x = 1; x < 4; x++) {
			if (players_[x]->getTotalPoints() < winnerScore) {
				winnerScore = players_[x]->getTotalPoints();
				winner = x;
            }
        }
    }

	if (greaterThanEightyPoints)
		return winner;
	return -1;
}

/*
 add points of current with 
 the total number of points and 
 check if it exceeds 80
 */
bool Game::numPointsGreaterThanEighty() const{

	for (int x = 0; x < 4; x++)
		if (players_[x]->getPoints() + players_[x]->getTotalPoints() >= 80)
			return true;

	return false;
}

/*
 Initialize cards for all 4 players
 */
void Game::initPlayerCards() {
	for (int currPlayer = 0; currPlayer < 4; currPlayer++) {
		for (int cardIndex = 0; cardIndex < 13; cardIndex++) {
			int currCard = currPlayer * 13 + cardIndex;
			Card* currentCard = cards_[currCard];
			players_[currPlayer]->addCard(currentCard);
		}
	}
}

/*
 Search for player with seven of spades
 and set them to the first player
 */
int Game::findFirstPlayer() {
	for (int currPlayer = 0; currPlayer < 4; currPlayer++) {
		for (int cardIndex = 0; cardIndex < 13; cardIndex++) {
			int currCard = currPlayer * 13 + cardIndex;
			if (cards_[currCard]->getRank() == SEVEN && cards_[currCard]->getSuit() == SPADE){
				currentPlayer_ = currPlayer;
				return currPlayer;
			}
		}
	}
}

/*
 Iterate to next player
 */
void Game::nextPlayer() {
	currentPlayer_++;
	if (currentPlayer_ >= 4)
		currentPlayer_ = currentPlayer_ % 4;
}

void Game::newRound(){

	for (int i = 0; i < 4; ++i) {
		players_[i]->newRound();
	}
	playedCards.newRound();
	shuffle();
	initPlayerCards();
	currentPlayer_ = findFirstPlayer();
}
/*
 print cards delimited with spaces
 */

void Game::printCards() const{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 12; j++) {
			cout << *cards_[i * 13 + j] << " ";
		}
		cout << *cards_[i * 13 + 12] << endl;
	}
}

/*
 The following function is responsible
 for informing the human player on the game
 and prompting for valid moves
 */
void Game::printHumanGameplay() {
	cout << "Cards on the table:" << endl;

	for (int suit = CLUB; suit < SUIT_COUNT; suit++) {
		cout << getSuit((Suit)suit) << ":";
		deque<Card*> cards = playedCards.getCardsOnTableOfSuit((Suit)suit);
		for (int x = 0; x < cards.size(); x++) {
			cout << " " << cards.at(x)->getRank() + 1;
		}
		cout << endl;
	}

	cout << "Your hand:";
	vector<Card*> hand = players_[currentPlayer_]->getHand();
	for (int x = 0; x < hand.size(); x++) {
		cout << " " << *hand.at(x);
	}
	cout << endl;

	//Print current player's legal plays
	cout << "Legal Plays:";

	vector<Card*> legalPlays = players_[currentPlayer_]->getLegalPlays(playedCards);

	for (vector<Card*>::const_iterator itr = legalPlays.begin(); itr < legalPlays.end(); itr++) {
		cout << " " << **itr;
	}
	cout << endl;

}


/*
 return points of the player for the current round
 */
int Game::getPlayerPoints(int player){

	return players_[player]->getPoints();

}

bool Game::playCard(Card* card, string typeOfAction){

	return players_[currentPlayer_]->performMove(playedCards, card, typeOfAction);

}

bool Game::discardCard(Card* card, string typeOfAction){

	return players_[currentPlayer_]->performMove(playedCards, card, typeOfAction);

}

/*
 return the total points of a player
 */
int Game::getPlayerTotalPoints(int player){

	return players_[player]->getTotalPoints();

}

Card* Game::getPointerToCard(Card card){
	for (int x = 0; x < 52; x++){
		if (cards_[x]->getRank() == card.getRank() && cards_[x]->getSuit() == card.getSuit()){
			return cards_[x];
		}

	}
}

/*
prints the score for all players
*/

void Game::printScore() {
	for (int x = 1; x <= 4; x++) {
		cout << "Player " << x << "'s discards:";
		vector<Card*> discardedCards = getDiscardedCards(x-1);
		for (int y = 0; y < discardedCards.size(); y++) {
			cout << " " << *discardedCards.at(y);
		}
		cout << endl;

		cout << "Player " << x << "'s score: " << getPlayerTotalPoints(x - 1) << " + " << getPlayerPoints(x - 1) << " = " << getPlayerTotalPoints(x - 1) + getPlayerPoints(x-1) << endl;
	}
}

bool Game::isCurrentPlayerHuman() const{

	return players_[currentPlayer_]->isPlayerHuman();

};

int Game::getCurrentPlayer() const{

	return currentPlayer_;

};
void Game::humanRageQuit(){

	Player* newPlayer = NULL;
	if (isCurrentPlayerHuman()){
		newPlayer = new ComputerPlayer(*players_[currentPlayer_]);
	}
	delete players_[currentPlayer_];
	players_[currentPlayer_] = newPlayer;

}