#include "player.h"
#include <iostream>

Player::Player(std::string name) : name(name) {}

void Player::setName(std::string name) {
	this->name = name;
}

void Player::addCard(Card* card) {
	hand.push_back(card);
}

int Player::computeScore(int (*scoringFunc)(const std::vector<Card*>&)) const {
	return scoringFunc(hand);
}

void Player::revealHand() const {
	std::cout << name << "'s cards are: ";
	for (Card* card : hand) {
		std::cout << "+ " << card->getName() << "  ";
	}
}

std::string Player::getName() const {
	return name;
}