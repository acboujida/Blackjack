#include <iostream>
#include "deck.h"
#include "player.h"
#include "blackjack.h"

int main(int argc, char* argv[]) {
	std::string name;
	std::cout << "ENTER YOUR NAME: ";
	std::cin >> name;
	bool on = true;

	while (on) {
		Blackjack blackjack(name);
		blackjack.play();

		char retry = 0;
		while (retry != 'y' && retry != 'n') {
			std::cout << "Would you like to retry? Yes(y) or No(n) : ";
			std::cin >> retry;
			std::cout << std::endl;
			retry = tolower(retry);
			if (retry == 'n') on = false;
			else if (retry != 'y') {
				std::cout << "Enter a valid answer!" << std::endl;
			}
		}
	}
}