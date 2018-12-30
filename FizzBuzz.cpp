// Run tests with:
// ~/Dropbox/udemy/test-driven-development-in-c (master)$ clang++ -O3 -std=c++17 FizzBuzz.cpp -lgtest -lgtest_main  -o test -pthread ; ./test
#include <iostream>
#include <gtest/gtest.h>

inline const bool isMultiple(int value, int base) {
	return value % base == 0;
}

std::string fizzBuzz(int v) {
	if (isMultiple(v, 3)) {
		if (isMultiple(v, 5)) return "FizzBuzz"; 
		else return "Fizz";
	}
	if (isMultiple(v, 5)) return "Buzz";
	return std::to_string(v);
}

void checkFizzBuzz(int value, std::string expectedResult) {
	std::string result = fizzBuzz(value);
	ASSERT_STREQ(expectedResult.c_str(), result.c_str());
}

TEST(FizzBuzzTest, canCallFizzBuzz) {
	auto result = fizzBuzz(1);
}

TEST(FizzBuzzTest, returns1With1PassedIn) {
	checkFizzBuzz(1, "1");
}

TEST(FizzBuzzTest, returns2With2PassedIn) {
	checkFizzBuzz(2, "2");
}

TEST(FizzBuzzTest, returnsFizzWith3PassedIn) {
	checkFizzBuzz(3, "Fizz");
}

TEST(FizzBuzzTest, returnsBuzzWith5PassedIn) {
	checkFizzBuzz(5, "Buzz");
}

TEST(FizzBuzzTest, returnsFizzWith6PassedIn) {
	checkFizzBuzz(6, "Fizz");
	checkFizzBuzz(9, "Fizz");
	checkFizzBuzz(12, "Fizz");
	checkFizzBuzz(18, "Fizz");
	checkFizzBuzz(21, "Fizz");
	checkFizzBuzz(24, "Fizz");
}

TEST(FizzBuzzTest, returnsBuzzWith10PassedIn) {
	checkFizzBuzz(10, "Buzz");
	checkFizzBuzz(20, "Buzz");
	checkFizzBuzz(25, "Buzz");
	checkFizzBuzz(35, "Buzz");
	checkFizzBuzz(5555, "Buzz");
}

TEST(FizzBuzzTest, returnsFizzBuzzWith15PassedIn) {
	checkFizzBuzz(15, "FizzBuzz");
	checkFizzBuzz(30, "FizzBuzz");
	checkFizzBuzz(60, "FizzBuzz");
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
