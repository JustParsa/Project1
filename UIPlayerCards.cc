// //
// //  UIPlayerCards.cc
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#include <gtkmm.h>
#include "UIPlayerCards.h"

UIPlayerCards::UIPlayerCards() {
	set_spacing(1);
	for (int i = 0; i < 52; i++) {
		cardImages[i] = new Gtk::Image(deck.getCardImage((Rank)(i%13), (Suit)(i/13)));
	}

	for (int i = 0; i < 13; ++i) {
		playerHand[i].set_image(*cardImages[i]);
		add(playerHand[i]);
	}

	set_spacing(3);
}

UIPlayerCards::~UIPlayerCards() {}
