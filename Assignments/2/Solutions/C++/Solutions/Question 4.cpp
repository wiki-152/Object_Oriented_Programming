/*
   Muhammad Waqas Shahid Khan
   22I - 2469
   BS SE-E
*/

#include <iostream>

using namespace std;

struct SavingAccount
{
	char* name;
	float annualInterestRate;
	double savingBalance;
	char* accountNum;
	static int counter;

	SavingAccount()
	{
		name = NULL;
		annualInterestRate = 1;
		savingBalance = 0;
		counter += 1;
		accountNum = new char[4];
		for (int i = 0; i < 4; i++)
		{
			accountNum[i] = 0;
			if (i == 1)
			{
				*(accountNum + i) = 'S';
			}
			if (i == 2)
			{
				accountNum[i] = 'A';
			}
			if (i == 3)
			{
				int ch = counter;
				if (ch < 10)
				{
					accountNum[i] = '0';
				}
				else
				{
					ch = ch / 10;
					if (ch == 1)
					{
						accountNum[i] = '1';
					}
					if (ch == 2)
					{
						accountNum[i] = '2';
					}
					if (ch == 3)
					{
						accountNum[i] = '3';
					}
					if (ch == 4)
					{
						accountNum[i] = '4';
					}
					if (ch == 5)
					{
						accountNum[i] = '5';
					}
					if (ch == 6)
					{
						accountNum[i] = '6';
					}
					if (ch == 7)
					{
						accountNum[i] = '7';
					}
					if (ch == 8)
					{
						accountNum[i] = '8';
					}
					if (ch == 9)
					{
						accountNum[i] = '9';
					}
				}

				if (i == 4)
				{
					int ch = counter;
					if (ch < 10)
					{
						accountNum[i] = '0';
					}
					else
					{
						ch = ch % 10;
						if (ch == 1)
						{
							accountNum[i] = '1';
						}
						if (ch == 2)
						{
							accountNum[i] = '2';
						}
						if (ch == 3)
						{
							accountNum[i] = '3';
						}
						if (ch == 4)
						{
							accountNum[i] = '4';
						}
						if (ch == 5)
						{
							accountNum[i] = '5';
						}
						if (ch == 6)
						{
							accountNum[i] = '6';
						}
						if (ch == 7)
						{
							accountNum[i] = '7';
						}
						if (ch == 8)
						{
							accountNum[i] = '8';
						}
						if (ch == 9)
						{
							accountNum[i] = '9';
						}
					}

				}
			}
		}
	}
};

int SavingAccount::counter = 0;

void OpenCustomerAccount(SavingAccount* savers[], int accountsOpen, char* NameVal, double balance)
{

}

float calculateMonthlyInterest(SavingAccount* saver)
{	
	double balance = saver->savingBalance;
	
	float ai = saver->annualInterestRate;

	float interest = balance*ai;

	interest = interest / 12;

	return interest;
}

void modifyInterestRate(SavingAccount* saver, float newValue)
{
	saver->annualInterestRate = newValue;
}

int SearchCustomer(SavingAccount* savers[], int accountsOpen, char* accountNum)
{
	int length = 0;
	
	while (accountNum[length] != '\0')
	{
		length += 1;
	}
	/*cout << length;*/
	char* check;
	int counter = 0;
	for (int i = 0; i < accountsOpen; i++)
	{
		check = savers[i]->accountNum;
		
		if (check[0] == accountNum[0])
		{
			/*cout << check[0];*/
			for (int j = 0; j < length; j++)
			{
				if (check[j] == accountNum[j])
				{
					cout << check[j] << " and " << accountNum[j] << endl;
					counter += 1;
				}
			}
		}

		if (counter == length)
		{
			return i;
		}
		else
		{
			counter = 0;
		}
	}

	return -1;
}

bool UpdateAccountBalance(SavingAccount* savers[], int accountsOpen, char* accountNumVal, double balanceVal)
{
	int index = SearchCustomer(savers , accountsOpen , accountNumVal);

	if (index != -1)
	{
		savers[index]->savingBalance = balanceVal;
		return true;
	}
	else
	{
		return false;
	}


}

int main()
{
	SavingAccount obj1  , obj2;
	cout << obj2.accountNum;
	/*char ns1[] = "SA99";
	char ns2[] = "SA90";
	obj1.accountNum = ns1;
	obj2.accountNum = ns2;

	SavingAccount obj3[][] = {obj1 , obj2};
	char ns3[] = "SA12";
	
	cout<<SearchCustomer(obj3, 2, ns3);*/

	return 0;
}
