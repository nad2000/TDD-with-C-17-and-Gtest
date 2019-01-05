#include "Bowling.hpp"

Game::Game(): _score(0), rolls{0}, currentRoll(0) {}
Game::~Game() {}
void Game::roll(const int pins) {_score += pins; rolls[currentRoll++] = pins;}
const int Game::score() {
	int s = 0, i = 0;
	for (int frame = 0; frame < 10; ++frame) {
		auto r1 = rolls[i], r2 = rolls[i+1];
		if (r1 + r2 == 10) s += 10 + rolls[i+2];
		else s += r1 + r2;
		i += 2;
	}
	return s;
}

