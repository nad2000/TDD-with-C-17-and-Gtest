#include "Checkout.hpp"

Checkout::Checkout(): total(0) {};
Checkout::~Checkout() {};

void Checkout::addItemPrice(std::string item, int price) {
	prices[item] = price;
}

void Checkout::addItem(std::string item) {
	total += prices[item];
}

int Checkout::getTotal() {
	return total;
}
