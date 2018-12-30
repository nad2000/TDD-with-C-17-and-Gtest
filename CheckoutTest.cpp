// RUN:
// clang++ -O3 -std=c++17 Checkout.cpp CheckoutTest.cpp -lgtest -lgtest_main  -o test -pthread ; ./test
#include <iostream>
#include <gtest/gtest.h>
#include "Checkout.hpp"

using namespace std;

class CheckoutTests: public ::testing::Test {
protected:
	Checkout co;
};

TEST_F(CheckoutTests, CanAddAnItemPrice){
	Checkout co;
	co.addItemPrice("a", 1);
}

TEST_F(CheckoutTests, CanAddAnItem){
	Checkout co;
	co.addItem("a");
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
