// //
// //  UIPlayerOptions.cc
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#include <gtkmm.h>
#include <string>
#include "UIPlayerOptions.h"

UIPlayerOptions::UIPlayerOptions(View& view, Game& model) : view_(view), model_(model) {
	this->set_spacing(3);
	for (int i = 0; i < 4; ++i) {
		playerFrames[i].set_label("Player " + std::to_string(i+1));
		add(playerFrames[i]);
		playerOptions[i] = new UIPlayerOption(view_, model_, i);
		playerFrames[i].add(*playerOptions[i]);
		Gdk::Color gray("gray");
		playerFrames[i].modify_bg(Gtk::STATE_NORMAL, gray);
		// playerFrames[i].override_color(gray, Gtk::STATE_NORMAL);
	}
}

// update each UI element for each player
void UIPlayerOptions::update() {
	std::cerr<<"Updating options"<<std::endl;
	int currPlayerIndex = model_.getCurrentPlayer();
	Gdk::Color green("green");
	Gdk::Color gray("gray");
	for (int i = 0; i < 4; ++i) {
		playerOptions[i]->update();
		std::cerr<<"We're at player "<<i<<std::endl;
		if (i == currPlayerIndex) {
			std::cerr<<"Set something to green"<<std::endl;
			playerFrames[currPlayerIndex].modify_bg(Gtk::STATE_NORMAL, green);
		}
		else {
			std::cerr<<"Set something to gray"<<std::endl;
			playerFrames[i].modify_bg(Gtk::STATE_NORMAL, gray);
		}
	}
}

UIPlayerOptions::~UIPlayerOptions() {
	for (int i = 0; i < 4; ++i) {
		delete playerOptions[i];
	}
}

