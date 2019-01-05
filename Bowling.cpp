#include "Bowling.hpp"

Game::Game(): rolls{0}, currentRoll(0) {}
Game::~Game() {}
void Game::roll(const int pins) {rolls[currentRoll++] = pins;}
const int Game::score() {
	int s = 0, i = 0;
	for (int frame = 0; frame < 10; ++frame) {
		if (isSpare(i)) s += 10 + rolls[i+2];
		else s += rolls[i] + rolls[i+1];
		i += 2;
	}
	return s;
}
const bool Game::isSpare(int frameIndex) {
	return rolls[frameIndex] + rolls[frameIndex + 1] == 10;
}

