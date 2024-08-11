#include "pch.h"
#include "pathway to your header"

//----------------------Problem 1----------------------
TEST(Problem1_1, CarClass) {
	Car c1("ab", "cd", 2015);
	ASSERT_EQ(8, c1.getAge(2023));
 
}
TEST(Problem1_2, CarClass) {
	Car c1("ab", "cd", 2015);
	
	ASSERT_EQ(1, c1.serviceNeeded());
}
TEST(Problem1_3, CarClass) {
	Car c2("ab", "cd", 2020);

	ASSERT_EQ(0, c2.serviceNeeded());
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
	EXPECT_EQ(33, s1.getVolume());
}

TEST(Problem4_2, SphereClass) {
	Sphere s1(1);

	EXPECT_EQ(2, s1.getDiameter());
	EXPECT_EQ(12, s1.getArea());
	EXPECT_EQ(6, s1.getCircumference());
	EXPECT_EQ(4, s1.getVolume());
}
