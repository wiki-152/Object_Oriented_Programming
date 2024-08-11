//Waqas_22i2469
#pragma once

/*
   Muhammad Waqas Shahid Khan
   22I - 2469
   BS SE-E
*/

#include <iostream>
#include <string>
#include<stdlib.h>
#include<windows.h>

using namespace std;

class Product
{
public:
	Product(string n, int q , double p);

	string getName();
	void setName(string input);

	int getQuantity();
	void setQuantity(int input);

	double getPrice();
	void setPrice(double input);

	~Product();

private:
	string name;
	int quantity;
	double price;
};

Product::Product(string n="-", int q = -1, double p = -1)
{
	name = n;
	quantity = q;
	price = p;
}

string Product:: getName()
{
	return name;
}

void Product:: setName(string input)
{
	name = input;
}

int Product:: getQuantity()
{
	return quantity;
}

void Product::setQuantity(int input)
{
	quantity = input;
}

double Product::getPrice()
{
	return price;
}

void Product::setPrice(double input)
{
	price = input;
}

Product::~Product()
{
}



// ------------------------------------------ Supplier ------------------------------------------

class Supplier
{
public:
	Supplier(string n , Product * ptr , int nop , int o , int in);

	string getName();
	void setName(string input);

	Product* getSupplyProducts();
	void setSupplyProducts(Product* input);

	int getNumberOfProducts();
	void setNumberOfProducts(int input);

	int getOrders();
	void setOrders(int input);

	int getIndex();
	void setIndex(int input);

	~Supplier();

private:
	string name;
	Product* supplyProducts;
	int numberOfProducts;
	int Order;
	int index;
};

Supplier::Supplier(string n="-", Product* ptr=NULL, int nop=0, int oa=0 , int in=-1)
{
	name = n;
	supplyProducts = ptr;
	numberOfProducts = nop;
	Order = 0;
	index = in;
}

string Supplier::getName()
{
	return name;
}

void Supplier::setName(string input)
{
	name = input;
}

Product* Supplier::getSupplyProducts()
{
	return supplyProducts;
}

void Supplier::setSupplyProducts(Product* input)
{
	supplyProducts = input;
}

int Supplier::getNumberOfProducts()
{
	return numberOfProducts;
}

void Supplier::setNumberOfProducts(int input)
{
	numberOfProducts = input;
}

int Supplier::getOrders()
{
	return Order;
}

void Supplier::setOrders(int input)
{
	Order = input;
}

int Supplier::getIndex()
{
	return index;
}

void Supplier::setIndex(int input)
{
	index = input;
}

Supplier::~Supplier()
{
}

// ------------------------------------------ Cart ------------------------------------------

class Cart
{
public:
	Cart(Product * ptr , int n);
	~Cart();

	Product* getProducts();
	void setProducts(Product *input);

	int getNumberOfProducts();
	void setNumberOfProducts(int input);

private:
	Product* products_Customer;
	int numberOfProducts;
};

Cart::Cart(Product* ptr =NULL, int n = 0)
{
	products_Customer = ptr;
	numberOfProducts = n;
}

Product* Cart::getProducts()
{
	return products_Customer;
}

void Cart::setProducts(Product* input)
{
	products_Customer = input;
}

int Cart::getNumberOfProducts()
{
	return numberOfProducts;
}

void Cart::setNumberOfProducts(int input)
{
	numberOfProducts = input;
}

Cart::~Cart()
{
}

// ------------------------------------------ Sale ------------------------------------------

class Sale
{
public:
	Sale();

	Product* getProducts();
	void setProducts(Product *input);

	~Sale();

private:
	Product * products_Sale;
};

Sale::Sale()
{
}

Product* Sale::getProducts()
{
	return products_Sale;
}

void Sale::setProducts(Product *input)
{
	products_Sale = input;
}


Sale::~Sale()
{
}

// ------------------------------------------ Customer ------------------------------------------

class Customer : public Cart
{
public:
	Customer();

	string getName();
	void setName(string input);

	Cart getCustomerCartObj();
	void setCustomerCartObj(Cart input);

	~Customer();

private:
	string name;
	Cart customerCartObj;
};

Customer::Customer()
{
}

string Customer::getName()
{
	return name;
}

void Customer::setName(string input)
{
	name = input;
}

Cart Customer::getCustomerCartObj()
{
	return customerCartObj;
}

void Customer::setCustomerCartObj(Cart input)
{
	customerCartObj = input;
}

Customer::~Customer()
{
}

//------------------------------------------ Inventory Managment Module ------------------------------------------

class IM_Module
{
public:
	IM_Module(Product * ptr , int tp);

	Product* getProducts();
	void setProducts(Product input[]);

	int getTotalProducts();
	void setTotalProducts(int input);

	Product getProductIndex(int input);

	void print();

	void addProduct(Product * newPrododuct, int size); // Add New Product To Inventory 

	void orderProduct(int SupplierCount , Supplier Suppliers[]); // Place Order For Product

	void takeProduct(int SupplierCount, Supplier Suppliers[], int takeOrders); // Take Product From Supplier

	void manageProduct(); // Manage Price / Discounts 

	~IM_Module();

private:
	Product* products_Inventory;
	int totalProducts;
};

IM_Module::IM_Module(Product* ptr =NULL , int tp=0)
{
	products_Inventory = ptr;
	totalProducts = tp;
}

Product* IM_Module::getProducts()
{
	return products_Inventory;
}

Product IM_Module::getProductIndex(int input)
{
	cout<<products_Inventory[input].getName()<<endl;
	return products_Inventory[input];
}

void IM_Module::setProducts(Product input[])
{
	products_Inventory = input;
}

int IM_Module::getTotalProducts()
{
	return totalProducts;
}

void IM_Module::setTotalProducts(int input)
{
	totalProducts = input;
}

void IM_Module::print()
{
	for (int i = 0; i < totalProducts; i++)
	{
		cout << i+1 << ". " << products_Inventory[i].getName() << "\nQuantity : " << products_Inventory[i].getQuantity() << "\nPrice : " << products_Inventory[i].getPrice() << endl << endl;
	}
}

void IM_Module:: addProduct(Product * newProducts , int size)
{
	
	
	Product* newList = new Product[totalProducts + size];

	for (int i = 0; i < totalProducts; i++)
	{
		newList[i] = products_Inventory[i];
	}

	for (int i = totalProducts ; i < totalProducts + size ; i++)
	{
		newList[i] = newProducts[i-totalProducts];
	}

	products_Inventory = newList;
	totalProducts += size;

	for (int i = 0; i < totalProducts ; i++)
	{
		cout << i;
		cout << products_Inventory[i].getName() << endl;
	}

	/*Sleep(10000);*/

	newList = NULL;
}

void IM_Module:: orderProduct(int SupplierCount , Supplier Suppliers[])
{
	system("cls");

	print();

	cout << endl << endl;

	cout << "Enter Product To Order (In Small Letters) : ";
	string name;
	cin >> name;

	int l = 0;
	while (name[l] != '\0')
	{
		if (name[l] >= 'A' && name[l] <= 'Z')
		{
			name[l] = name[l] + 32;
		}
		l++;
	}

	bool find = false;
	int nindex = -1;
	int pindex = -1;

	while (true)
	{
		for (int i = 0; i < SupplierCount; i++)
		{
			for (int j = 0; j < Suppliers[i].getNumberOfProducts(); j++)
			{
				if (name == Suppliers[i].getSupplyProducts()[j].getName())
				{
					find = true;
					nindex = i;
					pindex = j;
					break;
				}
			}
		}
		break;
	}

	if (find == true)
	{
		cout << "Supplier : " << Suppliers[nindex].getName() << endl;
		cout << "Product : " << Suppliers[nindex].getSupplyProducts()[pindex].getName() << endl;
		cout << "Enter Quantity : ";
		int quantity;
		cin >> quantity;
		Suppliers[nindex].setOrders(quantity);
		Suppliers[nindex].setIndex(pindex);

		
	}
	else
	{
		cout << "Product Supplier Not Found! Add Supplier !" << endl;
	}


	
}

void IM_Module::takeProduct(int SupplierCount, Supplier Suppliers[], int takeOrders)
{
	system("cls");
	
	for (int i = 0; i < SupplierCount; i++)
	{
		if (Suppliers[i].getIndex() != -1)
		{
			for (int j = 0; j < Suppliers[i].getNumberOfProducts(); j++)
			{
				if (j == Suppliers[i].getIndex())
				{
					cout << "Take Product : " << Suppliers[i].getSupplyProducts()[j].getName() << " Quantity : " << Suppliers[i].getOrders() << " From Supplier : " << Suppliers[i].getName() << endl;
				}
			}
		}
	}

	if (takeOrders != 0)
	{
		cout << endl << endl << "Enter Product To Take (In Small Letters) : ";
		string name;
		cin >> name;

		int l = 0;
		while (name[l] != '\0')
		{
			if (name[l] >= 'A' && name[l] <= 'Z')
			{
				name[l] = name[l] + 32;
			}
			l++;
		}

		bool find = false;
		int nindex = -1;
		int pindex = -1;

		while (true)
		{
			for (int i = 0; i < SupplierCount; i++)
			{
				pindex = Suppliers[i].getIndex();
				if (pindex != -1)
				{
					for (int j = 0; j < Suppliers[i].getNumberOfProducts(); j++)
					{
						if (name == Suppliers[i].getSupplyProducts()[j].getName())
						{
							for (int k = 0; k < totalProducts; k++)
							{
								if (name == products_Inventory[k].getName())
								{
									products_Inventory[k].setQuantity(products_Inventory[k].getQuantity() + Suppliers[i].getOrders());

									find = true;

									cout << "Enter New Price Of Product : ";
									int in = 0;
									cin >> in;

									products_Inventory[k].setPrice(in);

									Suppliers[i].setIndex(-1);
									Suppliers[i].setOrders(0);
									takeOrders -= 1;
									break;
								}
							}
							break;
						}
					}
				}

			}
			break;
		}
	}
	
}

// ------------------------------------------ Discount ------------------------------------------

class Discount
{
public:
	Discount();

	double getPercentage();
	void setPercentage(double input);

	void RamadanDiscount(IM_Module& IMM);

	void EidDiscount(IM_Module& IMM);

	void IndependenceDayDiscount(IM_Module& IMM);

	void DefenceDayDiscount(IM_Module& IMM);

	void NewYearDiscount(IM_Module& IMM);

	void ChristmasDiscount(IM_Module& IMM);



	~Discount();

private:
	double percentage;
};

Discount::Discount()
{
}

double Discount::getPercentage()
{
	return percentage;
}

void Discount::setPercentage(double input)
{
	percentage = input;
	percentage = percentage / 100;
}

void Discount::RamadanDiscount(IM_Module& IMM)
{

	Product* newList = IMM.getProducts();

	for (int i = 0; i < IMM.getTotalProducts(); i++)
	{
		newList[i].setPrice(newList[i].getPrice() - (newList[i].getPrice() * percentage));
	}

	IMM.setProducts(newList);
	
}

void Discount::EidDiscount(IM_Module& IMM)
{
	Product* newList = IMM.getProducts();
	for (int i = 0; i < IMM.getTotalProducts(); i++)
	{
		newList[i].setPrice(newList[i].getPrice() - (newList[i].getPrice() * percentage));
	}
	IMM.setProducts(newList);
	delete newList;
	newList = NULL;
}

void Discount::IndependenceDayDiscount(IM_Module& IMM)
{
	Product* newList = IMM.getProducts();
	for (int i = 0; i < IMM.getTotalProducts(); i++)
	{
		newList[i].setPrice(newList[i].getPrice() - (newList[i].getPrice() * percentage));
	}
	IMM.setProducts(newList);
	delete newList;
	newList = NULL;
}

void Discount::DefenceDayDiscount(IM_Module& IMM)
{
	Product* newList = IMM.getProducts();
	for (int i = 0; i < IMM.getTotalProducts(); i++)
	{
		newList[i].setPrice(newList[i].getPrice() - (newList[i].getPrice() * percentage));
	}
	IMM.setProducts(newList);
	delete newList;
	newList = NULL;
}

void Discount::NewYearDiscount(IM_Module& IMM)
{
	Product* newList = IMM.getProducts();
	for (int i = 0; i < IMM.getTotalProducts(); i++)
	{
		newList[i].setPrice(newList[i].getPrice() - (newList[i].getPrice() * percentage));
	}
	IMM.setProducts(newList);
	delete newList;
	newList = NULL;
}

void Discount::ChristmasDiscount(IM_Module& IMM)
{
	Product* newList = IMM.getProducts();
	for (int i = 0; i < IMM.getTotalProducts(); i++)
	{
		newList[i].setPrice(newList[i].getPrice() - (newList[i].getPrice() * percentage));
	}
	IMM.setProducts(newList);
	delete newList;
	newList = NULL;
}

Discount::~Discount()
{
}

void IM_Module:: manageProduct()
{
	cout << "1 For Setting New Price" << endl;
	cout << "2 For Applying Discount" << endl;

	int pminput;
	cin >> pminput;

	while (pminput != 1 && pminput != 2)
	{
		cout << "Invalid Input Enter Again : ";
		cin >> pminput;
	}

	if (pminput == 1)
	{
		system("cls");
		cout << "Enter Product Name : ";
		string name;
		cin >> name;
		int l = 0;
		while (name[l] != '\0')
		{
			if (name[l] >= 'A' && name[l] <= 'Z')
			{
				name[l] = name[l] + 32;
			}
			l++;
		}
		bool find = false;
		int index = -1;
		while (true)
		{
			for (int i = 0; i < totalProducts; i++)
			{
				if (name == products_Inventory[i].getName())
				{
					find = true;
					index = i;
					break;
				}
			}
			break;
		}
		if (find == true)
		{
			cout << "Enter New Price : ";
			int price;
			cin >> price;
			products_Inventory[index].setPrice(price);
		}
		else
		{
			cout << "Product Not Found !" << endl;
		}
	}

	if (pminput == 2)
	{
		Discount obj;

		int dinput = 0;

		cout << "1 For Ramadan Discount" << endl;
		cout << "2 For Eid Discount" << endl;
		cout << "3 For Independence Day Discount" << endl;
		cout << "4 For Defence Day Discount" << endl;
		cout << "5 For New Year Discount" << endl;
		cout << "6 For Christmas Discount" << endl;

		cout << endl << "Enter : ";
		cin >> dinput;

		if (dinput == 1)
		{
			obj.setPercentage(50);
			obj.RamadanDiscount(*this);
		}

		if (dinput == 2)
		{
			obj.setPercentage(40);
			obj.EidDiscount(*this);
		}

		if (dinput == 3)
		{
			obj.setPercentage(30);
			obj.IndependenceDayDiscount(*this);
		}

		if (dinput == 4)
		{
			obj.setPercentage(25);
			obj.DefenceDayDiscount(*this);
		}

		if (dinput == 5)
		{
			obj.setPercentage(15);
			obj.NewYearDiscount(*this);
		}

		if (dinput == 6)
		{
			obj.setPercentage(5);
			obj.ChristmasDiscount(*this);
		}
	}
}

IM_Module::~IM_Module()
{
}

// ------------------------------------------ POS Module ------------------------------------------

class POS_Module
{
public:
	POS_Module(Product*ptr , int tpm);

	Product * getProducts();
	void setProducts(Product* input);

	int getTotalProductsManage();
	void setTotalProductsManage(int input);

	void print();

	void addToCart(IM_Module & IMM);

	void applyDiscount();

	void issueRefunds();

	~POS_Module();

private:
	Product* products_Manage;
	int totalProductsManage;
};

POS_Module::POS_Module(Product* ptr=NULL , int tpm=0)
{
	products_Manage = ptr;

	totalProductsManage = tpm;
}

Product* POS_Module::getProducts()
{
	return products_Manage;
}

void POS_Module::setProducts(Product* input)
{
	products_Manage = input;
}

int POS_Module::getTotalProductsManage()
{
	return totalProductsManage;
}

void POS_Module::setTotalProductsManage(int input)
{
	totalProductsManage = input;
}

void POS_Module::print()
{
	for (int i = 0; i < totalProductsManage; i++)
	{
		cout << "Product Name : " << products_Manage[i].getName() << endl;
		cout << "Product Quantity : " << products_Manage[i].getQuantity() << endl;
		cout << "Product Price : " << products_Manage[i].getPrice() << endl;
		cout << endl;
	}
}

void POS_Module::addToCart(IM_Module& IMM)
{
	int newinp = -1;
	int size = totalProductsManage;

	print();

	cout << "1 For Adding Product To Cart" << endl;
	cout << "2 For Removing Product From Cart" << endl;
	

	cin >> newinp;

	while (newinp != 1 && newinp != 2)
	{
		cout << "Invalid Input Enter Again : ";
		cin >> newinp;
	}

	if (newinp == 1)
	{
		size += 1;
		Product* newList = new Product[size];

		for (int i = 0; i < size; i++)
		{
			cout<<"Enter Product Name : ";

			string name;
			cin >> name;

			int l = 0;

			while (name[l] != '\0')
			{
				if (name[l] >= 'A' && name[l] <= 'Z')
				{
					name[l] = name[l] + 32;
				}
				l++;
			}

			bool find = false;

			int index = -1;

			while (true)
			{
				for (int i = 0; i < IMM.getTotalProducts(); i++)
				{
					if (name == IMM.getProducts()[i].getName())
					{
						find = true;
						index = i;
						break;
					}
				}
				break;
			}

			if (find == true)
			{
				newList[i].setName(IMM.getProducts()[index].getName());
				
				cout<<"Enter Quantity : ";
				int quantity;
				cin >> quantity;
				while (quantity <= 0 || quantity > IMM.getProducts()[index].getQuantity())
				{
					cout<< "Invalid Input Enter Again : ";
					cin >> quantity;
				}

				IMM.getProducts()[index].setQuantity(IMM.getProducts()[index].getQuantity() - quantity);
				newList[i].setQuantity(quantity);
				newList[i].setPrice(IMM.getProducts()[index].getPrice()*quantity);
				products_Manage = newList;
				totalProductsManage= size;
				newList = NULL;
			}
			else
			{
				cout << "Product Not Found !" << endl;
			}

		}
	}

	if (newinp == 2)
	{
		if (size >= 1)
		{
			size -= 1;
			Product* newList = new Product[size];
			cout << "Enter Product Name : ";
			string name;
			cin >> name;
			int l = 0;
			while (name[l] != '\0')
			{
				if (name[l] >= 'A' && name[l] <= 'Z')
				{
					name[l] = name[l] + 32;
				}
				l++;
			}
			
			for (int i = 0; i < totalProductsManage ; i++)
			{
				
				bool find = false;
				int index = -1;
				
				if (name == products_Manage[i].getName())
				{
					find = true;
					index = i;
				}

				if (find == true)
				{
					for (int j = 0; j < size; j++)
					{
						if (name != products_Manage[i].getName())
						{
							newList[i] = products_Manage[i];
						}
						else
						{
							IMM.getProducts()[i].setQuantity(IMM.getProducts()[i].getQuantity() + products_Manage[i].getQuantity());
						}
					}


					products_Manage = newList;
					totalProductsManage = size;
					newList = NULL;
				}
				else
				{
					cout << "Product Not Found !" << endl;
				}
			}
		}
		else
		{
			cout << "Cart Is Empty !" << endl;
		}
		
	}
}



POS_Module::~POS_Module()
{
}

// ------------------------------------------ Report Module ------------------------------------------

class R_Module
{
public:
	R_Module();
	
	void saleReport(); // By Product / By Day / By Customer

	void inventoryReport(); // By Product / By Location / By Supplier

	void profitReport(); // By Product / By Day / By Customer

	~R_Module();

private:

};

R_Module::R_Module()
{
}

R_Module::~R_Module()
{

}


