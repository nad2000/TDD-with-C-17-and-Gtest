#ifndef BOWLING_H
#define BOWLING_H

class Game
{
private:
	int _score;
	int rolls[21];
	int currentRoll;

public:
	Game();
	virtual ~Game();
	const int score();
	void roll(const int pins);

};

#endif /* BOWLING_H */
