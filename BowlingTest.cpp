#include <iostream>
#include <gtest/gtest.h>
#include "Bowling.hpp"

using namespace std;

class GameTests: public ::testing::Test {
protected:
	Game g;
	void rollMany(int n, int pins) {
		for (auto i=0; i < n; ++i) g.roll(pins);
	}
	void rollSpare() {
		g.roll(5);
		g.roll(5);
	}
};

TEST_F(GameTests, CanRoll){
	g.roll(0);
}

TEST_F(GameTests, gutterGame){
	rollMany(20, 0);
	ASSERT_EQ(g.score(), 0);
}

TEST_F(GameTests, allOnes){
	rollMany(20, 1);
	ASSERT_EQ(g.score(), 20);
}

TEST_F(GameTests, spare){
	rollSpare();
	g.roll(3);
	rollMany(17, 0);
	ASSERT_EQ(g.score(), 16);
}

TEST_F(GameTests, oneStrike){
	g.roll(10);
	g.roll(3);
	g.roll(4);
	rollMany(16, 0);
	ASSERT_EQ(g.score(), 24);
}

TEST_F(GameTests, perfectGame){
	rollMany(12, 10);
	ASSERT_EQ(g.score(), 300);
}

TEST_F(GameTests, CanGetScore){
	auto s = g.score();
	ASSERT_EQ(s, 0);
}

/* int main(int argc, char *argv[]) */
/* { */
/* 	::testing::InitGoogleTest(&argc, argv); */
/* 	return RUN_ALL_TESTS(); */
/* } */
