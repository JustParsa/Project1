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
#include "Observer.h"
#include "Controller.h"
#include "Game.h"

class UIPlayerCards : public Gtk::HBox {
public:
    UIPlayerCards();
    virtual ~UIPlayerCards();
    void update();
private:
	DeckGUI							deck;
	Gtk::Button						playerHand[13];
	Gtk::Image						*cardImages[52];
};

#endif /* defined(__UIPlayerCards__) */
