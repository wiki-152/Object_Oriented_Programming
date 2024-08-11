// Waqas_22i2469

// Assignment 1

/*
Example: printDiamond(5) will give us the following output
**********
****  ****
***    ***
**      **
*        *
**      **
***    ***
****  ****
**********
*/


#include<iostream>

using namespace std;

void star_printer (int star)
{
	static int star_counter = 0;
	if (star_counter == star)
	{
		star_counter = 0;
		return;
	}
	else
	{
		cout<<"*";
		star_counter += 1;
		star_printer (star);
	}
}

void space_printer (int space)
{
	static int space_counter = 0;
	if (space_counter == space)
	{
		space_counter = 0;
		return;
	}
	else
	{
		cout<<" ";
		space_counter += 1;
		space_printer (space);
	}
}

void printDiamond(int n)//define arrguments
{
	//No loops allowed
	//you can make helper funcation to print different items
	//all funcations must be done with recurrsion
	
	static int counter = 1 ;
	static int stars = n/2 ;
	static int spaces = 0 ;
	
	if (counter == n)
	{
		return;
	} 
	else
	{
		if (counter < (n/2))
		{
			star_printer(stars);
			space_printer (spaces);
			star_printer (stars);
			
			counter += 1;
			stars -= 1;
			spaces += 2;
		
			cout<<endl;
			printDiamond (n);
		}
		
		if (counter == (n/2))
		{
			star_printer(stars);
			space_printer (spaces);
			star_printer (stars);
			
			counter += 1;
			stars += 1;
			spaces -= 2;
			
			cout<<endl;
			printDiamond (n);
		}
		
		if (counter > (n/2) && counter < n)
		{
			star_printer(stars);
			space_printer (spaces);
			star_printer(stars);
			
			counter += 1;
			stars += 1;
			spaces -= 2;
			
			cout<<endl;
			printDiamond (n);
		}
	}
	
}

main()
{
	int n;
	cout << "Enter Number of star: ";
	cin >> n;
	printDiamond(n*2);//define arguments 
}
