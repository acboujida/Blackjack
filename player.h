#pragma once

#include <vector>
#include "card.h"

class Player {
	std::vector<Card*> hand;
	std::string name;
public:
	Player(std::string);
	void setName(std::string);
	std::string getName() const;
	void addCard(Card* card);
	void revealHand() const;
	int computeScore(int (*scoringFunc)(const std::vector<Card*>&)) const;
};