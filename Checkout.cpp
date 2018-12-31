#include "Checkout.hpp"
#include <iostream>

using namespace std;

Checkout::Checkout(): total(0) {};
Checkout::~Checkout() {};

void Checkout::addItemPrice(std::string item, int price) {
	prices[item] = price;
}

void Checkout::addItem(std::string item) {
	items[item]++;
}

int Checkout::getTotal() {
	int total = 0;
	for (auto const &[item, count]: items) {
		auto discount = distcounts[item];
		if (discount.numberOfItems && count >= discount.numberOfItems) {
			total += 
				(count / discount.numberOfItems ) * discount.discountPrice
				+ prices[item] * (count % discount.numberOfItems);
		} else {
			total += prices[item] * count;
		}
	}
	return total;
}

void Checkout::addDiscount(std::string item, int numberOfItems, int discountPrice) {
	distcounts[item] = {numberOfItems, discountPrice};
}
