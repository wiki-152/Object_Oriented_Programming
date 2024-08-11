/*
   Muhammad Waqas Shahid Khan
   22I - 2469
   BS SE-E
*/

#include <iostream>

using namespace std;

class Integer
{
private:
	int num;
	string str;

public:
	Integer()
	{
		num = 0;
		str = "-";
	}

	Integer(int input_num)
	{
		num = input_num;
	}

	Integer(string input_str)
	{
		str = input_str;
	}

	void set(int input_num)
	{
		num = input_num;
	}

	int get() const
	{
		return num;
	}

	int bitCount()
	{
		int save = num;
		int n = 0;
		int ii = num;
		int counter = 0;
		while (num != 0)
		{
			num = num / 2;
			n = (ii)-(num * 2);
			ii = num;

			if (n == 1)
			{
				counter +=1;
			}
		}

		num = save;

		return counter;
	}

	int compareTo(Integer obj) // What to return is not defined in question 
	{
		if (num > obj.get())
		{
			return 1;
		}

		if (num < obj.get())
		{
			return 2;
		}

		if (num == obj.get())
		{
			return 3;
		}
	}

	double doubleValue()
	{
		return (double(num));
	}

	float floatValue()
	{
		return (float(num));
	}

	Integer plus(const Integer obj)
	{
		Integer new_int;
		new_int.set(this->num + obj.num);

		return new_int;
	}

	Integer minus(const Integer obj)
	{
		Integer new_int;
		new_int.set(this->num - obj.num);

		return new_int;
	}

	Integer multiple(const Integer obj)
	{
		Integer new_int;
		new_int.set(this->num * obj.num);

		return new_int;
	}

	Integer divide(const Integer obj)
	{
		Integer new_int;
		new_int.set(this->num / obj.num);

		return new_int;
	}

	static int numberOfLeadingZeros(int i)
	{
		int digits = 0;
		int n = i;
		while (n != 0)
		{
			n = n / 10;
			digits += 1;
		}

		int c = 0;
		int nn = 1;
		for (int i = 1; i <= digits; i++)
		{
			nn *= 10;
		}

		while (digits!=0)
		{
			if (n % nn == 0)
			{
				c += 1;
			}
		}

		return c;
	}

	static int numberOfTrailingZeros(int i)
	{
		int digits = 0;
		int n = i;
		while (n != 0)
		{
			if (n % 10 == 0)
			{
				digits +=1;
			}

			n = n / 10;
		}

		return digits;
	}

	static string toBinaryString(int i)
	{
		int n = 0;
		int ii = i;
		string wow;
		while (i != 0)
		{
			i = i / 2;
			n = (ii)-(i * 2);
			ii = i;

			for (int i = 0; i <= 1; i++)
			{
				if (n == 1)
				{
					wow += "1";
					break;
				}

				if (n == 0)
				{
					wow += "0";
					break;
				}
			}

		}

		int length = 0;
		int counter = 0;
		while (wow[counter] != '\0')
		{
			counter += 1;
		}

		length = counter;
		string newstr;
		for (int i = length; i >= 0; i--)
		{
			newstr += wow[i];
		}
		return newstr;
	}

	static string toHexString(int i)
	{
		int n = 0;
		int ii = i;
		string wow;
		while (i != 0)
		{
			i = i / 16;
			n = (ii)-(i * 16);
			ii = i;

			for (int i = 0; i < 16; i++)
			{
				if (n == 1)
				{
					wow += "1";
					break;
				}

				if (n == 2)
				{
					wow += "2";
					break;
				}

				if (n == 3)
				{
					wow += "3";
					break;
				}

				if (n == 4)
				{
					wow += "4";
					break;
				}

				if (n == 5)
				{
					wow += "5";
					break;
				}

				if (n == 6)
				{
					wow += "6";
					break;
				}

				if (n == 7)
				{
					wow += "7";
					break;
				}

				if (n == 8)
				{
					wow += "8";
					break;
				}

				if (n == 9)
				{
					wow += "9";
					break;
				}

				if (n == 10)
				{
					wow += "A";
					break;
				}

				if (n == 11)
				{
					wow += "B";
					break;
				}

				if (n == 12)
				{
					wow += "C";
					break;
				}

				if (n == 13)
				{
					wow += "D";
					break;
				}

				if (n == 14)
				{
					wow += "E";
					break;
				}

				if (n == 15)
				{
					wow += "F";
					break;
				}
			}

		}

		int length = 0;
		int counter = 0;
		while (wow[counter] != '\0')
		{
			counter += 1;
		}

		length = counter;
		string newstr;
		newstr += "0x";
		for (int i = length; i >= 0; i--)
		{
			newstr += wow[i];
		}
		return newstr;
	}

	static string toOctString(int i)
	{
		int n = 0;
		int ii = i;
		string wow;
		while (i != 0)
		{
			i = i / 8;
			n = (ii)-(i * 8);
			ii = i;

			for (int i = 0; i < 8; i++)
			{
				if (n == 1)
				{
					wow += "1";
					break;
				}

				if (n == 2)
				{
					wow += "2";
					break;
				}

				if (n == 3)
				{
					wow += "3";
					break;
				}

				if (n == 4)
				{
					wow += "4";
					break;
				}

				if (n == 5)
				{
					wow += "5";
					break;
				}

				if (n == 6)
				{
					wow += "6";
					break;
				}

				if (n == 7)
				{
					wow += "7";
					break;
				}

				if (n == 8)
				{
					wow += "8";
					break;
				}
			}

		}

		int length = 0;
		int counter = 0;
		while (wow[counter] != '\0')
		{
			counter += 1;
		}

		length = counter;
		string newstr;
		newstr += "0";
		for (int i = length; i >= 0; i--)
		{
			newstr += wow[i];
		}
		return newstr;
	}



};

int main()
{
	Integer a;

	cout << a.toHexString(500)<<endl;

	cout << a.toOctString(500) << endl;

	cout << a.toBinaryString(500)<<endl;

	cout << a.numberOfTrailingZeros(1000);
	return 0;
}
