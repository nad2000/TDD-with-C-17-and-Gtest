#ifndef BOWLING_H
#define BOWLING_H

class Game
{
private:
	int rolls[21];
	int currentRoll;

public:
	Game();
	virtual ~Game();
	const int score();
	void roll(const int pins);
	const bool isSpare(int frameIndex);
};

#endif /* BOWLING_H */
