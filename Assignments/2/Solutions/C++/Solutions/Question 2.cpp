/*
   Muhammad Waqas Shahid Khan
   22I - 2469
   BS SE-E
*/

#include <iostream>

using namespace std;

class Pizza
{
private:
	char* name;
	char* topping;
	char* size;
	bool is_ready;
	double price;

public:
	Pizza()
	{
		name = NULL;
		topping = NULL;
		size = NULL;
		is_ready = false;
		price = 0;
	}

	Pizza(char* toppingVal, double priceVal)
	{
		name = NULL;
		topping = toppingVal;
		size = NULL;
		is_ready = false;
		price = priceVal;
	}

	Pizza(char * toppingVal , double priceVal , char*nameVal , char*sizeVal , bool ready_status)
	{
		name = nameVal;
		topping = toppingVal;
		size = sizeVal;
		is_ready = ready_status;
		price = priceVal;
	}

	Pizza(const Pizza& pizza)
	{
		this->name = name;
		this->topping = topping;
		this->size = size;
		this->is_ready = is_ready;
		this->price = price;
	}

	void setTopping(char* toppingVal)
	{
		topping = toppingVal;
	}

	void setPrice(double priceVal)
	{
		while (priceVal<0)
		{
			cout << "Price cannot be negative! Enter Again : ";
			cin >> priceVal;
		}
		price = priceVal;
	}

	void setName(char* nameVal)
	{
		name = nameVal;
	}

	void setSize(char* sizeVal)
	{
		size = sizeVal;
	}

	void makePizza()
	{
		if (topping != NULL)
		{
			is_ready = true;
		}
		else
		{
			is_ready = false;
		}
	}

	bool check_status()
	{
		if (is_ready == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};

int main()
{
	Pizza obj;
	obj.makePizza();
	cout<<obj.check_status();



	return 0;
}
