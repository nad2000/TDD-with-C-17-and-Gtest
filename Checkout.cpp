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

int Checkout::calculateItem(std::string item, int count) {
	auto discount = distcounts[item];
	if (discount.numberOfItems && count >= discount.numberOfItems) {
		return calculateItemDiscount(item, count, discount);
	} else {
		return prices[item] * count;
	}
}

int Checkout::calculateItemDiscount(std::string item, int count, const Distcount& discount) {
	return
		(count / discount.numberOfItems ) * discount.discountPrice
		+ prices[item] * (count % discount.numberOfItems);
}


int Checkout::getTotal() {
	int total = 0;
	for (auto const &[item, count]: items) {
		total += calculateItem(item, count);
	}
	return total;
}

void Checkout::addDiscount(std::string item, int numberOfItems, int discountPrice) {
	distcounts[item] = {numberOfItems, discountPrice};
}
