#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <string>
#include <map>

class Checkout
{
private:
	
protected:
	struct Distcount{
		int numberOfItems;
		int discountPrice;
	};
	std::map<std::string, int> prices;
	std::map<std::string, Distcount> distcounts;
	std::map<std::string, int> items;

public:
	void addItemPrice(std::string item, int price);
	void addItem(std::string item);
	void addDiscount(std::string item, int numberOfItems, int discountPrice);
	int calculateItem(std::string item, int count);
	int calculateItemDiscount(
		std::string item, int count, const Distcount& discount);
	int getTotal();
	Checkout();
	virtual ~Checkout();

	// Until https://en.cppreference.com/w/cpp/container/map/contains
	// gets implemented:
	const bool containsItem(const std::string item);
};

#endif /* CHECKOUT_H */
