
#include <deque>
#include "Player.h"
#include "Card.h"

using namespace std;

Player::Player(bool isPlayerHuman, int playerNumber) : isPlayerHuman_(isPlayerHuman),playerNumber_(playerNumber), points_(0), totalPoints_(0) {}
Player::~Player() {};
bool Player::isPlayerHuman() const {return isPlayerHuman_;}
vector<Card> Player::getHand() const {return hand_;}
vector<Card> Player::getDiscardedCards() const {return discardedCards_;}
int Player::getPoints() const {return points_;}
int Player::getTotalPoints() const { return totalPoints_; }
void Player::pushDiscardedDeck(Card card) {discardedCards_.push_back(card);}
void Player::sumTotalPoints() {
	totalPoints_ += points_;
	points_ = 0;
}
void Player::newRound() {
	hand_.clear();
	discardedCards_.clear();
}
void Player::addPoints(Card card) {
	points_ += card.getRank() + 1;
}
bool Player::hasCard(Card card) const {
	for (int x = 0; x < hand_.size(); x++) {
		if (hand_.at(x) == card) {
			return true;
		}
		else{
			return false;
		}

	}
	return false;
}
void Player::addCard(Card card) {
	hand_.push_back(card);
}

