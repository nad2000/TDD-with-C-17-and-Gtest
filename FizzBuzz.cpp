#include <iostream>
#include <gtest/gtest.h>

std::string fizzBuzz(int v) {
	if (v == 1) return "1";
	else if (v == 2) return "2";
}

TEST(FizzBuzzTest, canCallFizzBuzz) {
	auto result = fizzBuzz(1);
}

TEST(FizzBuzzTest, returns1With1PassedIn) {
	auto result = fizzBuzz(1);
	ASSERT_STREQ(result.c_str(), "1");
}

TEST(FizzBuzzTest, returns2With2PassedIn) {
	auto result = fizzBuzz(2);
	ASSERT_STREQ(result.c_str(), "2");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
