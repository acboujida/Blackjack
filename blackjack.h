#pragma once

#include "card.h"
#include <vector>
#include "player.h"
#include "deck.h"

class Blackjack {
	Player player;
	Player dealer;
	Deck deck;

	void playerTurn();
	void dealerTurn();
	void getWinner() const;
	void printScore() const;

public:
	static int computeScore(const std::vector<Card*>&);

	Blackjack(std::string);
	void play();
};