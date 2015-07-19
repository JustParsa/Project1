// //
// //  UITableCards.h
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#ifndef _UITABLECARDS_
#define _UITABLECARDS_

#include <stdio.h>
#include <gtkmm.h>
#include "UIPlayerOption.h"
#include "DeckGUI.h"
// #include "Observer.h"
// #include "Controller.h"
// #include "Game.h"

class UITableCards : public Gtk::VBox, public Observer {
public:
    UITableCards();
    virtual ~UITableCards();
    void update();
private:
	DeckGUI						deck;
	Gtk::HBox					cardRow[4];
	Gtk::Image					*cardImages[52];
	// Controller					controller_;
	// Game 						model_;
	void reveal (Rank, Suit);
};

#endif /* defined(_UITABLECARDS_) */