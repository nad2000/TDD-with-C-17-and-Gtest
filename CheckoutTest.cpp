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
	co.addItemPrice("a", 1);
}

TEST_F(CheckoutTests, CanAddAnItem){
	co.addItem("a");
}

TEST_F(CheckoutTests, CanCalculateTotal){
	co.addItemPrice("a", 1);
	co.addItem("a");
	auto total = co.getTotal();
	ASSERT_EQ(total, 1);
}

TEST_F(CheckoutTests, CanCalculateTotalForMultiple){
	co.addItemPrice("a", 1);
	co.addItemPrice("b", 2);
	co.addItem("a");
	co.addItem("b");
	auto total = co.getTotal();
	ASSERT_EQ(total, 3);
}

TEST_F(CheckoutTests, CanAddDiscount){
	co.addDiscount("a", 3, 2);
}

TEST_F(CheckoutTests, CanCalculateTotalWithDiscount){
	co.addItemPrice("a", 1);
	co.addDiscount("a", 3, 2);
	co.addItem("a");
	co.addItem("a");
	co.addItem("a");
	auto total = co.getTotal();
	ASSERT_EQ(total, 2);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
