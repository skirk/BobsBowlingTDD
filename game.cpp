#include "game.h"

Game::Game()
	: m_currentRoll(0), m_rolls{0}
{

}

void Game::roll(int pins)
{
	m_rolls[m_currentRoll++] = pins;

}

int Game::score()
{
	int score = 0;
	int frames = 10;
	for (int frame = 0, frameIndex = 0; frame < frames; frame++)
	{
		int frameIndexIncrement = 2;
		if (isStrike(frameIndex))
		{
			score += 10 + getStrikeBonus(frameIndex);
			frameIndexIncrement = 1;
		}
		else if (isSpare(frameIndex))
		{
			score += 10 +  getSpareBonus(frameIndex);
		}
		else
		{
			score += getFrameScore(frameIndex);
		}
		frameIndex += frameIndexIncrement;
	}
	return score;

}

bool Game::isSpare(int frameIndex)
{
	return  10 == (m_rolls[frameIndex] + m_rolls[frameIndex+1]);
}

bool Game::isStrike(int frameIndex)
{
	return  10 == m_rolls[frameIndex];
}

int Game::getFrameScore(int frameIndex)
{
	return (m_rolls[frameIndex] + m_rolls[frameIndex+1]);
}

int Game::getSpareBonus(int frameIndex)
{
	return m_rolls[frameIndex+2];
}
int Game::getStrikeBonus(int frameIndex)
{
	return m_rolls[frameIndex+1] + m_rolls[frameIndex+2];
}
