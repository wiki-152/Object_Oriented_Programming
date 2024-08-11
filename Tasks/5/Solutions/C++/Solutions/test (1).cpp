#include "pch.h"
#include "pathway to your header"

//----------------------Problem 1----------------------
TEST(Problem1_1, HolidayClass) {
	Holiday h1("Pakistan Day", 23, "March");
	Holiday h2("Labour Day", 1, "May");
	
  EXPECT_EQ(false, inSameMonth(h1, h2));
  
  
}
TEST(Problem1_2, HolidayClass) {
	Holiday h1("Pakistan Day", 23, "March");
	Holiday h3("Pakistan Day", 23, "March");

	EXPECT_EQ(true, inSameMonth(h1, h3));
}

TEST(Problem1_3, HolidayClass) {
	Holiday arr[2];
	Holiday h1("Pakistan Day", 23, "March");
	Holiday h2("Labour Day", 1, "May");
	arr[0] = h1;
	arr[1] = h2;

	EXPECT_EQ(12, avgDate(arr, 2));
}


TEST(Problem1_4, HolidayClass) {
	Holiday arr[2];
	Holiday h1("Pakistan Day", 23, "March");
	Holiday h2("Pakistan Day", 23, "March");
	arr[0] = h1;
	arr[1] = h2;

	EXPECT_EQ(23, avgDate(arr, 2));
}

//----------------------Problem 2----------------------
TEST(Problem2_1, RationalClass) {
	Rational r1(1, 2), r2(2, 3),r3;
	r3 = addRationalNumber(r1, r2);
	EXPECT_EQ(7, r3.getNumerator());
	EXPECT_EQ(6, r3.getDenominator());
}
TEST(Problem2_2, RationalClass) {
	Rational r1(1, 2), r2(2, 3), r3;
	r3 = multiRationalNumber(r1, r2);
	EXPECT_EQ(1, r3.getNumerator());
	EXPECT_EQ(3, r3.getDenominator());
}
TEST(Problem2_3, RationalClass) {
	Rational r1(1, 2), r2(2, 3), r3;
	r3 = divRationalNumber(r1, r2);
	EXPECT_EQ(3, r3.getNumerator());
	EXPECT_EQ(4, r3.getDenominator());
}


//----------------------Problem 4----------------------

TEST(Problem4_1, SphereClass) {
	Sphere s1(2);

	EXPECT_EQ(4, s1.getDiameter());
	EXPECT_EQ(50, s1.getArea());
	EXPECT_EQ(12, s1.getCircumference());
	EXPECT_EQ(16, s1.getVolume());
}

TEST(Problem4_2, SphereClass) {
	Sphere s1(1);

	EXPECT_EQ(2, s1.getDiameter());
	EXPECT_EQ(12, s1.getArea());
	EXPECT_EQ(6, s1.getCircumference());
	EXPECT_EQ(4, s1.getVolume());
}
