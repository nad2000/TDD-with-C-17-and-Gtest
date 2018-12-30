#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <string>
#include <map>

class Checkout
{
private:
	
protected:
	std::map<std::string, int> prices;
	int total;

public:
	void addItemPrice(std::string item, int price);
	void addItem(std::string item);
	int getTotal();
	Checkout();
	virtual ~Checkout();
};

#endif /* CHECKOUT_H */
