/*
   Muhammad Waqas Shahid Khan
   22I - 2469
   BS SE-E
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void start_hangman (string word , int length)
{
	int count = 0 ;
	
	char letter ;
	
	char array[length];
	
	for (int i=0 ; i<length ; i++)
	{
		array[i] = '-';
	}
	
	bool status = false;
	
	cout<<word << endl;
	while (count != 4)
	{
		status = false;
		cout<< "Enter Letter : ";
		cin>> letter;
		
		for (int i=0 ; i<length ; i++)
		{
			if (letter == word[i] || ((letter + 23) == word[i]))
			{
				cout<<"found"<<endl;
				array[i] = i;
				status = true;
			}
		}
		
		if (status == false)
		{
			count +=1 ;
		}
	}
}

int main()
{
	cout << "----------------------------Hangman Game----------------------------" << endl;
	
	string array[10] = {"apple" , "Banana" , "Apricot" , "Blueberry" , "Cranberry" , "Cherry" , "Dragonfruit" , "Dates" , "Orange" , "Coconut"};
	
	srand (time(0));
	int num = (rand () % (9 - 0 + 1)) + 0 ;
	
	string word;
	
	if (num == 1)
	{
		word = "apple";
	}
	
	if (num == 2)
	{
		word = "Banana";
	}
	
	if (num == 3)
	{
		word = "Apricot";
	}
	
	if (num == 4)
	{
		word = "Blueberry"; 
	}
	
	if (num == 5)
	{
		word = "Cranberry";
	}
	
	if (num == 6)
	{
		word = "Cherry";
	}
	
	if (num == 7)
	{
		word = "Dragonfruit";
	}
	
	if (num == 8)
	{
		word = "Dates";
	}
	
	if (num == 9)
	{
		word ="Orange";
	}
	
	if (num == 10)
	{
		word = "Coconut";
	}
	
	int length = 0 ;
	while (word [length] != '\0')
	{
		length +=1 ;
	}
	
	start_hangman (word , length );










	return 0;
}

