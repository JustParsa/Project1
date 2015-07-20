// //
// //  UIPlayerCards.h
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#ifndef __UIPlayerCards__
#define __UIPlayerCards__

#include <stdio.h>
#include <gtkmm.h>
#include "DeckGUI.h"
#include "Game.h"
#include "View.h"

class UIPlayerCards : public Gtk::HBox {
public:
    UIPlayerCards(View&, Game&);
    virtual ~UIPlayerCards();
    void update();
private:
	DeckGUI							deck;
	View&							view_;
	Game&							model_;
	Gtk::Button						*playerHand[13];
	Gtk::Image						*cardImages[52];
	Gtk::Image						*nullImg[13];
	void eventCardSelect(int);
};

#endif /* defined(__UIPlayerCards__) */
