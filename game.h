#pragma once

#include <array>

class Game
{
public:
	Game();
	void roll(int pins);
	int score();
protected:
	std::array<int, 21> m_rolls;
	int m_currentRoll;

	bool isSpare(int frameIndex);
	bool isStrike(int frameIndex);
	int getFrameScore(int frameIndex);
	int getSpareBonus(int frameIndex);
	int getStrikeBonus(int frameIndex);

};
