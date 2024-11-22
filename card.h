#pragma once

#include <string>

class Card {
public:
	enum Colour { HEART, DIAMOND, PIKE, CLOVER };

	Card(int, Colour);

	int getValue() const;
	Colour getColour() const;

	std::string getName() const;
private:
	int value;
	Colour colour;
};