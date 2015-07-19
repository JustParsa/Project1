// //
// //  UIPlayerCards.cc
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#include <gtkmm.h>
#include "UIPlayerCards.h"

UIPlayerCards::UIPlayerCards(View& view, Game& model): view_(view), model_(model) {
	for (int i = 0; i < 52; i++) {
		cardImages[i] = new Gtk::Image(deck.getCardImage((Rank)(i%13), (Suit)(i/13)));
	}
    for (int i = 0; i < 13; i++) {
		nullImg[i] = new Gtk::Image(deck.getNullCardImage());
	}
	for (int i = 0; i < 13; ++i) {
		playerHand[i] = new Gtk::Button();
		playerHand[i]->set_image(*nullImg[i]);
		add(*playerHand[i]);
	}

    for (int i = 0; i < 13; i++) {
        (*playerHand[i]).signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &UIPlayerCards::eventCardSelect), i));
    }

	set_spacing(3);
}

void UIPlayerCards::update(){
    vector <Card*> playerCards = model_.getCurrentPlayersHand();
    for (int y = 0; y < 13; y++){
        playerHand[y]->set_image(*nullImg[y]);
    }
    for (int x = 0; x < playerCards.size(); x++){

        Card* currCard = playerCards.at(x);
        playerHand[x]->set_image(*cardImages[currCard->getSuit()*13 + currCard->getRank()]);

    }
}

void UIPlayerCards::eventCardSelect(int i){

    vector <Card*> playerCards = model_.getCurrentPlayersHand();
    std::cerr << i << std::endl;
    if (i<playerCards.size()){
        std::cerr << *playerCards.at(i) << std::endl;
        view_.eventCardSelect(playerCards.at(i));
    }
}

UIPlayerCards::~UIPlayerCards() {
	// for (int i = 0; i < 52; ++i) {
	// 	delete cardImages[i];
	// }
}

