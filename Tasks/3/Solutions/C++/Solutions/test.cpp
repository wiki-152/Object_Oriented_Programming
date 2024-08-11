#include "pch.h"
#include "pathway to your header"

//------------------------Problem 1--------------------------
TEST(Problem1_1, product) {
	int** matrix1 = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		matrix1[i] = new int[3];
	}
	int** matrix2 = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		matrix2[i] = new int[3];
	}

	int arr1[3][3] = { {1,2,3},{2,3,4},{5,6,7} };
	int arr2[3][3] = { {1,2,3},{2,3,4},{5,6,7} };
	int product[3][3] = { {20,26,32},{28,37,46},{ 52,70,88} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix1[i][j] = arr1[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix2[i][j] = arr2[i][j];
		}
	}
	int** ptr = Product(matrix1,matrix2, 3, 3, 3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			EXPECT_EQ(product[i][j], ptr[i][j]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		delete[] matrix1[i];
	}
	delete[] matrix1;
	for (int i = 0; i < 3; i++)
	{
		delete[] matrix2[i];
	}
	delete[] matrix2;
}

TEST(Problem1_2, product) {
	int** matrix1 = new int* [2];
	for (int i = 0; i < 2; i++)
	{
		matrix1[i] = new int[2];
	}
	int** matrix2 = new int* [2];
	for (int i = 0; i < 2; i++)
	{
		matrix2[i] = new int[2];
	}
	int arr1[2][2] = { {40,55},{22,34} };
	int arr2[2][2] = { {15,21},{20,38} };
	int product[2][2] = { {1700,2930},{1010,1754} };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matrix1[i][j] = arr1[i][j];
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matrix2[i][j] = arr2[i][j];
		}
	}
	int** ptr = Product(matrix1, matrix2, 2, 2, 2, 2);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			EXPECT_EQ(product[i][j], ptr[i][j]);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		delete[] matrix1[i];
	}
	delete[] matrix1;
	for (int i = 0; i < 2; i++)
	{
		delete[] matrix2[i];
	}
	delete[] matrix2;
}
TEST(Problem1_3, product) {
	int** matrix1 = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		matrix1[i] = new int[3];
	}
	int** matrix2 = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		matrix2[i] = new int[3];
	}
	int arr1[3][3] = { {4,5,6},{2,3,4},{9,6,7} };
	int arr2[3][3] = { {1,2,3},{2,3,4},{5,6,7} };
	int product[3][3] = { { 44,59,74},{ 28,37,46},{ 56,78,100} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix1[i][j] = arr1[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix2[i][j] = arr2[i][j];
		}
	}
	int** ptr = Product(matrix1, matrix2, 3, 3, 3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			EXPECT_EQ(product[i][j], ptr[i][j]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		delete[] matrix1[i];
	}
	delete[] matrix1;
	for (int i = 0; i < 3; i++)
	{
		delete[] matrix2[i];
	}
	delete[] matrix2;
}

//------------------------Problem 2--------------------------
TEST(Problem2_1, UpperHalf) {
	int** p1 = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		p1[i] = new int[5];
	}
	
	int arr1[5][5] = { {2,3,1,5,0},{7,1,5,3,1},{2,5,7,8,1},{0,1,5,0,1},{3,4,9,1,5} };
	int arr2[5][5] = { {2,3,1,5,0},{0,1,5,3,1},{0,0,7,8,1},{0,0,0,0,1},{0,0,0,0,5} };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			p1[i][j] = arr1[i][j];
		}
	}
	
	int** ptr = Upper_half(p1, 5, 5);
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			EXPECT_EQ(arr2[i][j], ptr[i][j]);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		delete[] p1[i];
	}
	delete[] p1;
	
}


TEST(Problem2_2, UpperHalf) {
	int** p1 = new int* [2];
	for (int i = 0; i < 2; i++)
	{
		p1[i] = new int[2];
	}
	int arr1[2][2] = { {2,3},{7,1} };
	int arr2[2][2] = { {2,3},{0,1} };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			p1[i][j] = arr1[i][j];
		}
	}
	int** ptr = Upper_half(p1, 2, 2);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			EXPECT_EQ(arr2[i][j], ptr[i][j]);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		delete[] p1[i];
	}
	delete[] p1;
}

TEST(Problem2_3, UpperHalf) {
	int** p1 = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		p1[i] = new int[3];
	}
	int arr1[3][3] = { {2,3,1},{7,1,5},{2,5,7} };
	int arr2[3][3] = { {2,3,1},{0,1,5},{0,0,7} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			p1[i][j] = arr1[i][j];
		}
	}
	int** ptr = Upper_half(p1, 3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			EXPECT_EQ(arr1[i][j], ptr[i][j]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		delete[] p1[i];
	}
	delete[] p1;
}

//------------------------Problem 3--------------------------
TEST(Problem3_1, CalDiagonal) {
	int** ptr = new int* [4];
	for (int i = 0; i < 4; i++)
	{
		ptr[i] = new int[4];
	}
	int arr1[4][4] = { {1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4} };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ptr[i][j] = arr1[i][j];
		}
	}
	EXPECT_EQ(10, calDiagonal(ptr, 4, 4));
	for (int i = 0; i < 4; i++)
	{
		delete[]ptr[i];
	}
	delete[]ptr;
}
TEST(Problem3_2, CalDiagonal) {
	int** ptr = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		ptr[i] = new int[3];
	}
	int arr1[3][3] = { {1,2,3},{1,2,3},{1,2,3} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ptr[i][j] = arr1[i][j];
		}
	}
	EXPECT_EQ(6, calDiagonal(ptr, 3, 3));
	for (int i = 0; i < 3; i++)
	{
		delete[]ptr[i];
	}
	delete[]ptr;
}
TEST(Problem3_3, CalDiagonal) {
	int** ptr = new int* [2];
	for (int i = 0; i < 2; i++)
	{
		ptr[i] = new int[2];
	}
	int arr1[2][2] = { {2,3},{4,5} };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ptr[i][j] = arr1[i][j];
		}
	}
	EXPECT_EQ(7, calDiagonal(ptr, 2, 2));
	for (int i = 0; i < 2; i++)
	{
		delete[]ptr[i];
	}
	delete[]ptr;
}

//------------------------Problem 5--------------------------
TEST(Problem5_1, Prime_Number) {
	EXPECT_EQ(true, PrimeNumber(11));
}
TEST(Problem5_2, Prime_Number) {
	EXPECT_EQ(false, PrimeNumber(60));
}
TEST(Problem5_3, Prime_Number) {
	EXPECT_EQ(true, PrimeNumber(97));
}

//------------------------Problem 6--------------------------
TEST(Problem6_1, WordReverser) {
	char* c1 = "I AM GOOD, How are you";
	char* c2 = "GOOD AM I, How are you";
	char * c3 = kWOrdsReverser(c1, 3, 22);
		for (int j = 0; c2[j] != '\0'; j++)
		{
			EXPECT_EQ(c2[j], c3[j]);
		}
}

TEST(Problem6_2, WordReverser) {
	char* c1 = "My name is bobb";
	char* c2 = "bobb is name My";
	char* c3 = kWOrdsReverser(c1, 4, 15);
	for (int j = 0; c2[j] != '\0'; j++)
	{
		EXPECT_EQ(c2[j], c3[j]);
	}
}

TEST(Problem6_3, WordReverser) {
	char* c1 = "I Like oop";
	char* c2 = "oop Like I";
	char* c3 = kWOrdsReverser(c1, 0, 10);
	for (int j = 0; c2[j] != '\0'; j++)
	{
		EXPECT_EQ(c2[j], c3[j]);
	}
}

//------------------------Problem 7--------------------------
TEST(Problem7_1, WordLocation) {
	char* c1 = "I AM GOOD, How GOOd are you";
	char* c2 = "GOOD";
	EXPECT_EQ(6, findWordLocation(c1, c2));
}

TEST(Problem7_2, WordLocation) {
	char* c1 = "I Like flowers";
	char* c2 = "flowers";
	EXPECT_EQ(8, findWordLocation(c1, c2));
}
TEST(Problem7_3, WordLocation) {
	char* c1 = "I AM GOOD, How are you";
	char* c2 = "HELLO";
	EXPECT_EQ(0, findWordLocation(c1, c2));
}

//------------------------Problem 8--------------------------
TEST(Problem8_1, Array_Sorting) {
	int array[] = { 4,6,9,1,22,5,98,23,65,29 };
	int ret[] = { 1,4,5,6,9,22,23,29,65,98 };
	int* ptr = ArraySorting(ret, 10);
	for (int i = 0; i < 10; i++)
	{
		EXPECT_EQ(ret[i], ptr[i]);
	}
}

TEST(Problem8_2, Array_Sorting) {
	int array[] = { 56,9,12,35,0,1,24,38,41 };
	int ret[] = {0,1,9,12,24,35,38,41,56 };
	int* ptr = ArraySorting(array, 9);
	for (int i = 0; i < 9; i++)
	{
		EXPECT_EQ(ret[i], ptr[i]);
	}
}

TEST(Problem8_3, Array_Sorting) {
	int array[] = { 9,4,5,2,3 };
	int ret[] = { 2,3,4,5,9 };
	int* ptr = ArraySorting(array, 5);
	for (int i = 0; i < 5; i++)
	{
		EXPECT_EQ(ret[i], ptr[i]);
	}
}

