// //
// //  UIPlayerOption.cc
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#include <gtkmm.h>
#include "UIPlayerOption.h"

UIPlayerOption::UIPlayerOption(View& view, Game& model, int playerPos) : pointsLbl("Points: 0"), discardsLbl("Discards: 0"), togglePlayerBtn("Human"), rageQuitBtn("Rage Quit!"), view_(view), model_(model), playerPos_(playerPos), isPlayerHuman(true){
	set_border_width(5);
	set_spacing(7);
	add(togglePlayerBtn);
	add(rageQuitBtn);
	add(pointsLbl);
	add(discardsLbl);

	rageQuitBtn.set_sensitive(false);

	rageQuitBtn.signal_clicked().connect(sigc::mem_fun(view, &View::eventRageQuit));
    togglePlayerBtn.signal_clicked().connect(sigc::mem_fun(*this, &UIPlayerOption::togglePlayerType));
}

void UIPlayerOption::update(){

}

void UIPlayerOption::togglePlayerType() {
	isPlayerHuman = !isPlayerHuman;
	if (isPlayerHuman) {
		togglePlayerBtn.set_label("Human");
	}
	else {
		togglePlayerBtn.set_label("Computer");
	}
	view_.eventSetPlayerType(playerPos_, isPlayerHuman);
	std::cout << model_.isSelectedPlayerHuman(0);
}

// void PlayerInfoDisplay::eventTogglePlayerType() {
//     isPlayerHuman_ = !isPlayerHuman_;
//     btnPlayerType.set_label(isPlayerHuman_ ? "Human" : "Computer");
//     view_.eventSetPlayerType(playerIndex_, isPlayerHuman_);
// }

UIPlayerOption::~UIPlayerOption() {}

