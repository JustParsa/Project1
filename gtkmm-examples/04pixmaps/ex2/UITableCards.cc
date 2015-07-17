// //
// //  UITableCards.cc
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#include <gtkmm.h>
#include "UITableCards.h"

UITableCards::UITableCards() {
	// NOTE: MUST BE CHANGED LATER FROM 4,13 TO SUIT/RANK SIZE
	for (int i = 0; i < 52; ++i) {
		cardImages[i] = new Gtk::Image(deck.getCardImage((Rank)(i%13), (Suit)(i/13)));
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; ++j) {
			cardRow[i].add(*cardImages[j + 13*i]);
		}
			cardRow[i].set_spacing(10);
			add(cardRow[i]);

	}
	set_spacing(3);
}

UITableCards::~UITableCards() {}

