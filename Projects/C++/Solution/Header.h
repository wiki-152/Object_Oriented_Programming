#pragma once

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

using namespace std;

// ------------------------------------------- FUNCTIONS -------------------------------------------

bool checkPassword(char* password)
{
	bool UpperCase = false, LowerCase = false, Digit = false, SpecialChar = false, lenght = false;

	int counter = 0;
	while (password[counter] != '\0')
	{
		if (password[counter] >= 'A' && password[counter] <= 'Z')
		{
			UpperCase = true;
		}
		if (password[counter] >= 'a' && password[counter] <= 'z')
		{
			LowerCase = true;
		}
		if (password[counter] >= '0' && password[counter] <= '9')
		{
			Digit = true;
		}

		if ((password[counter] >= 33 && password[counter] <= 47) || (password[counter] >= 58 && password[counter] <= 64) || (password[counter] >= 91 && password[counter] <= 96) || (password[counter] >= 123 && password[counter] <= 126))
		{
			SpecialChar = true;
		}
		counter++;
	}

	if (counter >= 8)
	{
		lenght = true;
	}

	if (UpperCase == true && LowerCase == true && Digit == true && SpecialChar == true && lenght == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// -------------------------------------------ABSTRACT CLASS-------------------------------------------

class ABSTRACTCLASS
{
public:
	ABSTRACTCLASS();

	virtual void addObj() = 0;
	virtual void deleteObj() = 0;

	~ABSTRACTCLASS();

private:
	char* firstName;
	char* lastName;
	char* username;
	char* passWord;

};

ABSTRACTCLASS::ABSTRACTCLASS()
{
}

ABSTRACTCLASS::~ABSTRACTCLASS()
{
}

// ------------------------------------------- COUNTRY CLASS -------------------------------------------

class COUNTRY
{
public:
	COUNTRY();
	COUNTRY(char* cn, char* c);
	COUNTRY(const COUNTRY& copyCountryObj);

	void setCountryName(char* cn);
	void setCity(char* c);

	void setCountryAllDetails(char* cn, char* c);

	char* getCountryName() const;
	char* getCity() const;

	void operator=(const COUNTRY& copyCountryObj);

	~COUNTRY();

private:
	const int sizeOfArray;

	char* countryName;
	char* city;

};



// ------------------------------------------- AIRPORT CLASS -------------------------------------------

class AIRPORT
{
public:
	AIRPORT();
	AIRPORT (char *n, COUNTRY c, bool cf , char ns, bool cb);
	AIRPORT (const AIRPORT& copyAirportObj);

	void setName(char *n);
	void setCountry(COUNTRY& c);
	void setCountryFilled(bool cf);
	void setNS(char ns);
	void setCovidBan(bool cb);

	void setAirportAllDetails(char* n, COUNTRY c, bool cf , char ns, bool cb);
	virtual void print();

	char* getName() const;
	COUNTRY getCountry() const;
	bool getCountryFilled() const;
	char getNS() const;
	bool getCovidBan() const;

	void operator=(const AIRPORT& copyAirportObj);

	~AIRPORT();

private:
	const int sizeOfArray;

	char* name; // Short form only 3 characters

	COUNTRY countryTravel;

	bool countryFilled;

	char NS; // North OR South OR -

	bool covidBan;

};


// ------------------------------------------- BOOKING CLASS -------------------------------------------

class BOOKING
{
public:
	BOOKING();
	BOOKING (char * fn, int d, int m, int y, AIRPORT fa, AIRPORT ta, bool faf , bool taf , bool dir, bool ind, bool l_f, bool i_f, double c, int ho, int mi, bool f);
	BOOKING (const BOOKING& copyBookingObj);

	void direct_or_indirect(); // if direct then local otherwise international

	void calculateDistance(); // First checks if data is complete then If country is same then avg travel time will be 2 hours and for international american countries 20 hours and for european 8 hours and for middle east 3 hours

	friend ofstream& operator<<(ofstream& out, const BOOKING& coutBookingObj);

	void operator=(const BOOKING& copyBookingObj);

	void input();

	void setFlightName(char* fn);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	void setFromAirport(AIRPORT& fa);
	void setToAirport(AIRPORT& ta);
	void setAirportFromFilled(bool faf);
	void setAirportToFilled(bool taf);
	void setDirect(bool dir);
	void setIndirect(bool ind);
	void setLocalFlight(bool l_f);
	void setIntFlight(bool i_f);
	void setCost(double c);
	void setHours(int ho);
	void setMins(int mi);
	void setFlown(bool f);

	char* getFlightName() const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	AIRPORT getFromAirport() const;
	AIRPORT getToAirport() const;
	bool getAirportFromFilled() const;
	bool getAirportToFilled() const;
	bool getDirect() const;
	bool getIndirect() const;
	bool getLocalFlight() const;
	bool getIntFlight() const;
	double getCost() const;
	int getHours() const;
	int getMins() const;
	bool getFlown() const;


	~BOOKING();

private:
	const int sizeOfArray;

	char* flightName;

	int day;
	int month;
	int year;

	double cost;
	int hours;
	int mins;

	bool flown;

};



// ------------------------------------------- USER CLASS -------------------------------------------

class USER : public ABSTRACTCLASS
{
public:
	USER();
	USER(char* fn, char* ln, int a, char* c, char* un, char* pw, bool p, bool v, int ct, BOOKING* pss, bool ade, USER* u18id);
	USER(const USER& copyUserObj);

	virtual void userInput();
	void operator=(const USER& copyUserObj);

	void addObj(); // UserU18
	void deleteObj(); // UserU18


	void addUserToFile(USER & obj);
	bool searchUsername(char* un);
	bool searchCnic(char* c);

	void bookFlight();
	void changeFlight();
	void cancelFlight();  // 25 % FEE DEDUCTION 

	void setFirstName(char* fn);
	void setLastName(char* ln);
	void setAge(int a);
	void setCnic(char* c);
	void setUserName(char* un);
	void setPassWord(char* pw);
	void setPassport(bool p);
	void setVisa(bool v);
	void setCounterTravellers(int ct);
	void setPassengers(BOOKING* pss);
	void setAllDataEntered(bool ade);
	void setBooked(bool b);
	void setBookedForMore(bool bfm);

	char* getFirstName() const;
	char* getLastName() const;
	int getAge() const;
	char* getCnic() const;
	char* getUserName() const;
	char* getPassWord() const;
	bool getPassport() const;
	bool getVisa() const;
	int getCounterTravellers() const;
	BOOKING* getPassengers() const;
	bool getAllDataEntered() const;
	bool getBooked() const;
	bool getBookedForMore() const;


	~USER();

private:
	const int sizeOfArray;

	char* firstName;
	char* lastName;
	int age;
	char* cnic;

	char* userName;
	char* passWord;

	USER* under18ID; // UNDER 18 ID'S ALLOWED 7 CHILDREN

	bool passport;
	bool visa; // 

	int counterTravellers; // Initially will be 1 will increase if under 18 ID's are registered and vice versa 
	BOOKING* passengers; // Total 1 + 7

	bool allDataEntered;
	bool booked;
	bool bookedForMore;
	
};



// ------------------------------------------- PLANE CLASS -------------------------------------------

class PLANE
{
public:
	PLANE();
	PLANE(char* fn, USER* ps, AIRPORT* fA , AIRPORT* tA ,int d  , int m , int y , bool cr, bool t, bool l , bool dir , bool ind , bool l_f , bool i_f , int de , int ar);
	PLANE(const PLANE& copyPlaneObj);

	virtual void print();

	void setPlaneAllDetails(char* fn, USER* ps, AIRPORT* fA, AIRPORT* tA, int d, int m, int y, bool cr, bool t, bool l, bool dir, bool ind, bool l_f, bool i_f, int de, int ar);

	void addSeat(USER & newPassenger);
	void removeSeat(USER &deletePassenger);

	void setFlightName(char* fn);
	void setPassengerSeats(USER* ps);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	void setFromAirport(AIRPORT* fA);
	void setToAirport(AIRPORT* tA);
	void setCovidRestriction(bool cr);
	void setTakeoff(bool t);
	void setLand(bool l);
	void setDirect(bool dir);
	void setIndirect(bool ind);
	void setLocalFlight(bool l_f);
	void setIntFlight(bool i_f);
	void setDep(int d);
	void setArr(int a);

	char* getFlightName() const;
	USER* getPassengerSeats() const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	AIRPORT* getFromAirport() const;
	AIRPORT* getToAirport() const;
	bool getCovidRestriction() const;
	bool getTakeoff() const;
	bool getLand() const;
	bool getDirect() const;
	bool getIndirect() const;
	bool getLocalFlight() const;
	bool getIntFlight() const;
	int getDep() const;
	int getArr() const;
	double getCost() const;

	friend ostream& operator << (ostream& out, const PLANE& obj);

	void operator = (const PLANE& obj);

	~PLANE();

private:
	const int sizeOfArray;

	char* flightName;

	USER* passengerSeats; // 50 is the capacity

	AIRPORT* fromAirport;
	AIRPORT*toAirport;

	int day;
	int month;
	int year;

	bool covidRestriction;
	bool takeoff;
	bool land;

	bool direct; 
	bool indirect;
	bool localFlight;
	bool IntFlight;

	int dep;
	int arr;
	double cost;

};



// ------------------------------------------- ADMIN CLASS -------------------------------------------
class ADMIN : public ABSTRACTCLASS
{
public:
	ADMIN();
	ADMIN(char* fn, char* ln, char* un, char* pw);
	ADMIN(const ADMIN& copyAdminObj);

	void setFirstName(char* fn);
	void setLastName(char* ln);
	void setUserName(char* un);
	void setPassWord(char* pw);

	char* getFirstName() const;
	char* getLastName() const ;
	char* getUserName() const;
	char* getPassWord() const;

	void addObj();
	void deleteObj();

	void covidBan(AIRPORT& banAirportObj);
	void covidUnban(AIRPORT& unBanAirportObj);

	void setCovidRestrictionOnPlane(PLANE& setPlaneObj);
	void removeCovidRestrictionOnPlane(PLANE& setPlaneObj);

	void flightTakeoff(PLANE& setPlaneObj);
	void flightLand(PLANE& setPlaneObj);

	~ADMIN();

private:
	const int sizeOfArray;

	char* firstName;
	char* lastName;

	char* userName;
	char* passWord;

};