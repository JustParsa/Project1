// //
// //  UITableCards.cc
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#include <gtkmm.h>
#include "UITableCards.h"
#include <deque>

UITableCards::UITableCards(View& view, Game& game) : model_(game), view_(view), tableLbl("Cards on the Table:") {
	add(tableLbl);

	for (int i = 0; i < 52; ++i) {
		cardImages[i] = new Gtk::Image(deck.getNullCardImage());
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			cardRow[i].add(*cardImages[j + 13*i]);
		}
		cardRow[i].set_spacing(10);
		add(cardRow[i]);
	}

	set_spacing(3);

	//reveal(ACE, SPADE);
	// reveal((Rank)3, (Suit)3);
}

void UITableCards::reveal(Rank r, Suit s) {
	cardImages[(int)r + (int)s*13]->set(deck.getCardImage(r, s));
}

void UITableCards::hideAllCards() {
	for (int x = 0; x < 52; x++)
        cardImages[x]->set(deck.getNullCardImage());
}

void UITableCards::update() {
    std::deque<Card*> playedCards = model_.getPlayedCards();
    if (playedCards.size() == 0) {
        hideAllCards();
    }else{
    //reveal cards on the list
        for(int x = 0; x < playedCards.size(); x++){
            Card* curCard = playedCards.at(x);
            reveal(curCard->getRank(),curCard->getSuit());
        }
    }
}

UITableCards::~UITableCards() {
	for (int i = 0; i < 52; ++i) {
		delete cardImages[i];
	}
}

