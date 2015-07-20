#include "View.h"
#include <string>


// Since widgets cannot be shared, must use pixel buffers to share images.
View::View(Game& model, Controller& controller) : vbox(false, 3), model_(model), controller_(controller), playerHandLbl("Current player's hand:") {

	menu = new UIMenu(*this);
	tableCards = new UITableCards(*this, model);
	playerMenu = new UIPlayerOptions(*this, model);
	playerCards = new UIPlayerCards(*this, model);

	// Sets the border width of the window.
	set_border_width(10);

	// Add the VBox to the window
	add(vbox);
	// Add UI elements
	vbox.add(*menu);
	vbox.add(*tableCards);
	vbox.add(*playerMenu);
	vbox.add(playerHandLbl);
	vbox.add(*playerCards);

	// The final step is to display this newly created widget.
	show_all();

	model_.subscribe(this);
} // View::View


// View will access the controller for appropriate function after each UIelements call it
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

// Next 3 functions are responsible for the dialog (popup)

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
