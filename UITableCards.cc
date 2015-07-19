// //
// //  UITableCards.cc
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#include <gtkmm.h>
#include "UITableCards.h"

UITableCards::UITableCards() {

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

	reveal(ACE, SPADE);
	// reveal((Rank)3, (Suit)3);
}

void UITableCards::reveal(Rank r, Suit s) {
	cardImages[(int)r + (int)s*13]->set(deck.getCardImage(r, s));
}

UITableCards::~UITableCards() {
	for (int i = 0; i < 52; ++i) {
		delete cardImages[i];
	}
}

