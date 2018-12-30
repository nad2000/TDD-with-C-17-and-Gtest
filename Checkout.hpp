#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <string>

class Checkout
{
private:
	

public:
	void addItemPrice(std::string item, int price);
	void addItem(std::string item);
	Checkout();
	virtual ~Checkout();
};

#endif /* CHECKOUT_H */
