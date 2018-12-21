#include <iostream>
#include <gtest/gtest.h>

std::string fizzBuzz(int v) {
	return "";
}

TEST(FizzBuzzTest, canCallFizzBuzz) {
	auto result = fizzBuzz(1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
