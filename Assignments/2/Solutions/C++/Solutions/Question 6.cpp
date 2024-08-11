/*
   Muhammad Waqas Shahid Khan
   22I - 2469
   BS SE-E
*/

#include <iostream>

using namespace std;

class Library
{
private:
	char* bookTitle;
	char* author;
	int bookID;
	int quantity;
	float price;
	static int totalBooks;
	bool calcPrice_status;

public:
	Library(char* bt = NULL, char* a = NULL, int b_id = -1 , int q=0 , float p=0)
	{
		bookTitle = bt;
		author = a;
		bookID = b_id;
		quantity = q;
		price = p;
		calcPrice_status = false;
	}
	char* getBookTitle()
	{
		return bookTitle;
	}

	char* getAuthor()
	{
		return author;
	}

	int getBookID()
	{
		return bookID;
	}

	int getQuantity()
	{
		return quantity;
	}

	float getPrice()
	{
		return price;
	}

	void setBookTitle(char* title)
	{
		bookTitle = title;
	}

	void setAuthor(char* authorName)
	{
		author = authorName;
	}

	void setBookID(int input_bookID)
	{
		bookID = input_bookID;
	}

	void setQuantity(int input_quantity)
	{
		while (input_quantity < 0)
		{
			cout << "Quantity can't be negative! Enter again : ";
			cin >> input_quantity;
		}
		quantity = input_quantity;
	}

	void setPrice(float input_price)
	{
		price = input_price;
	}

	static void setTotalBooks(int input_totalBooks)
	{
		totalBooks = input_totalBooks;
	}

	void calcTotalPrice()
	{
		if (calcPrice_status == false)
		{
			price *= quantity;
			calcPrice_status = true;
		}
		else
		{
			cout << "Price of all copies has been already calculated? Enter (Y/y)";
			char input;
			cin >> input;
			if (input == 'y' || input == 'Y')
			{
				int p = price;
				price = 0;
				price = p* quantity;
			}
		}
		/*cout << price;*/
	}

	static int getTotalBooks()
	{
		return totalBooks;
	}

};

Library getBook_at(Library books[100], int index)
{
	return books[index];
}

void addBook(Library books[100], Library newBook)
{
	int index=-1;
	for (int i = 0; i < 100; i++)
	{
		if (books[i].getBookID() == -1)
		{
			index = i;
		}
	}

	if (index == -1)
	{
		cout << "The Library is full!"<<endl;
	}
	else
	{
		books[index].setBookTitle(newBook.getBookTitle());
		books[index].setAuthor(newBook.getAuthor());
		books[index].setBookID(newBook.getBookID());
		books[index].setQuantity(newBook.getQuantity());
		books[index].setPrice(newBook.getPrice());
		books[index].setTotalBooks(newBook.getTotalBooks());
	}
}

void removeBook(Library books[100], int bookID)
{
	int index = -1;
	for (int i = 0; i < 100; i++)
	{
		if (books[i].getBookID() == bookID)
		{
			index = -1;
		}
	}

	if (index == -1)
	{
		cout << "Book Not Found!"<<endl;
	}
	else
	{
		books[index].setBookTitle(NULL);
		books[index].setAuthor(NULL);
		books[index].setBookID(-1);
		books[index].setQuantity(0);
		books[index].setPrice(0);
	}
}

void SortByTitle(Library books[100])
{
	bool swapFlag = false;
	Library temp;
	int counter = 0;
	do
	{
		swapFlag = false;
		counter = 0;
		for (int i = 0; i < 99 ; i++) // Assuming Size is fixed 100
		{
			char *first = (*(books + i)).getBookTitle();
			char *second = (*(books + i + 1)).getBookTitle();
			int n1 = first[counter];
			int n2 = second[counter];
			/*cout << n1 << n2 << endl;*/

			if (n1 >= 65 && n1 <= 90)
			{
				n1 = n1 + 32;
			}

			if (n2 >= 65 && n2 <= 90)
			{
				n2 = n2 +32;
			}

			while (n1 == n2)
			{
				n1 = first[counter];
				n2 = second[counter];
				counter += 1;

				if (n1 >= 65 && n1 <= 90)
				{
					n1 = n1 + 32;
				}

				if (n2 >= 65 && n2 <= 90)
				{
					n2 = n2 + 32;
				}
			}
			/*cout << char(n1) << " " << char(n2) << endl;*/

			if (n1 > n2)
			{
				temp = *(books + i);
				*(books + i) = *(books + i + 1);
				*(books + i + 1) = temp;
				swapFlag = true;
			}
		}
	} while (swapFlag == true);

	/*cout << books[0].getBookTitle();*/
}

void SortByAuthor(Library books[100])
{
	bool swapFlag = false;
	Library temp;
	int counter = 0;
	do
	{
		swapFlag = false;
		counter = 0;
		for (int i = 0; i < 99; i++) // Assuming Size is fixed 100
		{
			char* first = (*(books + i)).getAuthor();
			char* second = (*(books + i + 1)).getAuthor();
			int n1 = first[counter];
			int n2 = second[counter];
			/*cout << n1 << n2 << endl;*/

			if (n1 >= 65 && n1 <= 90)
			{
				n1 = n1 + 32;
			}

			if (n2 >= 65 && n2 <= 90)
			{
				n2 = n2 + 32;
			}

			while (n1 == n2)
			{
				n1 = first[counter];
				n2 = second[counter];
				counter += 1;

				if (n1 >= 65 && n1 <= 90)
				{
					n1 = n1 + 32;
				}

				if (n2 >= 65 && n2 <= 90)
				{
					n2 = n2 + 32;
				}
			}
			/*cout << char(n1) << " " << char(n2) << endl;*/

			if (n1 > n2)
			{
				temp = *(books + i);
				*(books + i) = *(books + i + 1);
				*(books + i + 1) = temp;
				swapFlag = true;
			}
		}
	} while (swapFlag == true);

	/*cout << books[0].getAuthor();*/
}

void SortByPrice(Library books[1])
{
	bool swapFlag = false;
	Library temp;
	
	do
	{
		swapFlag = false;
		
		for (int i = 0; i < 1; i++) // Assuming Size is fixed 100
		{
			float n1 = (*(books + i)).getPrice();
			float n2 = (*(books + i + 1)).getPrice();
			
			/*cout << n1 << n2 << endl;*/

			while (n1 == n2)
			{
				
			}
			/*cout << char(n1) << " " << char(n2) << endl;*/

			if (n1 > n2)
			{
				temp = *(books + i);
				*(books + i) = *(books + i + 1);
				*(books + i + 1) = temp;
				swapFlag = true;
			}
		}
	} while (swapFlag == true);

	cout << books[0].getPrice();
}

bool searchByTitle (Library books[2] , char*titleName)
{
	int counter = 0;
	int length = 0;

	for (int i = 0; i < 2; i++)
	{
		length = 0;
		counter = 0;

		char* title = (*(books + i)).getBookTitle();
		while (title[length] != '\0')
		{
			length += 1;
		}

		if (title[0] == titleName[0])
		{
			for (int j = 0; j < length; j++)
			{
				if (title[j] == titleName[j])
				{
					counter += 1;
				}
			}
		}

		if (counter == length)
		{
			return true;
		}
	}

	return false;
}

Library mostExpensiveBook(Library books[2])
{
	Library temp = books[0];

	for (int i = 0; i < 2; i++)
	{
		if (temp.getPrice() < books[i].getPrice())
		{
			temp = books[i];
		}
	}
	cout << temp.getPrice();
	return temp;
}



int main()
{

	char arr[] = "Abmee";
	char* ptr = arr;

	Library obj;
	obj.setBookTitle(ptr);
	obj.setAuthor(ptr);
	/*obj.setPrice(10.5);
	obj.setQuantity(20);
	obj.calcTotalPrice();*/

	Library obj2;
	char arr1[] = "Abmed";
	char* ptr1 = arr1;
	obj2.setBookTitle(ptr1);
	obj2.setAuthor(ptr1);
	obj.setPrice(500.12);
	obj2.setPrice(50.05);
	Library objj[] = { obj,obj2 };

	/*SortByTitle(objj);*/
	
	/*SortByAuthor(objj);*/

	/*SortByPrice(objj);*/

	/*char track[] = "Abmes";
	char* ptrrr = track;
	cout << searchByTitle(objj , ptrrr);*/

	/*mostExpensiveBook(objj);*/

	return 0;
}
