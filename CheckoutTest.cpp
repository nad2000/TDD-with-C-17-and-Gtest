#include <iostream>
#include <gtest/gtest.h>
#include "Checkout.hpp"

using namespace std;

TEST(CheckoutTests, CanInstantiateCheckout){
	Checkout co;
}

TEST(CheckoutTests, CanAddAnItemPrice){
	Checkout co;
	co.addItemPrice("a", 1);
}

TEST(CheckoutTests, CanAddAnItem){
	Checkout co;
	co.addItem("a");
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
