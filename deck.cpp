#include "deck.h"
#include <algorithm>
#include <random>

Deck::Deck() {
	for (int colour=0; colour<4; colour++) {
		for (int value = 1; value < 14; value++) {
			cards.push_back(new Card(value, static_cast<Card::Colour>(colour)));
		}
	}
}

void Deck::shuffle() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(cards.begin(), cards.end(), g);
}

Card* Deck::drawCard() {
	if (cards.empty()) return nullptr;
	Card* card = cards.back();
	cards.pop_back();

	return card;
}

Deck::~Deck() {
	for (Card* card : cards) {
		delete card;
	}
	cards.clear();
}