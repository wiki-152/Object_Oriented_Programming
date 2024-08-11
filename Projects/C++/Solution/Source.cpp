/*
   Muhammad Waqas Shahid Khan
   22I - 2469
   BS SE-E
*/

#include <iostream>
#include <string>
#include <fstream> // For File Handling
#include <Windows.h> 
#include <conio.h> // For _getch() function for Password
#include <cstdlib> 

#include "D:\@@WIKI STUDY UNI\!---Semester_2---!\@CS1004--OOP\22I-2469\Header.h"

using namespace std;



// ------------------------------------------- CLASSES -------------------------------------------

COUNTRY::COUNTRY() : sizeOfArray(20)
{
	countryName = new char[sizeOfArray];
	city = new char[sizeOfArray];

	for (int i = 0; i < sizeOfArray; i++)
	{
		countryName[i] = '-';
		city[i] = '-';
	}
}

COUNTRY::COUNTRY(char* cn, char* c) : sizeOfArray(20)
{
	countryName = new char[sizeOfArray];
	city = new char[sizeOfArray];

	for (int i = 0; i < sizeOfArray; i++)
	{
		countryName[i] = '-';
		city[i] = '-';
		countryName[i] = cn[i];
		city[i] = c[i];
	}
}

COUNTRY::COUNTRY(const COUNTRY& copyCountryObj) : sizeOfArray(20)
{
	countryName = new char[sizeOfArray];
	city = new char[sizeOfArray];

	for (int i = 0; i < sizeOfArray; i++)
	{
		countryName[i] = '-';
		city[i] = '-';
		countryName[i] = copyCountryObj.countryName[i];
		city[i] = copyCountryObj.city[i];
	}
}

void COUNTRY::setCountryName(char* cn)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		countryName[i] = cn[i];
	}
}

void COUNTRY::setCity(char* c)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		city[i] = c[i];
	}
}

void COUNTRY::setCountryAllDetails(char* cn, char* c)
{
	int i = 0;
	for (i = 0; i < sizeOfArray; i++)
	{
		countryName[i] = cn[i];
		city[i] = c[i];
	}
	countryName[i] = '\0';
	city[i] = '\0';

	/*cout << countryName <<  city  << endl;
	Sleep(1000);*/
}

char* COUNTRY::getCountryName() const
{
	return countryName;
}

char* COUNTRY::getCity() const
{
	return city;
}

void COUNTRY::operator=(const COUNTRY& copyCountryObj)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		countryName[i] = copyCountryObj.countryName[i];
		city[i] = copyCountryObj.city[i];
	}
}

COUNTRY::~COUNTRY()
{
}

AIRPORT::AIRPORT() : sizeOfArray(4)
{
	name = new char[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		name[i] = '-';
	}

	countryTravel;
	countryFilled = false;


	NS = '-';
	covidBan = false;

}

AIRPORT::AIRPORT(char* n, COUNTRY c, bool cf, char ns, bool cb) : sizeOfArray(4)
{
	name = new char[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		name[i] = n[i];
	}
	countryTravel = c;
	countryFilled = cf;


	NS = ns;
	covidBan = cb;
}

AIRPORT::AIRPORT(const AIRPORT& copyAirportObj) : sizeOfArray(4)
{
	name = new char[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		name[i] = copyAirportObj.name[i];
	}
	countryTravel = copyAirportObj.countryTravel;
	countryFilled = copyAirportObj.countryFilled;

	NS = copyAirportObj.NS;
	covidBan = copyAirportObj.covidBan;
}

void AIRPORT::setName(char* n)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		name[i] = n[i];
	}
}

void AIRPORT::setCountry(COUNTRY& c)
{
	countryTravel = c;
}

void AIRPORT::setCountryFilled(bool cf)
{
	countryFilled = cf;
}

void AIRPORT::setNS(char ns)
{
	NS = ns;
}

void AIRPORT::setCovidBan(bool cb)
{
	covidBan = cb;
}

void AIRPORT::setAirportAllDetails(char* n, COUNTRY c, bool cf, char ns, bool cb)
{
	name = n;
	countryTravel = c;
	countryFilled = cf;

	NS = ns;
	covidBan = cb;

	//cout<< n << c.getCountryName() << ns << endl;

	//Sleep(5000);

}

void AIRPORT::print()
{
	cout << "Airport Name: " << name << endl;
	cout << "Country Name: " << countryTravel.getCountryName() << endl;
	cout << "City Name: " << countryTravel.getCity() << endl;
	cout << "North OR South: " << NS << endl;
	if (covidBan == true)
	{
		cout << "Covid Ban: Yes" << endl;
	}
	else
	{
		cout << "Covid Ban: No" << endl;
	}
}


char AIRPORT::getNS() const
{
	return NS;
}

bool AIRPORT::getCovidBan() const
{
	return covidBan;
}

char* AIRPORT::getName() const
{
	return name;
}

COUNTRY AIRPORT::getCountry() const
{
	return countryTravel;
}

bool AIRPORT::getCountryFilled() const
{
	return countryFilled;
}

void AIRPORT::operator=(const AIRPORT& copyAirportObj)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		name[i] = copyAirportObj.name[i];
	}
	countryTravel = copyAirportObj.countryTravel;
	countryFilled = copyAirportObj.countryFilled;

	NS = copyAirportObj.NS;
	covidBan = copyAirportObj.covidBan;

}

AIRPORT::~AIRPORT()
{
}


BOOKING::BOOKING() : sizeOfArray(20)
{
	flightName = new char[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		flightName[i] = '-';
	}

	day = -1;
	month = -1;
	year = -1;
	AIRPORT obj;
	cost = -1;
	hours = -1;
	mins = -1;
	flown = false;
}

BOOKING::BOOKING(char* fn, int d, int m, int y, AIRPORT fa, AIRPORT ta, bool faf, bool taf, bool dir, bool ind, bool l_f, bool i_f, double c, int ho, int mi, bool f) : sizeOfArray(20)
{
	flightName = new char[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		flightName[i] = '-';
		flightName[i] = fn[i];
	}
	day = d;
	month = m;
	year = y;
	cost = c;
	hours = ho;
	mins = mi;
	flown = f;
}

BOOKING::BOOKING(const BOOKING& copyBookingObj) : sizeOfArray(20)  // check
{
	flightName = new char[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		flightName[i] = '-';
		flightName[i] = copyBookingObj.flightName[i];
	}
	day = copyBookingObj.day;
	month = copyBookingObj.month;
	year = copyBookingObj.year;
	cost = copyBookingObj.cost;
	hours = copyBookingObj.hours;
	mins = copyBookingObj.mins;
	flown = copyBookingObj.flown;
}

void BOOKING::direct_or_indirect()
{
}

// First checks if data is complete then If country is same then avg travel time will be 2 hours and for international american countries 20 hours and for european 8 hours and for middle east 3 hours
void BOOKING::calculateDistance()
{

}

ofstream& operator<<(ofstream& out, const BOOKING& coutBookingObj)
{
	out << "Flight Name: " << coutBookingObj.flightName << endl;
	out << "Date: " << coutBookingObj.day << "/" << coutBookingObj.month << "/" << coutBookingObj.year << endl;
	out << "Cost: " << coutBookingObj.cost << endl;
	out << "Hours: " << coutBookingObj.hours << endl;
	out << "Minutes: " << coutBookingObj.mins << endl;
	out << "Flown: " << coutBookingObj.flown << endl;
	return out;
}

void BOOKING::operator=(const BOOKING& coutBookingObj)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		flightName[i] = '-';
		flightName[i] = coutBookingObj.flightName[i];
	}
	day = coutBookingObj.day;
	month = coutBookingObj.month;
	year = coutBookingObj.year;
	cost = coutBookingObj.cost;
	hours = coutBookingObj.hours;
	mins = coutBookingObj.mins;
	flown = coutBookingObj.flown;
}

void BOOKING::input()
{
	char* temp = new char[sizeOfArray];
	cout << "Enter Flight Name: ";
	cin.getline(temp, sizeOfArray);
	setFlightName(temp);
	cout << "Enter Date: ";
	cin >> day >> month >> year;
	cout << "Enter Hours: ";
	cin >> hours;
	cout << "Enter Minutes: ";
	cin >> mins;
}

void BOOKING::setFlightName(char* fn)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		flightName[i] = '-';
		flightName[i] = fn[i];
	}
}

void BOOKING::setDay(int d)
{
	day = d;
}

void BOOKING::setMonth(int m)
{
	month = m;
}

void BOOKING::setYear(int y)
{
	year = y;
}


void BOOKING::setCost(double c)
{
	cost = c;
}

void BOOKING::setHours(int ho)
{
	hours = ho;
}

void BOOKING::setMins(int mi)
{
	mins = mi;
}

void BOOKING::setFlown(bool f)
{
	flown = f;
}

char* BOOKING::getFlightName() const
{
	return flightName;
}

int BOOKING::getDay() const
{
	return day;
}

int BOOKING::getMonth() const
{
	return month;
}

int BOOKING::getYear() const
{
	return year;
}


double BOOKING::getCost() const
{
	return cost;
}

int BOOKING::getHours() const
{
	return hours;
}

int BOOKING::getMins() const
{
	return mins;
}

bool BOOKING::getFlown() const
{
	return flown;
}

BOOKING::~BOOKING()
{
}

USER::USER() :sizeOfArray(20)
{
	firstName = new char[sizeOfArray];
	lastName = new char[sizeOfArray];
	cnic = new char[14];
	userName = new char[sizeOfArray];
	passWord = new char[sizeOfArray];

	for (int i = 0; i < sizeOfArray; i++)
	{
		firstName[i] = '-';
		lastName[i] = '-';
		userName[i] = '-';
		passWord[i] = '-';

		if (i < 14)
		{
			cnic[i] = '-';
		}
	}
	firstName[19] = '\0';
	lastName[19] = '\0';
	userName[19] = '\0';
	passWord[19] = '\0';

	age = -1;
	under18ID = NULL;
	passport = false;
	visa = false;
	counterTravellers = 1;
	passengers = new BOOKING[counterTravellers];

	allDataEntered = false;
	booked = false;
	bookedForMore = false;
}

USER::USER(char* fn, char* ln, int a, char* c, char* un, char* pw, bool p, bool v, int ct, BOOKING* pss, bool ade, USER* u18id) : sizeOfArray(20)
{
	firstName = new char[sizeOfArray];
	lastName = new char[sizeOfArray];
	cnic = new char[14];
	userName = new char[sizeOfArray];
	passWord = new char[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		firstName[i] = '-';
		lastName[i] = '-';
		userName[i] = '-';
		passWord[i] = '-';

		firstName[i] = fn[i];
		lastName[i] = ln[i];
		userName[i] = un[i];
		passWord[i] = pw[i];

		if (i < 14)
		{
			cnic[i] = '-';
			cnic[i] = c[i];
		}
	}
	firstName[19] = '\0';
	lastName[19] = '\0';
	userName[19] = '\0';
	passWord[19] = '\0';

	age = a;
	under18ID = u18id;
	passport = p;
	visa = v;
	counterTravellers = ct;
	passengers = pss;
	allDataEntered = ade;

	booked = false;
	bookedForMore = false;
}

USER::USER(const USER& copyUserObj) : sizeOfArray(20)
{
	firstName = copyUserObj.firstName;
	lastName = copyUserObj.lastName;
	cnic = copyUserObj.cnic;
	userName = copyUserObj.userName;
	passWord = copyUserObj.passWord;
	age = copyUserObj.age;
	under18ID = copyUserObj.under18ID;
	passport = copyUserObj.passport;
	visa = copyUserObj.visa;
	counterTravellers = copyUserObj.counterTravellers;
	passengers = copyUserObj.passengers;
	allDataEntered = copyUserObj.allDataEntered;
}

void USER::userInput()
{
	cout << "Enter First Name: ";
	cin.ignore();
	cin.getline(firstName, sizeOfArray);
	cout << "Enter Last Name: ";
	cin.getline(lastName, sizeOfArray);
	cout << "Enter CNIC: ";
	cin.getline(cnic, 14);

	int counter = 0;
	while (cnic[counter] != '\0')
	{
		if (cnic[counter] < '0' || cnic[counter] > '9')
		{
			cout << "Invalid CNIC Entered" << endl;
			cout << "Enter CNIC: ";
			cin.getline(cnic, 14);
			counter = 0;
		}
		else
		{
			counter++;
		}

		if (counter != 13 && cnic[counter] == '\0')
		{
			cout << "Invalid CNIC Entered (13 Numbers Required)" << endl;
			cout << "Enter CNIC: ";
			cin.getline(cnic, 13);
			counter = 0;
		}
	}
	counter = 0;

	cout << "Enter Username: ";
	cin.getline(userName, sizeOfArray);
	cout << "Enter Password: ";

	char ch;
	counter = 0;
	while ((ch = _getch()) != '\r')
	{

		if (counter < 19)
		{
			passWord[counter] = ch;
			counter++;
			cout << "*";
		}
	}

	passWord[counter] = '\0';

	bool check = checkPassword(passWord);

	while (check == false)
	{
		counter = 0;
		cout << endl << "Password must contain at least 1 uppercase, 1 lowercase, 1 digit and 1 special character and Lenght must be 8 atleast" << endl;
		cout << "Enter Password : ";

		while ((ch = _getch()) != '\r')
		{
			if (counter < 19)
			{
				passWord[counter] = ch;
				counter++;
				cout << "*";
			}
		}

		passWord[counter] = '\0';
		check = checkPassword(passWord);
	}

	char* confirmPass = new char[20];
	for (int i = 0; i < 20; i++)
	{
		confirmPass[i] = '-';
	}

	cout << endl << "Confirm Password : ";
	counter = 0;

	while ((ch = _getch()) != '\r')
	{
		if (counter < 19)
		{
			confirmPass[counter] = ch;
			counter++;
			cout << "*";
		}
	}

	confirmPass[counter] = '\0';

	check = checkPassword(confirmPass);

	while (check == false)
	{
		counter = 0;
		cout << endl << "Password must contain at least 1 uppercase, 1 lowercase, 1 digit and 1 special character and Lenght must be 8 atleast" << endl;
		cout << "Confirm Password : ";
		while ((ch = _getch()) != '\r')
		{
			if (counter < 19)
			{
				confirmPass[counter] = ch;
				counter++;
				cout << "*";
			}
		}
		confirmPass[counter] = '\0';
		check = checkPassword(confirmPass);
	}

	int compare = strcmp(passWord, confirmPass);

	while (compare != 0)
	{
		cout << endl << "Passwords Do Not Match" << endl;

		cout << "Enter Password: ";
		counter = 0;
		while ((ch = _getch()) != '\r')
		{
			if (counter < 19)
			{
				passWord[counter] = ch;
				counter++;
				cout << "*";
			}
		}
		passWord[counter] = '\0';

		check = checkPassword(passWord);

		while (check == false)
		{
			counter = 0;
			cout << endl << "Password must contain at least 1 uppercase, 1 lowercase, 1 digit and 1 special character and Lenght must be 8 atleast" << endl;
			cout << "Enter Password : ";
			while ((ch = _getch()) != '\r')
			{
				if (counter < 19)
				{
					passWord[counter] = ch;
					counter++;
					cout << "*";
				}
			}
			passWord[counter] = '\0';
			check = checkPassword(passWord);
		}

		cout << endl << "Confirm Password : ";
		counter = 0;
		while ((ch = _getch()) != '\r')
		{
			if (counter < 19)
			{
				confirmPass[counter] = ch;
				counter++;
				cout << "*";
			}
		}
		confirmPass[counter] = '\0';

		check = checkPassword(confirmPass);

		while (check == false)
		{
			counter = 0;
			cout << endl << "Password must contain at least 1 uppercase, 1 lowercase, 1 digit and 1 special character and Lenght must be 8 atleast" << endl;
			cout << "Confirm Password : ";
			while ((ch = _getch()) != '\r')
			{
				if (counter < 19)
				{
					confirmPass[counter] = ch;
					counter++;
					cout << "*";
				}
			}
			confirmPass[counter] = '\0';
			check = checkPassword(confirmPass);
		}

		compare = strcmp(passWord, confirmPass);
	}


	cout << "Enter Age: ";
	cin >> age;
	while (age < 0 || age > 100)
	{
		cout << "Invalid Age Entered" << endl;
		cout << "Enter Age: ";
		cin >> age;
	}

	char ch1;
	cout << "Do You Have Passport ? ( Enter Y / N ) : ";
	cin >> ch1;

	while (ch1 != 'Y' && ch1 != 'y' && ch1 != 'N' && ch1 != 'n')
	{
		cout << "Invalid Input" << endl;
		cout << "Do You Have Passport ? ( Enter Y / N ) : ";
		cin >> ch1;
	}
	if (ch1 == 'Y' || ch1 == 'y')
	{
		passport = true;
	}
	else
	{
		passport = false;
	}


	cout << "Do You Have Visa ? (Enter Y / N ) : ";
	cin >> ch1;

	while (ch1 != 'Y' && ch1 != 'y' && ch1 != 'N' && ch1 != 'n')
	{
		cout << "Invalid Input" << endl;
		cout << "Do You Have Visa ? (Enter Y / N ) : ";
		cin >> ch1;
	}

	if (ch1 == 'Y' || ch1 == 'y')
	{
		visa = true;
	}
	else
	{
		visa = false;
	}

	counterTravellers = 1;
	passengers = NULL;
	passengers = new BOOKING[counterTravellers];
	allDataEntered = true;
}

void USER::operator=(const USER& copyUser)
{
	if (copyUser.passengers != NULL)
	{
		passengers = new BOOKING[copyUser.counterTravellers];
		for (int i = 0; i < copyUser.counterTravellers; i++)
		{
			passengers[i] = copyUser.passengers[i];
		}
	}
	else
	{
		passengers = NULL;
	}
	if (copyUser.under18ID != NULL)
	{
		under18ID = new USER;
		*under18ID = *copyUser.under18ID;
	}
	else
	{
		under18ID = NULL;
	}
	firstName = copyUser.firstName;
	lastName = copyUser.lastName;
	userName = copyUser.userName;
	passWord = copyUser.passWord;
	age = copyUser.age;
	passport = copyUser.passport;
	visa = copyUser.visa;
	counterTravellers = copyUser.counterTravellers;
	allDataEntered = copyUser.allDataEntered;
}

void USER::addObj()  // check
{
	if (under18ID == NULL)
	{
		under18ID = new USER;
		under18ID->userInput();
		counterTravellers++;
	}
	else
	{
		USER* temp = under18ID;
		while (temp->under18ID != NULL)
		{
			temp = temp->under18ID;
		}
		temp->under18ID = new USER;
		temp->under18ID->userInput();
		counterTravellers++;
	}
}

void USER::deleteObj() // check
{
	if (under18ID == NULL)
	{
		cout << "No Under 18 ID's Registered" << endl;
	}
	else
	{
		USER* temp = under18ID;
		USER* temp2 = under18ID;
		while (temp->under18ID != NULL)
		{
			temp2 = temp;
			temp = temp->under18ID;
		}
		delete temp;
		temp2->under18ID = NULL;
		counterTravellers--;
	}
}

void USER::addUserToFile(USER& obj)
{
	fstream fs;
	fs.open("Users.txt", ios::binary | ios::out);
	if (fs.is_open())
	{
		fs.write((char*)&obj, sizeof(USER));
		fs.close();
	}
	else
	{
		cout << "File Not Opened" << endl;
	}

	Sleep(5000);
}

bool USER::searchUsername(char* un)
{
	fstream fs;
	bool status = false;
	fs.open("Users.txt", ios::binary | ios::in);
	if (fs.is_open())
	{
		USER temp;
		while (fs.eof() == false)
		{
			fs.read((char*)&temp, sizeof(USER));
			if (strcmp(temp.userName, un) == 0)
			{
				cout << "Username Found!" << endl;
				*this = temp;
				status = true;
				return status;
				break;
			}
		}
		fs.close();
		return status;
	}
	else
	{
		cout << "File Not Opened" << endl;
		return status;
	}
}

bool USER::searchCnic(char* c)
{
	fstream fs;
	bool status = false;
	fs.open("Users.txt", ios::binary | ios::in);
	if (fs.is_open())
	{
		USER temp;
		while (fs.eof() == false)
		{
			fs.read((char*)&temp, sizeof(USER));
			if (strcmp(temp.cnic, c) == 0)
			{
				cout << "CNIC Found!" << endl;
				*this = temp;
				status = true;
				return status;
				break;
			}
		}
		fs.close();
		return status;
	}
	else
	{
		cout << "File Not Opened" << endl;
		return status;
	}


}


void USER::bookFlight()
{

}

void USER::changeFlight()
{

}

void USER::cancelFlight()
{
}


void USER::setFirstName(char* fn)
{
	strcpy_s(firstName, 20, fn);
}

void USER::setLastName(char* ln)
{
	strcpy_s(lastName, 20, ln);
}

void USER::setAge(int a)
{
	age = a;
}

void USER::setCnic(char* c)
{
	strcpy_s(cnic, 20, c);
}

void USER::setUserName(char* un)
{
	strcpy_s(userName, 20, un);
}

void USER::setPassWord(char* p)
{
	strcpy_s(passWord, 20, p);
}

void USER::setPassport(bool p)
{
	passport = p;
}

void USER::setVisa(bool v)
{
	visa = v;
}

void USER::setCounterTravellers(int c)
{
	counterTravellers = c;
}

void USER::setPassengers(BOOKING* pss)
{
	passengers = pss;
}

void USER::setAllDataEntered(bool ade)
{
	allDataEntered = ade;
}

void USER::setBooked(bool b)
{
	booked = b;
}

void USER::setBookedForMore(bool bfm)
{
	bookedForMore = bfm;
}

char* USER::getFirstName() const
{
	return firstName;
}

char* USER::getLastName() const
{
	return lastName;
}

int USER::getAge() const
{
	return age;
}

char* USER::getCnic() const
{
	return cnic;
}

char* USER::getUserName() const
{
	return userName;
}

char* USER::getPassWord() const
{
	return passWord;
}

bool USER::getPassport() const
{
	return passport;
}

bool USER::getVisa() const
{
	return visa;
}

int USER::getCounterTravellers() const
{
	return counterTravellers;
}

BOOKING* USER::getPassengers() const
{
	return passengers;
}

bool USER::getAllDataEntered() const
{
	return allDataEntered;
}

bool USER::getBooked() const
{
	return booked;
}

bool USER::getBookedForMore() const
{
	return bookedForMore;
}

USER::~USER()
{
}

PLANE::PLANE() : sizeOfArray(20)
{
	flightName = new char[sizeOfArray];

	for (int i = 0; i < sizeOfArray; i++)
	{
		flightName[i] = '-';
	}

	day = -1;
	month = -1;
	year = -1;

	AIRPORT obj;
	fromAirport = &obj;
	toAirport = &obj;

	covidRestriction = false;
	passengerSeats = new USER[50];
	takeoff = false;
	land = false;

	direct = false;
	indirect = false;
	localFlight = false;
	IntFlight = false;

	dep = -1;
	arr = -1;
	cost = 0;
}

PLANE::PLANE(char* fn, USER* ps, AIRPORT* fA, AIRPORT* tA, int d, int m, int y, bool cr, bool t, bool l, bool dir, bool ind, bool l_f, bool i_f, int de, int ar) : sizeOfArray(20)
{
	flightName = new char[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		flightName[i] = '-';
		flightName[i] = fn[i];
	}

	day = d;
	month = m;
	year = y;

	fromAirport = fA;
	toAirport = tA;

	covidRestriction = cr;
	if (covidRestriction == true)
	{
		passengerSeats = new USER[30];
	}
	else
	{
		passengerSeats = passengerSeats = new USER[50];;
	}

	passengerSeats = ps;
	takeoff = t;
	land = l;

	direct = dir;
	indirect = ind;
	localFlight = l_f;
	IntFlight = i_f;

	dep = de;
	arr = ar;

}

PLANE::PLANE(const PLANE& copyPlaneObj) : sizeOfArray(20)
{
	flightName = copyPlaneObj.flightName;
	covidRestriction = copyPlaneObj.covidRestriction;
	day = copyPlaneObj.day;
	month = copyPlaneObj.month;
	year = copyPlaneObj.year;
	fromAirport = copyPlaneObj.fromAirport;
	toAirport = copyPlaneObj.toAirport;
	passengerSeats = copyPlaneObj.passengerSeats;
	takeoff = copyPlaneObj.takeoff;
	land = copyPlaneObj.land;
	direct = copyPlaneObj.direct;
	indirect = copyPlaneObj.indirect;
	localFlight = copyPlaneObj.localFlight;
	IntFlight = copyPlaneObj.IntFlight;
	dep = copyPlaneObj.dep;
	arr = copyPlaneObj.arr;

}

void PLANE::print()
{
	cout << "Flight Name: " << flightName << "\t";
	cout << day << "/" << month << "/" << year << "\t";
	cout << "From Airport: " << fromAirport->getName() << "\t" << fromAirport->getCountry().getCountryName() << "\t\t";
	cout << "Departure : " << dep << "\t";
	cout << "To Airport: " << toAirport->getName() << "\t" << toAirport->getCountry().getCountryName() << "\t\t";
	cout << "Arrival : " << arr << "\t";
}

void PLANE::setPlaneAllDetails(char* fn, USER* ps, AIRPORT* fA, AIRPORT* tA, int d, int m, int y, bool cr, bool t, bool l, bool dir, bool ind, bool l_f, bool i_f, int de, int ar)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		flightName[i] = '-';
		flightName[i] = fn[i];
	}
	day = d;
	month = m;
	year = y;
	fromAirport = fA;
	toAirport = tA;
	covidRestriction = cr;
	if (covidRestriction == true)
	{
		passengerSeats = new USER[30];
	}
	else
	{
		passengerSeats = new USER[50];
	}
	passengerSeats = ps;
	takeoff = t;
	land = l;
	direct = dir;
	indirect = ind;
	localFlight = l_f;
	IntFlight = i_f;

	dep = de;
	arr = ar;

	if (l_f == true)
	{
		cost = 0;
		cost = (arr - dep) * 10000;
	}
	else
	{
		cost = 0;
		cost = (arr - dep) * 20000;
	}



}

void PLANE::addSeat(USER& newSeat)
{
	if (covidRestriction == true)
	{
		for (int i = 0; i < 30; i++)
		{
			if (passengerSeats[i].getAge() == -1)
			{
				passengerSeats[i] = newSeat;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < 50; i++)
		{
			if (passengerSeats[i].getAge() == -1)
			{
				passengerSeats[i] = newSeat;
				break;
			}
		}
	}
}

void PLANE::removeSeat(USER& removeSeat)
{
	if (covidRestriction == true)
	{
		for (int i = 0; i < 30; i++)
		{
			if (strcmp(passengerSeats[i].getCnic(), removeSeat.getCnic()) == 0)
			{
				USER obj;
				passengerSeats[i] = obj;
			}
		}
	}
	else
	{
		for (int i = 0; i < 50; i++)
		{
			if (strcmp(passengerSeats[i].getCnic(), removeSeat.getCnic()) == 0)
			{
				USER obj;
				passengerSeats[i] = obj;
			}
		}
	}
}

void PLANE::setFlightName(char* fn)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		flightName[i] = '-';
		flightName[i] = fn[i];
	}
}

void PLANE::setPassengerSeats(USER* ps)
{
	passengerSeats = NULL;
	passengerSeats = ps;
}

void PLANE::setDay(int d)
{
	day = d;
}

void PLANE::setMonth(int m)
{
	month = m;
}

void PLANE::setYear(int y)
{
	year = y;
}

void PLANE::setFromAirport(AIRPORT* fA)
{
	fromAirport = fA;
}

void PLANE::setToAirport(AIRPORT* tA)
{
	toAirport = tA;
}

void PLANE::setCovidRestriction(bool cr)
{
	covidRestriction = cr;

	passengerSeats = NULL;
	if (covidRestriction == true)
	{
		passengerSeats = new USER[30];
	}
	else
	{
		passengerSeats = passengerSeats = new USER[50];;
	}
}

void PLANE::setTakeoff(bool t)
{
	takeoff = t;
}

void PLANE::setLand(bool l)
{
	land = l;
}

void PLANE::setDirect(bool dir)
{
	direct = dir;
}

void PLANE::setIndirect(bool ind)
{
	indirect = ind;
}

void PLANE::setLocalFlight(bool l_f)
{
	localFlight = l_f;
}

void PLANE::setIntFlight(bool i_f)
{
	IntFlight = i_f;
}

void PLANE::setDep(int de)
{
	dep = de;
}

void PLANE::setArr(int ar)
{
	arr = ar;
}

char* PLANE::getFlightName() const
{
	return flightName;
}

USER* PLANE::getPassengerSeats() const
{
	return passengerSeats;
}

int PLANE::getDay() const
{
	return day;
}

int PLANE::getMonth() const
{
	return month;
}

int PLANE::getYear() const
{
	return year;
}

AIRPORT* PLANE::getFromAirport() const
{
	return fromAirport;
}

AIRPORT* PLANE::getToAirport() const
{
	return toAirport;
}

bool PLANE::getCovidRestriction() const
{
	return covidRestriction;
}

bool PLANE::getTakeoff() const
{
	return takeoff;
}

bool PLANE::getLand() const
{
	return land;
}

bool PLANE::getDirect() const
{
	return direct;
}

bool PLANE::getIndirect() const
{
	return indirect;
}

bool PLANE::getLocalFlight() const
{
	return localFlight;
}

bool PLANE::getIntFlight() const
{
	return IntFlight;
}

int PLANE::getDep() const
{
	return dep;
}

int PLANE::getArr() const
{
	return arr;
}

double PLANE::getCost() const
{
	return cost;
}

void PLANE::operator=(const PLANE& planeObj)
{
	flightName = NULL;
	flightName = new char[4];
	strcpy_s(flightName, 4, planeObj.flightName);
	passengerSeats = NULL;
	passengerSeats = new USER[50];
	for (int i = 0; i < 50; i++)
	{
		passengerSeats[i] = planeObj.passengerSeats[i];
	}
	day = planeObj.day;
	month = planeObj.month;
	year = planeObj.year;
	fromAirport = planeObj.fromAirport;
	toAirport = planeObj.toAirport;
	covidRestriction = planeObj.covidRestriction;
	takeoff = planeObj.takeoff;
	land = planeObj.land;
	direct = planeObj.direct;
	indirect = planeObj.indirect;
	localFlight = planeObj.localFlight;
	IntFlight = planeObj.IntFlight;
	dep = planeObj.dep;
	arr = planeObj.arr;
	cost = planeObj.cost;
}

PLANE::~PLANE()
{
}

ostream& operator << (ostream& out, const  PLANE& planeObj)
{
	out << "Cost : " << planeObj.getCost() << endl;
	Sleep(500);
	return out;
}

ADMIN::ADMIN() : sizeOfArray(20)
{
	firstName = new char[sizeOfArray];
	lastName = new char[sizeOfArray];
	userName = new char[sizeOfArray];
	passWord = new char[sizeOfArray];

	for (int i = 0; i < sizeOfArray; i++)
	{
		firstName[i] = '-';
		lastName[i] = '-';
		userName[i] = '-';
		passWord[i] = '-';
	}
}

ADMIN::ADMIN(char* fn, char* ln, char* un, char* pw) : sizeOfArray(20)
{
	firstName = new char[sizeOfArray];
	lastName = new char[sizeOfArray];
	userName = new char[sizeOfArray];
	passWord = new char[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		firstName[i] = '-';
		lastName[i] = '-';
		userName[i] = '-';
		passWord[i] = '-';
		firstName[i] = fn[i];
		lastName[i] = ln[i];
		userName[i] = un[i];
		passWord[i] = pw[i];
	}
}

ADMIN::ADMIN(const ADMIN& copyAdminObj) : sizeOfArray(20)
{
	firstName = copyAdminObj.firstName;
	lastName = copyAdminObj.lastName;
	userName = copyAdminObj.userName;
	passWord = copyAdminObj.passWord;
}

void ADMIN::setFirstName(char* fn)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		firstName[i] = fn[i];
	}
}

void ADMIN::setLastName(char* ln)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		lastName[i] = ln[i];
	}
}

void ADMIN::setUserName(char* un)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		userName[i] = un[i];
	}
}

void ADMIN::setPassWord(char* pw)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		passWord[i] = pw[i];
	}
}

char* ADMIN::getFirstName() const
{
	return firstName;
}

char* ADMIN::getLastName() const
{
	return lastName;
}

char* ADMIN::getUserName() const
{
	return userName;
}

char* ADMIN::getPassWord() const
{
	return passWord;
}

void ADMIN::addObj()   // ch
{
	ADMIN addAdminObj;
}

void ADMIN::deleteObj()
{
	ADMIN deleteAdminObj;
}

void ADMIN::covidBan(AIRPORT& banAirportObj)
{
	banAirportObj.setCovidBan(true);
}

void ADMIN::covidUnban(AIRPORT& unBanAirportObj)
{
	unBanAirportObj.setCovidBan(false);
}

void ADMIN::setCovidRestrictionOnPlane(PLANE& setPlaneObj)
{
	setPlaneObj.setCovidRestriction(true);
}

void ADMIN::removeCovidRestrictionOnPlane(PLANE& setPlaneObj)
{
	setPlaneObj.setCovidRestriction(false);
}

void ADMIN::flightTakeoff(PLANE& setPlaneObj)
{
	setPlaneObj.setTakeoff(true);
}

void ADMIN::flightLand(PLANE& setPlaneObj)
{
	setPlaneObj.setLand(false);
}

ADMIN::~ADMIN()
{
}


int main()
{
	int input = -1;

	bool adminLoginFlag = false;
	bool userLoginFlag = false;



	// DATA 
	COUNTRY* countriesObj = new COUNTRY[26]; // 1 is Pakistan and Rest are other countries

	char * countryName = new char[20];
	char * cityName = new char[20];
	 

	strcpy_s (countryName, 20, "Pakistan");
	strcpy_s (cityName, 20, "Islamabad");
	countriesObj[0].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Pakistan");
	strcpy_s(cityName, 20, "Lahore");
	countriesObj[1].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Pakistan");
	strcpy_s(cityName, 20, "Karachi");
	countriesObj[2].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Pakistan");
	strcpy_s(cityName, 20, "Peshawar");
	countriesObj[3].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Pakistan");
	strcpy_s(cityName, 20, "Quetta");
	countriesObj[4].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Switzerland");
	strcpy_s(cityName, 20, "Zurich");
	countriesObj[5].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Germany");
	strcpy_s(cityName, 20, "Berlin");
	countriesObj[6].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "France");
	strcpy_s(cityName, 20, "Paris");
	countriesObj[7].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "England");
	strcpy_s(cityName, 20, "London");
	countriesObj[8].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Turkey");
	strcpy_s(cityName, 20, "Istanbul");
	countriesObj[9].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "China");
	strcpy_s(cityName, 20, "Beijing");
	countriesObj[10].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "India");
	strcpy_s(cityName, 20, "New Delhi");
	countriesObj[11].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "USA");
	strcpy_s(cityName, 20, "New York");
	countriesObj[12].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Canada");
	strcpy_s(cityName, 20, "Ottowa");
	countriesObj[13].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Australia");
	strcpy_s(cityName, 20, "Sydney");
	countriesObj[14].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "New Zealand");
	strcpy_s(cityName, 20, "Wellington");
	countriesObj[15].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Japan");
	strcpy_s(cityName, 20, "Tokyo");
	countriesObj[16].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "South Korea");
	strcpy_s(cityName, 20, "Seoul");
	countriesObj[17].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Oman");
	strcpy_s(cityName, 20, "Muscat");
	countriesObj[18].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Argentina");
	strcpy_s(cityName, 20, "Buenos Aires");
	countriesObj[19].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "South Africa");
	strcpy_s(cityName, 20, "Cape Town");
	countriesObj[20].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Egypt");
	strcpy_s(cityName, 20, "Cairo");
	countriesObj[21].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Saudi Arabia");
	strcpy_s(cityName, 20, "Jeddah");
	countriesObj[22].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "UAE");
	strcpy_s(cityName, 20, "Dubai");
	countriesObj[23].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Afghanistan");
	strcpy_s(cityName, 20, "Kabul");
	countriesObj[24].setCountryAllDetails(countryName, cityName);

	strcpy_s(countryName, 20, "Iran");
	strcpy_s(cityName, 20, "Tehran");
	countriesObj[25].setCountryAllDetails(countryName, cityName);




	AIRPORT* airportsObj = new AIRPORT[30];

	char* airportName = new char[4];
	char NS = '-';

	for (int i = 0; i < 4; i++)
	{
		airportName[i] = '-';
	}

	strcpy_s(airportName, 4, "ISB");
	NS = 'N';
	airportsObj[0].setAirportAllDetails(airportName,countriesObj[0] , true , NS, false);

	strcpy_s(airportName, 4, "ISB");
	NS = 'S';
	airportsObj[1].setAirportAllDetails(airportName, countriesObj[0], true, NS, false);

	strcpy_s(airportName, 4, "LHE");
	NS = 'N';
	airportsObj[2].setAirportAllDetails(airportName, countriesObj[1], true, NS, false);

	strcpy_s(airportName, 4, "LHE");
	NS = 'S';
	airportsObj[3].setAirportAllDetails(airportName, countriesObj[1], true, NS, false);

	strcpy_s(airportName, 4, "KHI");
	NS = 'N';
	airportsObj[4].setAirportAllDetails(airportName, countriesObj[2], true, NS, false);

	strcpy_s(airportName, 4, "KHI");
	NS = 'S';
	airportsObj[5].setAirportAllDetails(airportName, countriesObj[2], true, NS, false);

	strcpy_s(airportName, 4, "PEW");
	NS = 'N';
	airportsObj[6].setAirportAllDetails(airportName, countriesObj[3], true, NS, false);

	strcpy_s(airportName, 4, "PEW");
	NS = 'S';
	airportsObj[7].setAirportAllDetails(airportName, countriesObj[3], true, NS, false);

	strcpy_s(airportName, 4, "QTA");
	NS = 'N';
	airportsObj[8].setAirportAllDetails(airportName, countriesObj[4], true, NS, false);

	strcpy_s(airportName, 4, "QTA");
	NS = 'S';
	airportsObj[9].setAirportAllDetails(airportName, countriesObj[4], true, NS, false);

	strcpy_s(airportName, 4, "ZRH");
	NS = '-';
	airportsObj[10].setAirportAllDetails(airportName, countriesObj[5], false, NS, false);

	strcpy_s(airportName, 4, "BER");
	NS = '-';
	airportsObj[11].setAirportAllDetails(airportName, countriesObj[6], false, NS, false);

	strcpy_s(airportName, 4, "PAR");
	NS = '-';
	airportsObj[12].setAirportAllDetails(airportName, countriesObj[7], false, NS, false);

	strcpy_s(airportName, 4, "LON");
	NS = '-';
	airportsObj[13].setAirportAllDetails(airportName, countriesObj[8], false, NS, false);

	strcpy_s(airportName, 4, "IST");
	NS = '-';
	airportsObj[14].setAirportAllDetails(airportName, countriesObj[9], false, NS, false);

	strcpy_s(airportName, 4, "BEI");
	NS = '-';
	airportsObj[15].setAirportAllDetails(airportName, countriesObj[10], false, NS, false);

	strcpy_s(airportName, 4, "NDI");
	NS = '-';
	airportsObj[16].setAirportAllDetails(airportName, countriesObj[11], false, NS, false);

	strcpy_s(airportName, 4, "NYK");
	NS = '-';
	airportsObj[17].setAirportAllDetails(airportName, countriesObj[12], false, NS, false);

	strcpy_s(airportName, 4, "OTA");
	NS = '-';
	airportsObj[18].setAirportAllDetails(airportName, countriesObj[13], false, NS, false);

	strcpy_s(airportName, 4, "SNY");
	NS = '-';
	airportsObj[19].setAirportAllDetails(airportName, countriesObj[14], false, NS, false);

	strcpy_s(airportName, 4, "WLN");
	NS = '-';
	airportsObj[20].setAirportAllDetails(airportName, countriesObj[15], false, NS, false);

	strcpy_s(airportName, 4, "TKO");
	NS = '-';
	airportsObj[21].setAirportAllDetails(airportName, countriesObj[16], false, NS, false);

	strcpy_s(airportName, 4, "SOL");
	NS = '-';
	airportsObj[22].setAirportAllDetails(airportName, countriesObj[17], false, NS, false);

	strcpy_s(airportName, 4, "MCT");
	NS = '-';
	airportsObj[23].setAirportAllDetails(airportName, countriesObj[18], false, NS, false);

	strcpy_s(airportName, 4, "BNA");
	NS = '-';
	airportsObj[24].setAirportAllDetails(airportName, countriesObj[19], false, NS, false);

	strcpy_s(airportName, 4, "CPN");
	NS = '-';
	airportsObj[24].setAirportAllDetails(airportName, countriesObj[20], false, NS, false);

	strcpy_s(airportName, 4, "CIO");
	NS = '-';
	airportsObj[25].setAirportAllDetails(airportName, countriesObj[21], false, NS, false);

	strcpy_s(airportName, 4, "JDH");
	NS = '-';
	airportsObj[26].setAirportAllDetails(airportName, countriesObj[22], false, NS, false);

	strcpy_s(airportName, 4, "DBI");
	NS = '-';
	airportsObj[27].setAirportAllDetails(airportName, countriesObj[23], false, NS, false);

	strcpy_s(airportName, 4, "KBL");
	NS = '-';
	airportsObj[28].setAirportAllDetails(airportName, countriesObj[24], false, NS, false);

	strcpy_s(airportName, 4, "THN");
	NS = '-';
	airportsObj[29].setAirportAllDetails(airportName, countriesObj[25], false, NS, false);


	PLANE* planesObj = new PLANE[50];
	char* flightName = new char[20];
	USER * usersObj = new USER[50];

	strcpy_s(flightName , 20, "PK-341");
	planesObj[0].setPlaneAllDetails(flightName, usersObj, &airportsObj[0], &airportsObj[2], 1, 2, 2023, false, false, false, true, false, true, false , 0 , 2);

	strcpy_s(flightName, 20, "PK-342");
	planesObj[1].setPlaneAllDetails(flightName, usersObj, &airportsObj[3], &airportsObj[4], 1, 2, 2023, false, false, false, true, false, true, false , 3 , 5);

	strcpy_s(flightName, 20, "PK-343");
	planesObj[2].setPlaneAllDetails(flightName, usersObj, &airportsObj[5], &airportsObj[6], 1, 2, 2023, false, false, false, true, false, true, false , 4 , 7);

	strcpy_s(flightName, 20, "PK-344");
	planesObj[3].setPlaneAllDetails(flightName, usersObj, &airportsObj[7], &airportsObj[8], 1, 2, 2023, false , false , false , true , false , false , true , 5 , 11);

	strcpy_s(flightName, 20, "PK-345");
	planesObj[4].setPlaneAllDetails(flightName, usersObj, &airportsObj[0], &airportsObj[10], 1, 2, 2023, false, false, false, true, false, false, true , 6 , 11);

	strcpy_s(flightName, 20, "PK-346");
	planesObj[5].setPlaneAllDetails(flightName, usersObj, &airportsObj[11], &airportsObj[12], 1, 2, 2023 , false ,false ,false, false, true , false , true , 7 , 13);

	strcpy_s(flightName, 20, "PK-347");
	planesObj[6].setPlaneAllDetails(flightName, usersObj, &airportsObj[13], &airportsObj[14], 1, 2, 2023, false, false, false, true, false, true, false , 8 , 14);

	strcpy_s(flightName, 20, "PK-348");
	planesObj[7].setPlaneAllDetails(flightName, usersObj, &airportsObj[15], &airportsObj[16], 1, 2, 2023, false, false, false, true, false, true, false , 9 , 15);

	strcpy_s(flightName, 20, "PK-349");
	planesObj[8].setPlaneAllDetails(flightName, usersObj, &airportsObj[17], &airportsObj[18], 1, 2, 2023, false, false, false, true, false, true, false , 10 , 18);

	strcpy_s(flightName, 20, "PK-350");
	planesObj[9].setPlaneAllDetails(flightName, usersObj, &airportsObj[19], &airportsObj[20], 1, 2, 2023, false, false, false, true, false, true, false , 11 , 19);

	strcpy_s(flightName, 20, "PK-351");
	planesObj[10].setPlaneAllDetails(flightName, usersObj, &airportsObj[0], &airportsObj[1], 1, 2, 2023, false, false, false, true, false, true, false , 12 , 14);

	strcpy_s(flightName, 20, "PK-352");
	planesObj[11].setPlaneAllDetails(flightName, usersObj, &airportsObj[0], &airportsObj[3], 1, 2, 2023, false, false, false, true, false, true, false , 13 , 15);

	strcpy_s(flightName, 20, "PK-353");
	planesObj[12].setPlaneAllDetails(flightName, usersObj, &airportsObj[2], &airportsObj[4], 1, 2, 2023, false, false, false, true, false, true, false , 19 , 21);

	strcpy_s(flightName, 20, "PK-354");
	planesObj[13].setPlaneAllDetails(flightName, usersObj, &airportsObj[1], &airportsObj[2], 1, 2, 2023, false, false, false, true, false, true, false , 20 , 22);

	strcpy_s(flightName, 20, "PK-355");
	planesObj[14].setPlaneAllDetails(flightName, usersObj, &airportsObj[4], &airportsObj[1], 1, 2, 2023, false, false, false, true, false, true, false , 20 , 22);




	PLANE objPlane;
	USER objRegister;

	while (input != 4)
	{
		system("cls");
		cout << "-------------------------------------- WELCOME TO NUCES AIRLINE FLIGHT SYSTEM --------------------------------------" << endl << endl;

		cout << "1. Login" << endl;
		cout << "2. Register" << endl;
		cout << "3. View Flights" << endl;
		cout << "4. Exit" << endl << endl;

		cout << "Enter your choice: ";
		cin >> input;

		while (input < 1 || input > 4)
		{
			cout << "Invalid Input! Please enter again: ";
			cin >> input;
		}

		system("cls");

		switch (input)
		{
			case 1:
			{
				int loginInput = -1;

				int sizeOfArray = 20;
				char* username = new char[sizeOfArray];
				char* password = new char[sizeOfArray];
				
				for (int i = 0; i < 20; i++)
				{
					username[i] = '-';
					password[i] = '-';
				}
				username[19] = '\0';
				password[19] = '\0';


				cout << "-------------------------------------- LOGIN --------------------------------------" << endl << endl;

				cout << "1 For Admin Login" << endl;
				cout << "2 For User Login" << endl << endl;
				cout << "3. Go Back" << endl;

				cout << "Enter your choice: ";
				cin >> loginInput;

				while (loginInput < 1 || loginInput > 3)
				{
					cout << "Invalid Input! Please enter again: ";
					cin >> loginInput;
				}

				system("cls");

				switch (loginInput)
				{
					case 1:
					{
						cout << "-------------------------------------- ADMIN LOGIN --------------------------------------" << endl << endl;
						
						cout << "Enter Username: ";
						cin >> username;

						cout << "Enter Password: ";
						cin >> password;

						if (strcmp(username, "@@@ADMIN_NAFS@@@") == 0 && strcmp(password, "admin") == 0)
						{
							cout << endl << "Login Successful!" << endl;
							adminLoginFlag = true;
						}
						else
						{
							cout << endl << "Login Failed!" << endl;
						}

						Sleep(5000);

						if (adminLoginFlag == true)
						{
							int adminInput = -1;

							while (adminInput != 8)
							{
								cout << "-------------------------------------- ADMIN MENU --------------------------------------" << endl << endl;

								cout << "1. Impose Covid restriction on Flight" << endl;
								cout << "2. Remove Covid restriction on Flight" << endl;
								cout << "3. Impose Covid restriction on Country" << endl;
								cout << "4. Remove Covid restriction on Country" << endl;
								cout << "5. Update Flight Scheedule" << endl;
								cout << "6. Update Flight Status" << endl;
								cout << "7. Update Flight Route" << endl;
								cout << "8. Go Back" << endl << endl;

								cout << "Enter your choice: ";
								cin >> adminInput;

								while (adminInput < 1 || adminInput > 7)
								{
									cout << "Invalid Input! Please enter again: ";
									cin >> adminInput;
								}

								system("cls");

								switch (adminInput)
								{
								case 1:
								{
									cout << "-------------------------------------- IMPOSE COVID RESTRICTION ON FLIGHT --------------------------------------" << endl << endl;
									int flightNumber = -1;
									for (int i = 0; i < 15; i++)
									{
										cout << i + 1 << ". "; planesObj[i].print();  cout << endl;
									}

									cout << endl << "Input : ";
									cin >> flightNumber;

									while (flightNumber < 1 || flightNumber > 15)
									{
										cout << "Invalid Input! Please enter again: ";
										cin >> flightNumber;
									}

									planesObj[flightNumber - 1].setCovidRestriction(true);

									cout << "Restricition Imposed !";

									break;
								}
								case 2:
								{
									cout << "-------------------------------------- REMOVE COVID RESTRICTION ON FLIGHT --------------------------------------" << endl << endl;
									int flightNumber = -1;
									for (int i = 0; i < 15; i++)
									{
										cout << i + 1 << ". "; planesObj[i].print(); cout << endl;
									}
									cout << endl << "Input : ";
									cin >> flightNumber;
									while (flightNumber < 1 || flightNumber > 15)
									{
										cout << "Invalid Input! Please enter again: ";
										cin >> flightNumber;
									}
									planesObj[flightNumber - 1].setCovidRestriction(false);
									cout << "Restricition Removed !";
									break;
								}

								case 3:
								{
									cout << "-------------------------------------- IMPOSE COVID RESTRICTION ON COUNTRY --------------------------------------" << endl << endl;
									int countryNumber = -1;

									for (int i = 0; i < 30; i++)
									{
										cout << i + 1 << ". " << airportsObj[i].getName() << " / " << airportsObj[i].getNS() << airportsObj[i].getCountry().getCountryName(); cout << endl;
									}

									cout << endl << "Input : ";
									cin >> countryNumber;

									while (countryNumber < 1 || countryNumber > 30)
									{
										cout << "Invalid Input! Please enter again: ";
										cin >> countryNumber;
									}

									airportsObj[countryNumber - 1].setCovidBan(true);

									cout << "Restricition Imposed !";
									break;
								}

								case 4:
								{
									cout << "-------------------------------------- REMOVE COVID RESTRICTION ON COUNTRY --------------------------------------" << endl << endl;
									int countryNumber = -1;
									for (int i = 0; i < 30; i++)
									{
										cout << i + 1 << ". " << airportsObj[i].getName() << " / " << airportsObj[i].getNS() << airportsObj[i].getCountry().getCountryName(); cout << endl;
									}
									cout << endl << "Input : ";
									cin >> countryNumber;
									while (countryNumber < 1 || countryNumber > 30)
									{
										cout << "Invalid Input! Please enter again: ";
										cin >> countryNumber;
									}
									airportsObj[countryNumber - 1].setCovidBan(false);
									cout << "Restricition Removed !";
									break;
								}

								case 5:
								{
									cout << "-------------------------------------- UPDATE FLIGHT SCHEDULE --------------------------------------" << endl << endl;
									int flightNumber = -1;
									for (int i = 0; i < 15; i++)
									{
										cout << i + 1 << ". "; planesObj[i].print();
										cout << planesObj[i] ;
										cout << endl;
									}
									cout << endl << "Input : ";
									cin >> flightNumber;
									while (flightNumber < 1 || flightNumber > 15)
									{
										cout << "Invalid Input! Please enter again: ";
										cin >> flightNumber;
									}

									int dep = 0;
									int arr = 0;
									cout << "Enter Departure Time: ";
									cin >> dep;
									cout << "Enter Arrival Time: ";
									cin >> arr;
									planesObj[flightNumber - 1].setDep(dep);
									planesObj[flightNumber - 1].setArr(arr);
									cout << "Flight Schedule Updated !";
									break;
								}

								case 6:
								{
									cout << "-------------------------------------- UPDATE FLIGHT STATUS --------------------------------------" << endl << endl;
									int flightNumber = -1;
									for (int i = 0; i < 15; i++)
									{
										cout << i + 1 << ". "; planesObj[i].print();
										cout <<planesObj[i];
										cout << endl;
									}
									cout << endl << "Input : ";
									cin >> flightNumber;
									while (flightNumber < 1 || flightNumber > 15)
									{
										cout << "Invalid Input! Please enter again: ";
										cin >> flightNumber;
									}

									bool status;
									cout << "Enter TakeOff Status: ";
									cin >> status;
									planesObj[flightNumber - 1].setTakeoff(status);

									cout << "Enter Landing Status: ";
									cin >> status;
									planesObj[flightNumber - 1].setLand(status);

									cout << "Flight Status Updated !";
									break;
								}

								case 7:
								{
									cout << "-------------------------------------- UPDATE FLIGHT RO--------------------------------------" << endl << endl;
									int flightNumber = -1;
									for (int i = 0; i < 15; i++)
									{
										cout << i + 1 << ". "; planesObj[i].print();
										cout <<planesObj[i];
										cout << endl;
									}
									cout << endl << "Input : ";
									cin >> flightNumber;
									while (flightNumber < 1 || flightNumber > 15)
									{
										cout << "Invalid Input! Please enter again: ";
										cin >> flightNumber;
									}


									int dep = 0;
									int arr = 0;

									for (int i = 0; i < 30; i++)
									{
										if (airportsObj[i].getCovidBan() == true)
										{
											airportsObj->print();
										}
									}

									cout << "Enter Departure Airport: ";
									cin >> dep;
									cout << "Enter Arrival Airport: ";
									cin >> arr;

									planesObj[flightNumber - 1].setFromAirport(&airportsObj[dep]);
									planesObj[flightNumber - 1].setToAirport(&airportsObj[arr]);

									cout << "Flight Schedule Updated !";
									break;
								}

								}
							}

						}
						

						break;
					}
					case 2:
					{
						cout << "-------------------------------------- USER LOGIN --------------------------------------" << endl << endl;
						int userInput = -1;
						bool status = false;
						int minorCount = 0;
						int loginUserInput = -1;
						int bookInput = -1;
						bool userLogin = false;
						USER obj1;
						while (userInput != 3 )
						{
							cout << "1. Login"<<endl;
							cout << "2. Recovery" << endl;
							cout << "3. Go Back " << endl;

							cout << endl << "Input : ";
							cin >> userInput;


							
							switch (userInput)
							{
							    case 1:
									
									cout<< "-------------------------------------- LOGIN --------------------------------------" << endl << endl;	
									cout << "Enter Username: ";
									cin >> username;

									cout << "Enter Password: ";
									cin >> password;

									
									status = obj1.searchUsername(username);
							
									
									if (status == true)
									{
										if (strcmp(obj1.getPassWord(), password) == 0)
										{
											userLogin = true;
										}
									}
									else
									{
										cout << "Invalid Username or Password !";
									}

									while (userLogin == true)
									{
										cout<< "-------------------------------------- USER MENU --------------------------------------" << endl << endl;
										cout << "1. Book Flight"<<endl;
										cout << "2. Cancel Flight" << endl;
										cout << "3. Register A Minor" << endl;
										cout << "4. Log Out " << endl;

										cout << endl << "Input : ";
										cin >> loginUserInput;
										
										switch (loginUserInput)
										{
										case 1:

											for (int i = 0; i < 15; i++)
											{
												cout << i + 1 << ". "; planesObj[i].print();
												cout << planesObj[i];
												cout << endl;
											}

											cout << endl << "Input : ";
											cin >> bookInput;

											while (bookInput < 1 || bookInput > 15)
											{
												cout << "Invalid Input! Please enter again: ";
												cin >> bookInput;
											}
											
											obj1.bookFlight();
											break;
										case 2:
											cout<< "-------------------------------------- CANCEL FLIGHT --------------------------------------" << endl << endl;
											obj1.cancelFlight();

											break;

										case 3:

											cout << "-------------------------------------- REGISTER MINOR --------------------------------------" << endl << endl;
											obj1.addObj();

										break;

										case 4:
											userLogin = false;
											break;
										}
									}
								break;

								case 2:

								break;

								default:
								break;
							}
						}	
						break;
					}
					case 3:
						break;
				}
				break;
			}
			// Register 
			case 2: 

				cout << "-------------------------------------- REGISTER --------------------------------------" << endl << endl;
				objRegister.userInput();
				objRegister.addUserToFile(objRegister);


				break;

				// View Flight Schedule
			case 3:
				system("cls");
				cout << "-------------------------------------- FLIGHT SCHEDULE --------------------------------------" << endl << endl;

				for (int i = 0; i < 15; i++)
				{
					
					cout << i + 1 << ". "; planesObj[i].print();
					cout << planesObj[i];
					cout << endl;
				}

				Sleep(5000);
				break;

				// Exit
			case 4:
				input = 4;
				break;
		}
	}
	delete[] countryName;
	delete[] cityName;
	countryName = NULL;
	cityName = NULL;

	delete[] airportsObj;
	airportsObj = NULL;

	delete[] planesObj;
	planesObj = NULL;

	return 0;
}
