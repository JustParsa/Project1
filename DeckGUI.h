/*
 *  Deck.h
 *
 * Loads a series of pixmaps used for displaying the cards, as well as a card back used as a place marker in the
 * display when we don't have a card yet to display. Use pixel buffers to share images since widgets cannot be
 * shared.
 *
 *  Created by Caroline Kierstead on 25/05/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */
#ifndef __DECK_GUI_H
#define __DECK_GUI_H
#include <gdkmm/pixbuf.h>
 // #include <gtkmm.h>
#include <vector>
#include "Card.h"
using std::vector;


// Enumerated types to define the face and suit values.
// enum Suit { CLUB, DIAMOND, HEART, SPADE, SUIT_COUNT };
// enum Rank {
// 	ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
// 	EIGHT, NINE, TEN, JACK, QUEEN, KING, RANK_COUNT
// };

class DeckGUI {
public:
	DeckGUI();
	virtual ~DeckGUI();
	Glib::RefPtr<Gdk::Pixbuf> getCardImage(Rank r, Suit s);   // Returns the image for the specified card.
	Glib::RefPtr<Gdk::Pixbuf> getNullCardImage();                 // Returns the image to use for the placeholder.
	// const Gtk::Image* getImage(Rank, Suit);
	// Gtk::Image *cardImages[52];
private:
	vector< Glib::RefPtr< Gdk::Pixbuf > > deck;                   // Contains the pixel buffer images.

}; // DeckGUI
#endif
