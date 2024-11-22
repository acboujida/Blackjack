#pragma once

#include <vector>
#include "card.h"

class Deck {
	std::vector<Card*> cards;
public:
	Deck();
	void shuffle();
	Card* drawCard();
	~Deck();
};