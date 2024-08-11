
// Waqas_22i2469

// Assignment # 1 

#include<iostream>
using namespace std;
//Recursive function
int find_Length(string s, int counter = 0) 
{
    if (s[counter] == '\0') {
        return counter;
    }
    else {
        counter += 1;
        return find_Length(s, counter);
    }
}


struct String_Manipulation {
	int Calculate_length (string s)
	{
		int length = find_Length (s);
			//call a recursive funcaiton to find string length
			//add your code
			/*
			The function should get a string as input and return the length of the string. 
			The length should be measured with the help of a recursive function. 
			*/
		return length;
	}
	bool substring (string main, string str)
	{
		bool status = false ;
		//add your code
		/*
			Main = "I am taking the OOP Class"
			Str = "OOP"
			The function should return true as the OOP exist in the above string.
			Another example
			Main = "I am taking the OOP Class"
			Str = "taking"
			The function should return true as it exists in the above string.
			Another example
			Main = "I am taking the OOP Class"
			Str = "that OOP"
			The function should return false as it does not exist in the above string.
			Another example
			Main = "I am taking the OOP Class"
			Str = "Taking the oop class and doing the assignment"

		*/
		int main_length = Calculate_length(main);
		
		int sub_length = Calculate_length(str);
		
		int counter = 0;
		
		for (int i=0 ; i<main_length ; i++)
		{
			if (main[i] == str[0])
			{
				counter += 1;
				for (int j=1 ; j<sub_length ; j++)
				{
					if (main[i+j] == str[j])
					{
						counter += 1;
					}
				}
			}
			
			if (counter == sub_length )
			{
				status = true;
			}
			else
			{
				counter = 0;
			}
		}
		return status;
	}
	int substring_position (string main, string str)
	{
		int index = -1;
		
		bool status = substring (main , str);
		
		if (status == true)
		{
			int main_length = Calculate_length(main);
		
		    int sub_length = Calculate_length(str);
		    
		    int counter = 0;
		    
		    for (int i = 0 ; i< main_length ;i++)
		    {
		    	if (main[i] == str[0])
			    { 
				    counter += 1;
				    for (int j=1 ; j<sub_length ; j++)
				    {
					    if (main[i+j] == str[j])
					    {
						    counter += 1;
					    }
				    }
			    }
			
			    if (counter == sub_length )
			    {
				    index = i;
				    break;
			    }
			    else
		        {
				    counter = 0;
			    }	
			}	
		}
		
		//add your code
		/*
			`	-                                                Main = "I am taking OOP course"
			Str = "taking"
			The function will return 5 as substring exist and starts at 5th index of main string. In case the substring does not exist, you will return -1.

		*/
		
		cout<<index;
		return index;
	}
};
int main()
{
	//add your code
	
	// Object
	String_Manipulation s1 ;
	
	s1.substring_position("I am taking OOP course" , "taking" );
}
