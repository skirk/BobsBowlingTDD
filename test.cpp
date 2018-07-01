#include <gtest/gtest.h>
#include "game.h"

class BowlingGameTests : public ::testing::Test
{
public:
	void rollMany(int n, int pins)
	{
		for (int i = 0; i < n; i++)
		{
			g.roll(pins);
		}
	}

	void rollSpare()
	{
		g.roll(5);
		g.roll(5);
	}
	void rollStrike()
	{
		g.roll(10);
	}
protected:
	Game g;
};

TEST_F(BowlingGameTests, testAllZeros)
{
	rollMany(20, 0);
	ASSERT_EQ(0, g.score());
}


TEST_F(BowlingGameTests, testAllOnes)
{
	rollMany(20, 1);
	ASSERT_EQ(20, g.score());
}

TEST_F(BowlingGameTests, testOneSpare)
{
	rollSpare();
	g.roll(3);
	rollMany(17, 0);
	ASSERT_EQ(16, g.score());
}

TEST_F(BowlingGameTests, testOneStrike)
{
	rollStrike();
	g.roll(3);
	g.roll(4);
	rollMany(16, 0);
	ASSERT_EQ(24, g.score());
}

TEST_F(BowlingGameTests, testPerfectGame)
{
	rollMany(21, 10);
	ASSERT_EQ(300, g.score());


