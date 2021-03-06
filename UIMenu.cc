// //
// //  UIMenu.cpp
// //  Deliverable1
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#include <gtkmm.h>
#include "UIMenu.h"

class View;

UIMenu::UIMenu(View& view) : startGameBtn("Start Game"), endGameBtn("End Game"), view_ (view){
    add(startGameBtn);
    add(seedEntry);
    add(endGameBtn);
    seedEntry.set_text("0");
    seedEntry.set_alignment(0.5);

    startGameBtn.signal_clicked().connect(sigc::mem_fun(*this, &UIMenu::startNewGame));
    endGameBtn.signal_clicked().connect(sigc::mem_fun(*this, &UIMenu::endGame));
};

void UIMenu::startNewGame () {
	view_.startNewGame(seedEntry.get_text());
}

void UIMenu::endGame () {
	view_.endGame();
}

void UIMenu::update() {
}

UIMenu::~UIMenu() {};