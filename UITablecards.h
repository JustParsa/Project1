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
#include "Game.h"
#include "View.h"

class View;

class UITableCards : public Gtk::VBox {
public:
    UITableCards(View&, Game&);
    virtual ~UITableCards();
    void update();
private:
	DeckGUI						deck;
	Gtk::HBox					cardRow[4];
	Gtk::Image					*cardImages[52];
	Game& 						model_;
	View&						view_;
	void reveal (Rank, Suit);
};

#endif /* defined(_UITABLECARDS_) */