//Waqas_22i2469
/*
   Muhammad Waqas Shahid Khan
   22I - 2469
   BS SE-E
*/

#include <iostream>
#include <string>
#include<stdlib.h>
#include<windows.h>

#include"C:\Users\mw13s\Desktop\OOP Assignment\Header.h"

using namespace std;



int main()
{
	int placedOrders = 0;
	int takeOrders = 0;
	POS_Module POS;

	Product apples("apple" , 10 , 2.5);
	Product bananas("banana", 10, 1.5);
	Product milkpak("milkpak", 10, 3.5);

	Product list[3] = {apples , bananas , milkpak};

	Product l1[2] = { apples , bananas};
	Product l2[1] = {milkpak };
	Supplier Khan("Khan", l1 ,2);
	Supplier Malik ("Malik", l2 ,1);

	Supplier Suppliers[2] = {Khan , Malik};
	int SupplierCount = 2;

	IM_Module IMM(list, 3);

	/*cout << list[0].getName()<<endl;
	cout << list[1].getName() << endl;
	cout << list[2].getName() << endl;*/

	int input = -1;

	while (input != 3)
	{
		cout << endl << "--------------------------- Welcome ---------------------------" << endl << endl;
		
		cout << "1 : Store Manager" << endl;
		cout << "2 : Store Employee" << endl;
		cout << "3 : Exit" << endl << endl;
		cout << "Input : ";
		cin >> input;
		while (input != 1 && input != 2 && input != 3)
		{
			cout << "Invalid Input Enter Again : ";
			cin >> input;
		}

		while (input == 1) // Manager
		{
			system ("cls");
			cout << "----------------------Important Notifications----------------------" << endl << endl;


			cout << "----------------------Supplier Notifications" << endl << endl;
			for (int i = 0; i < SupplierCount; i++)
			{
				if (Suppliers[i].getIndex() != -1)
				{
					for (int j = 0; j < Suppliers[i].getNumberOfProducts(); j++)
					{
						if (j == Suppliers[i].getIndex())
						{
							cout<< "Take Product : " << Suppliers[i].getSupplyProducts()[j].getName() << " Quantity : " <<  Suppliers[i].getOrders() << " From Supplier : " << Suppliers[i].getName() << endl;
						}
					}
				}
			}

			cout << endl << endl << "----------------------Low Inventory" << endl << endl;
			for (int i = 0; i < IMM.getTotalProducts(); i++)
			{
				if (IMM.getProducts()[i].getQuantity() < 100)
				{
					cout << "Quantity of The Product \"" << IMM.getProducts()[i].getName() << "\" = " << IMM.getProducts()[i].getQuantity() << " is below 100 - Place/Take Order !" << endl;
					
				}
			}

			cout << endl << endl << "----------------------END OF Notifications----------------------" << endl << endl << endl;

			int managerInput = -1;
			cout << "1 : Adding New Product To Inventory" << endl;
			cout << "2 : Order Products" << endl;
			cout << "3 : Taking Products " << endl;
			cout << "4 : Price Management" << endl;
			cout << "5 : Show Inventory Levels" << endl;
			cout << "6 : Show Sales Report" << endl;
			cout<< "7 : Exit" << endl << endl;
			cout << "Input : ";
			cin >> managerInput;

			while (managerInput != 1 && managerInput != 2 && managerInput != 3 && managerInput != 4 && managerInput != 5 && managerInput != 6 && managerInput != 7)
			{
				cout << "Invalid Input Enter Again : ";
				cin >> managerInput;
			}

			if (managerInput == 1)
			{
				/*system("cls");*/
				int num = 0;
				cout<< "Enter Number Of Product(s) To Add : ";
				cin >> num;

				Product *temp = new Product [num];

				for (int i = 0; i < num; i++)
				{
					string name;
					int quantity;
					double price;

					cout << "Product Number " << i + 1 << endl;

					cout << "Enter Name Of Product : ";
					cin >> name;
					cout << "Enter Quantity Of Product : ";
					cin >> quantity;
					cout << "Enter Price Of Product : ";
					cin >> price;

					temp[i].setName(name);
					temp[i].setQuantity(quantity);
					temp[i].setPrice(price);
				}
				
				IMM.addProduct(temp, num);

				delete [] temp;
				temp = NULL;
			}

			while (managerInput == 2)
			{
				IMM.orderProduct(SupplierCount , Suppliers );

				placedOrders += 1;
				takeOrders += 1;

				cout << "Do You Want To Order More Products (Y/N) : ";
				char ch;
				cin >> ch;

				while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
				{
					cout << "Invalid Input Enter Again : ";
					cin >> ch;
				}

				if (ch == 'N' || ch == 'n')
				{
					break;
				}
			}

			while (managerInput == 3)
			{
					if (takeOrders > 0)
					{
						IMM.takeProduct(SupplierCount, Suppliers, takeOrders);
						takeOrders -= 1;
						cout<<"Do You Want To Take More Products (Y/N) : ";
						char ch;
						cin >> ch;

						while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
						{
							cout << "Invalid Input Enter Again : ";
							cin >> ch;
						}

						if (ch == 'N' || ch == 'n')
						{
							break;
						}
					}
					else
					{
						cout << "No Orders To Take !" << endl;
						Sleep(5000);
						break;
					}

			}

			if (managerInput == 4)
			{
				system("cls");

				IMM.manageProduct();
				
				cout << "Do You Want To Apply Any Other Discount (Y/N) : ";
				char ch;
				cin >> ch;

				while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
				{
					cout << "Invalid Input Enter Again : ";
					cin >> ch;
				}

				if (ch == 'N' || ch == 'n')
				{
					break;
				}

			}

			while (managerInput == 5)
			{
				system("cls");

				IMM.print();

				cout << endl << endl;

				cout<<"Enter 0 For Going Back"<<endl;
				int newinp = -1;
				cin >> newinp;

				while (newinp != 0)
				{
					cout<<"Invalid Input Enter Again : ";
					cin >> newinp;
				}

				if (newinp == 0)
				{
					break;
				}
			}

			if (managerInput == 6)
			{
				system("cls");
			}

			if (managerInput == 7)
			{
				input = -1;
			}

		}
		
		while (input == 2) // Employee
		{
			system("cls");
			int employeeInput = -1;

			cout<<"1 For Managing Cart" <<endl;
			cout << "2 For Discounts" << endl;
			cout << "3 For Issuing Refunds" << endl;
			cout<<"O For Going Back To Main Menu"<<endl;

			cin >> employeeInput;

			while (employeeInput != 1 && employeeInput != 2 && employeeInput != 3 && employeeInput != 0)
			{
				cout << "Invalid Input Enter Again : ";
				cin >> employeeInput;
			}

			if (employeeInput == 1)
			{
				system("cls");
				
				POS.addToCart(IMM);

				cout << "Do You Want To Go Back (Y/N) : ";
				char ch;
				cin >> ch;

				while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
				{
					cout << "Invalid Input Enter Again : ";
					cin >> ch;
				}

				if (ch == 'N' || ch == 'n')
				{
					break;
				}
				
			}

			if (employeeInput == 2)
			{
				system("cls");
				
			}

			if (employeeInput == 3)
			{
				system("cls");
				
			}

			if (employeeInput == 0)
			{
				input = -1;
			}
		}


	}












	return 0;
}
