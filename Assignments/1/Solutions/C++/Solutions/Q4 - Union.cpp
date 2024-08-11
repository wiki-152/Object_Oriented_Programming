// Waqas_22i2469

// Assignment 1 

/*
The program will have two arrays with a set of values. 
Call a function named find_union and result will be stored in result array that contains the union of all elements of two array. 
Example 
Arr1 = {1,3,6,7,9,3}
Arr2 = {2,3,6,10}
ResultUnionArr = {1,2,3,6,7,10}
Note: You can add helping function in the code.

*/
#include<iostream>
using namespace std;
struct arrayUnion{
	int arr1[10]; //keep this size
	int arr2[5]; // keep this size
	int *ResultUnionArr;
	int counter;

	input()
	{
		cout<<"Enter Values For Array 1 : ";
		for (int i=0 ; i<10 ; i++)
		{
			cin>>arr1[i];
		}
		
		cout<< endl << "Enter Values For Array 2 : ";
		for (int i=0 ; i<5 ; i++)
		{
			cin>>arr2[i];
		}
		
		//cin>>arr1 >>arr2
		//input of the arr1 and arr2
	}
	
	find_union()
	{
		counter = 15 ;
		
		for (int i = 0 ; i<10 ; i++)
		{
			for (int j=0 ; j<5 ; j++)
			{
				if (arr1[i] == arr2[j])
				{
					counter -= 1 ;
				}
			}
		}
		
		ResultUnionArr = new int [counter];
		
		for (int i=0 ; i<counter ; i++)
		{
			*(ResultUnionArr) = 0 ;
		}
		
		for (int i=0 ; i<10 ; i++)
		{
			*(ResultUnionArr + i) = arr1[i];
		}		
		
		bool status = true;
		int checker = 1;
		
		for (int i=0 ; i<5 ; i++)
		{
			status = true;
			for (int j=0 ; j<10 ; j++)
			{
				if (arr2[i] == arr1[j])
				{
					status = false;
				}
			}
			
			if (status == true)
			{
				*(ResultUnionArr + 9 + checker) = arr2[i];
				checker += 1;
			}
			
		}
		
		// bubble sorting !
		
		bool swapFlag;
	    int temp;
	    do
	    {
		        swapFlag = false;
		        for (int i = 0; i < (counter - 1); i++)
		        {
			            if ((*(ResultUnionArr + i)) > (*(ResultUnionArr + i + 1)))
			            {
				                temp = *(ResultUnionArr+i);
				                *(ResultUnionArr+i) = *(ResultUnionArr +i + 1);
				                *(ResultUnionArr +i + 1) = temp;
				            swapFlag = true;
			            }
		        }
	    } while (swapFlag==true);
		
		//find union of arr1 and arr2
	}
	printresult()
	{
		//print array with union
		
		for (int i=0 ; i<counter ; i++)
		{
			cout<<*(ResultUnionArr + i) << "\t" ;
		}
		
		delete [] ResultUnionArr;
		ResultUnionArr = NULL ;
	}
};


int main()
{
	arrayUnion u;
	u.input();
	u.find_union();
	u.printresult();
	//main will remain same
}
