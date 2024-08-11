/*
   Muhammad Waqas Shahid Khan
   22I - 2469
   BS SE-E
*/

#include <iostream>

using namespace std;

class String
{
private:
	char* data;
	int size;

public:
	String()
	{
		data = NULL;
		size = 0;
	}

	String(int length)
	{
		size = length;
		
		data = new char[size];

		for (int i = 0; i < length; i++)
		{
			*(data + i) = '-';
		}
	}

	String(char* str)
	{
		data = str;
		
		size = 0;

		while (data[size] != '\0')
		{
			size += 1;
		}
	}

	String(const String& str)
	{
		this->size = size;

		for (int i = 0; i < size; i++)
		{
			this->data[i] = data[i];
		}
	}

	~String()
	{
		delete data;
		data = NULL;
		size = 0;
	}

	int stringLength()
	{
		size = 0;

		while (data[size] != '\0')
		{
			size += 1;
		}

		return size;
	}

	void clear()
	{
		size = 0;
		data = NULL;
	}

	bool isEmpty()
	{
		bool status = false;
		if (data == NULL || size == 0)
		{
			status = true;
		}

		return status;
	}

	int charAt(char c)
	{
		int counter = 0;
		int index = -1;

		while (data[counter != '\0'])
		{
			if (data[counter] == c)
			{
				index = counter;
			}
			break;
		}
		return index;
	}

	char* getdata()
	{
		return data;
	}

	bool isEqual(char* str)
	{
		int length_str=0;
		
		while (*(str+length_str) != '\0')
		{
			length_str += 1;
		}

		int counter = 0;

		for (int i = 0; i < length_str; i++)
		{
			if (*(data + i) == *(str + i))
			{
				for (int j = i; j < (length_str + i); j++)
				{
					if (*(data + j) == *(str + j))
					{
						counter += 1;
					}
				}
			}

			if (counter == length_str)
			{
				return true;
			}
			else
			{
				counter = 0;
			}
		}

		return false;
	}

	bool equalsIgnoreCase(char* str)
	{
		int length_str = 0;

		while (*(str + length_str) != '\0')
		{
			length_str += 1;
		}

		char* main = data;
		char* sub = str;
		for (int i = 0; i < length_str; i++)
		{
			if (*(main + i) >= 65 && *(main + i)<=90)
			{
				*(main + i) += 65;
			}

			if (*(sub + i) >= 65 && *(sub + i) <= 90)
			{
				*(sub + i) += 65;
			}

		}

		int counter = 0;

		for (int i = 0; i < length_str; i++)
		{
			if (*(main + i) == *(sub))
			{
				for (int j = i; j < (length_str + i); j++)
				{
					if (*(main + j) == *(sub + j - i))
					{
						counter += 1;
					}
				}
			}

			if (counter == length_str)
			{
				return true;
			}
			else
			{
				counter = 0;
			}
		}

		return false;
	}

	char* substring(char* substr, int startIndex)
	{
		int length_substr = 0;

		while (*(substr + length_substr) != '\0')
		{
			length_substr += 1;
		}

		int counter = 0;
		int index = -1;
		for (int i = startIndex; i < size; i++)
		{
			if (*(data + i) == *(substr))
			{
				for (int j = i; j < (length_substr + i); j++)
				{
					if (*(data + j) == *(substr + j - i))
					{
						counter += 1;
					}
				}
			}

			if (counter == length_substr)
			{
				index = i;
			}
			else
			{
				counter = 0;
			}
		}

		if (index != -1)
		{
			string new_str;

			for (int i = index; i < size; i++)
			{
				new_str += *(data + i);
			}

			int l = 0;
			while (new_str[l] != '\0')
			{
				l += 1;
			}

			const int le = l;
			char final[le];
			for (int i = 0; i < l; i++)
			{
				final[i] = new_str[i];
			}

			
			char* ptr =final ;
			return ptr;
		}
		else
		{
			return NULL;
		}
	}

	char* substring(char* substr, int startIndex, int endIndex)
	{
		int length_substr = 0;

		while (*(substr + length_substr) != '\0')
		{
			length_substr += 1;
		}

		int counter = 0;
		int index = -1;
		for (int i = startIndex; i < endIndex; i++)
		{
			if (*(substr) == *(data + i))
			{
				for (int j = i; j < (length_substr + i); j++)
				{
					if (*(data + j) == *(substr + j - i))
					{
						counter += 1;
					}
				}
			}
		}
	}

	void print()
	{
		int length = 0;

		while (data[length] != '\0')
		{
			length += 1;
		}

		if (length != 0)
		{
			for (int i = 0; i < size; i++)
			{
				cout << *(data + i);
			}
		}
		else
		{
			cout << "NULL" << endl;
		}
	}
};

int main()
{
	char str[] = "aBc";
	char* ptr = str;
	String obj(ptr);
	/*obj.clear();*/
	cout << obj.stringLength();


	return 0;
}
