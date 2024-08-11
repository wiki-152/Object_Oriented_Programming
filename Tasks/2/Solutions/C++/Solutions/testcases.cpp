#include "pch.h"
#include "pathway to your header"

//.............Problem 2.............
TEST(Problem2_1, SortAndReverse) {
	int array[] = {4,6,9,1,22,5,98,23,65,29};
	EXPECT_EQ(159, sortNreverse(array, 10));
}
TEST(Problem2_2, SortAndReverse) {
	int array[] = {56,9,12,35,0,1,24,38,41};
	EXPECT_EQ(89, sortNreverse(array, 9));
}
TEST(Problem2_3, SortAndReverse) {
	int array[] = {6,9,2,5,0,11,2,4,3};
	EXPECT_EQ(19, sortNreverse(array, 9));
}

//.............Problem 3.............
TEST(Problem5_1, combineArray) {
	char c1 [] = "Lab tasks time";
	char c2 [] = " is over";
	char c3 [] = "Lab tasks time is";
	EXPECT_EQ(c3, combineArr(c1, c2, 3));
}
TEST(Problem5_2, combineArray) {
	char c1 [] = "Lets do it";
	char c2 [] = "now ";
	char c3 [] = "Lets do it";
	EXPECT_EQ(c3, combineArr(c1, c2, 0));
}
TEST(Problem5_3, combineArray) {
	char c1 [] = "OOP lab is boring a";
	char c2 [] = "nd difficult";
	char c3 [] = "OOP lab is boring and di";
	EXPECT_EQ(c3, combineArr(c1, c2, 5));
}

//.............Problem 4.............
TEST(Problem3_1, ReturnSum) {
	int array[] = {4,6,9,1,22,5,98,23,65,29};
	EXPECT_EQ(38, returnSum(array, 10, 38));
}
TEST(Problem3_2, ReturnSum) {
	int array[] = {56,9,12,35,0,1,24,38,41};
	EXPECT_EQ(5, returnSum(array, 9, 5));
}
TEST(Problem3_3, ReturnSum) {
	int array[] = {6,9,2,5,0,11,2,4,3};
	EXPECT_EQ(-1, returnSum(array, 9, 32));
}

//.............Problem 5.............
TEST(Problem6_1, rearrangeArray) {
	int array[] = {4,6,9,1,22,5,98,23,65,29};
	int ret [] =  {1,65,9,4,22,5,98,23,6,29};
	EXPECT_EQ(ret, rearrangeArr(array, 10));
}
TEST(Problem6_2, rearrangeArray) {
	int array[] = {56,9,12,35,0,1,24,38,41};
	int ret [] =  {0,41,12,35,56,1,24,38,9};
	EXPECT_EQ(ret, rearrangeArr(array, 9));
}
TEST(Problem6_3, rearrangeArray) {
	int array[] = {6,9,2,5,0,11,2,4,3};
	int ret [] =  {0,9,2,5,6,11,2,4,3};
	EXPECT_EQ(ret, rearrangeArr(array, 9));
}

//.............Problem 6.............
TEST(Problem4_1, AddNum) {
	int array[] = {4,6,9,1,22,5,98,23,65,29};
	int ret [] = {1,4,5,6,9,22,23,29,65,71,98};
	EXPECT_EQ(ret, addNum(array, 10, 71, 3));
}
TEST(Problem4_2, AddNum) {
	int array[] = {56,9,12,35,0,1,24,38,41};
	int ret [] = {0,1,9,12,24,27,35,38,41,56};
	EXPECT_EQ(ret, addNum(array, 9, 27, 5));
}
TEST(Problem4_3, AddNum) {
	int array[] = {6,9,2,5,0,11,2,4,3};
	int ret [] = {0,1,2,2,3,4,5,6,9,11};
	EXPECT_EQ(ret, addNum(array, 9, 1, 0));
}

//.............Problem 7.............
TEST(Problem8_1, matchCharacters) {
	EXPECT_EQ(TRUE, matchChar("Don’t nod"));
}
TEST(Problem8_2, matchCharacters) {
	char c1 [] = "Aibohphobiaa";
	EXPECT_EQ(FALSE, matchChar(c1));
}
TEST(Problem8_3, matchCharacters) {
	char c1 [] = "UFO tofu";
	EXPECT_EQ(TRUE, matchChar(c1));
}

//.............Problem 8.............
TEST(Problem7_1, sameChars) {
	EXPECT_EQ(TRUE, sameChar("debit card", "bad credit"));
}
TEST(Problem7_2, sameChars) {
	char c1 [] = "Vacations time";
	char c2 [] = "I am not active";
	EXPECT_EQ(FALSE, sameChar(c1, c2));
}
TEST(Problem7_3, sameChars) {
	char c1 [] = "dormitory";
	char c2 [] = "dirty room";
	EXPECT_EQ(TRUE, sameChar(c1, c2));
}
