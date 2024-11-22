#include "blackjack.h"
#include <iostream>

Blackjack::Blackjack(std::string name) : player(Player(name)), dealer(Player("dealer")) {
	deck.shuffle();
}

int Blackjack::computeScore(const std::vector<Card*>& cards) {
	int score = 0;
	int countAs = 0;

	for (Card* card : cards) {
		int value = card->getValue();
		if (value == 1) {
			score += 11;
			countAs++;
		}
		else {
			score += value;
		}
	}

	while (score > 21 && countAs > 0) {
		score -= 10;
		countAs--;
	}

	return score;
}

void Blackjack::printScore() const {
	std::cout << "Your current score is: " << player.computeScore(Blackjack::computeScore) << std::endl;
}

void Blackjack::play() {
	player.addCard(deck.drawCard());
	player.addCard(deck.drawCard());
	player.revealHand();
	std::cout << std::endl;

	printScore();

	dealer.addCard(deck.drawCard());
	dealer.revealHand();
	std::cout << "+ Unrevealed card" << std::endl;
	dealer.addCard(deck.drawCard());

	playerTurn();
	if (player.computeScore(Blackjack::computeScore) < 21) {
		dealerTurn();
	}
	getWinner();
}

void Blackjack::playerTurn() {
	char choice = 'h';
	while (choice == 'h') {
		std::cout << "Hit (h) or Rest (r)? ";
		std::cin >> choice;
		std::cout << std::endl;
		choice = tolower(choice);
		if (choice == 'h') {
			player.addCard(deck.drawCard());
			player.revealHand();
			std::cout << std::endl;
			int score = player.computeScore(Blackjack::computeScore);
			printScore();
			if (score > 21) {
				std::cout << "BUST!" << std::endl;
				choice = 'r';
			}
		}
		else if (choice != 'r') {
			choice = 'h';
			std::cout << "Enter a valid answer!" << std::endl;
		}
	}
}

void Blackjack::dealerTurn() {
	dealer.revealHand();
	std::cout << std::endl;
	while (dealer.computeScore(Blackjack::computeScore) < 17) {
		dealer.addCard(deck.drawCard());
		dealer.revealHand();
		std::cout << std::endl;
	}
}

void Blackjack::getWinner() const {
	int scorePlayer = player.computeScore(Blackjack::computeScore);
	int scoreDealer = dealer.computeScore(Blackjack::computeScore);

	if (scorePlayer > 21) {
		std::cout << "The dealer's score is: " << scoreDealer << std::endl;
		std::cout << player.getName() << " loses!" << std::endl;
	}
	else if (scorePlayer == 21) {
		std::cout << "BLACKJACK!" << std::endl;
		std::cout << player.getName() << " wins!" << std::endl;
	}
	else if (scoreDealer > 21 || scorePlayer > scoreDealer) {
		std::cout << "The dealer's score is: " << scoreDealer << std::endl;
		std::cout << player.getName() << " wins!" << std::endl;
	}
	else {
		std::cout << "The dealer's score is: " << scoreDealer << std::endl;
		std::cout << player.getName() << " loses!" << std::endl;
	}
}