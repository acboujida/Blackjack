#include "card.h"

Card::Card(int value, Colour colour) : value(value), colour(colour) {}

int Card::getValue() const {
	return value;
}

Card::Colour Card::getColour() const {
	return colour;
}

std::string Card::getName() const {
	std::string numbers[] = { "As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
	std::string colours[] = { "Heart", "Diamond", "Pike", "Clover" };

	return numbers[value-1] + " of " + colours[colour];
}