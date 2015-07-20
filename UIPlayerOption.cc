// //
// //  UIPlayerOption.cc
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //
#include <string>
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

	// (*this).property_shadow_type.set_value(Gtk::ShadowType::SHADOW_ETCHED_IN);

	// GdkColor blue = {0, 0x0000, 0x0000, 0xffff};
 //    gtk_widget_modify_bg(this, GTK_STATE_NORMAL, &blue);

	// Gdk::Color frameColor("yellow");
 //    modify_bg(Gtk::STATE_NORMAL, frameColor);

	// appropriate even handlers based on buttons pressed
	rageQuitBtn.signal_clicked().connect(sigc::mem_fun(view, &View::eventRageQuit));
    togglePlayerBtn.signal_clicked().connect(sigc::mem_fun(*this, &UIPlayerOption::togglePlayerType));
}

void UIPlayerOption::update(){
	// Disable switching player type if game is running
	togglePlayerBtn.set_sensitive(model_.isGameRunning() ? false : true);
	// set ragequit button status
	rageQuitBtn.set_sensitive(model_.canRageQuit(playerPos_));
	togglePlayerBtn.set_label(model_.isSelectedPlayerHuman(playerPos_) ? "Human": "Computer");
	pointsLbl.set_label("Points: " + std::to_string(model_.getPlayerPoints(playerPos_)));
	discardsLbl.set_label("Discards: " + std::to_string(model_.getDiscardedCards(playerPos_).size()));

}

// switch between player and human
void UIPlayerOption::togglePlayerType() {
	isPlayerHuman = !isPlayerHuman;
	if (isPlayerHuman) {
		togglePlayerBtn.set_label("Human");
	}
	else {
		togglePlayerBtn.set_label("Computer");
	}
	view_.eventSetPlayerType(playerPos_, isPlayerHuman);
}

UIPlayerOption::~UIPlayerOption() {}

