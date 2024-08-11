#include "pch.h"
#include "your path to headerfile"

TEST(TestCase1, Addition) {
	ASSERT_EQ(3, sum(1, 2));
}

TEST(TestCase2, Sub) {
	ASSERT_EQ(10, subtract(40, 30));
}

TEST(TestCase3, mul) {
	ASSERT_EQ(1200, multiply(40, 30));
}

TEST(TestCase4, div) {
	ASSERT_EQ(2, division(10, 5));
}