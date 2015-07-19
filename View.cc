#include "View.h"
#include <string>

// Sets the horizontal box to have homogeneous spacing (all elements are of the same size), and to put 10 pixels
// between each widget. Initializes the pixel buffer for the null place holder card, and the 10 of spades.
// Puts a frame in the window, and lays out the widgets horizontally. Four widgets are images, the fifth is a button
// with an image in it.
//
// Since widgets cannot be shared, must use pixel buffers to share images.
View::View(Game& model, Controller& controller) : vbox(false, 3), model_(model), controller_(controller), playerHandLbl("Current player's hand:") {

	menu = new UIMenu(*this);
	tableCards = new UITableCards(*this, model);
	playerMenu = new UIPlayerOptions(*this, model);
	playerCards = new UIPlayerCards(*this, model);

	// const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();
	// const Glib::RefPtr<Gdk::Pixbuf> cardPixbuf     = deck.getCardImage( TEN, SPADE );

	// Sets the border width of the window.
	set_border_width(10);

	// Set the look of the frame.
	// frame.set_label("Straights");
	// frame.set_label_align( Gtk::ALIGN_CENTER, Gtk::ALIGN_TOP );
	// frame.set_shadow_type( Gtk::SHADOW_ETCHED_OUT );

	// Add the frame to the window. Windows can only hold one widget, same for frames.
	add(vbox);
	vbox.add(*menu);

	//vbox.add(*menu);
	// menu.add(startGame);
	// menu.add(entry);
	// menu.add(endGame);
	// vbox.add(button);
	// vbox.add(entry);

	// Add the horizontal box for laying out the images to the frame.


	 vbox.add(*tableCards);


	// for (int i = 0; i < 4; i++) {
	// 	vbox.add(hbox[i]);

	// 	// Initialize 4 empty cards and place them in the box.
	// 	for (int j = 0; j < 13; j++ ) {
	// 		card[i] = new Gtk::Image(deck.getCardImage((Rank)j, (Suit)i));
	// 		hbox[i].set_spacing(10);
	// 		hbox[i].add(*card[i]);
	// 	} // for
	// }



	vbox.add(*playerMenu);
	vbox.add(playerHandLbl);
	vbox.add(*playerCards);



	// Initialize the 5th card and place the image into the button.
	// card[4] = new Gtk::Image( cardPixbuf );
	// button.set_image( *card[4] );

	// Add the button to the box.

	// The final step is to display this newly created widget.
	show_all();

	model_.subscribe(this);
} // View::View

void View::startNewGame(std::string seed) {
    controller_.eventNewGame(seed);
}

void View::endGame() {
    controller_.eventEndGame();
}

void View::eventRageQuit() {
    controller_.eventRageQuit();
}

void View::eventCardSelect(Card* card) {
    controller_.eventCardSelect(card);
}

void View::eventSetPlayerType(int playerPos, bool isPlayerHuman) {
    controller_.eventSetPlayerType(playerPos, isPlayerHuman);
}

void View::update() {
	tableCards->update();
	playerMenu->update();
	playerCards->update();
	updateDiolog();
}

void View::updateDiolog(){
    if (model_.isGameOver()){
        if (model_.addAllPlayerPoints() >= 0){
            updateGameOver();
        }else{
            updateRoundComplete();
        }
    }
}

void View::updateRoundComplete() {
    std::string output;

    for (int i = 0; i < 4; ++i) {
            output += "Player " + std::to_string(i + 1) + "'s score: "
                     + std::to_string(model_.getPlayerTotalPoints(i)) + " + " + std::to_string(model_.getPlayerPoints(i))
                    + " = " + std::to_string(model_.getPlayerTotalPoints(i) + model_.getPlayerPoints(i)) + "\n";
    }

    Gtk::MessageDialog popUp(*this, output);
    popUp.run();
}


void View::updateGameOver() {

    if (model_.isGameOver()){
        std::string output;
        int winner = model_.addAllPlayerPoints();
        if (winner < 0)
            return;
    for (int i = 0; i < 4; ++i) {
            output += "Player " + std::to_string(i + 1) + "'s score: "
                     + std::to_string(model_.getPlayerTotalPoints(i)) + " + " + std::to_string(model_.getPlayerPoints(i))
                    + " = " + std::to_string(model_.getPlayerTotalPoints(i) + model_.getPlayerPoints(i)) + "\n";
    }
        output += "Player " + std::to_string(winner + 1) + " wins!" + "\n";
        Gtk::MessageDialog popUp(*this, output);
        popUp.run();
    }
}

View::~View() {
	for (int i = 0; i < 52; i++ ) {
		delete card[i];
	}
	delete menu;
	delete tableCards;
	delete playerMenu;
	delete playerCards;
} // View::~View()
