#include "pch.h"
#include "pathway to your header"


//-------------------Task1----------------- (1)
TEST(Task1_1, TestCase1) {
	DayOfYear d1(32);
	EXPECT_EQ("February",d1.GetMonth());
}

TEST(Task1_2, TestCase2) {
	DayOfYear d1(32);
	DayOfYear d2(32);
	
	EXPECT_EQ(true,d1==d2);
}

TEST(Task1_3, TestCase3) {
	DayOfYear d1(32);
	DayOfYear d2(2);
	d1+=d2;
	EXPECT_EQ(3,d1.GetDay());
	EXPECT_EQ("March",d1.GetMonth());
}

//-------------------Task2----------------- 
TEST(Task2_1, TestCase1) {
		Matrix m1(2,2);
		Matrix m2(2,2);	
		//assuming ptr of m1 have value less than ptr of m2	
		EXPECT_EQ(false,m1<m2);
}

TEST(Task2_2, TestCase2) {
		Matrix m1(2,2);
		Matrix m2(2,2);	
		m1+=m2;
		//assuming value place in both matrix is 1
		int arr[2][2]={{2,2},{2,2}};
		int **ret=m1.getPtr();
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				EXPECT_EQ(arr[i][j],ret[i][j]);
			}
		}		
}

TEST(Task2_3, TestCase3) {
		Matrix m1(2,2);
		Matrix m2(2,2);	
		m1*=m2;
		//assuming value place in both matrix is 1
		int arr[2][2]={{1,1},{1,1}};
		int **ret=m1.getPtr();
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				EXPECT_EQ(arr[i][j],ret[i][j]);
			}
		}		
}

//-------------------Task3----------------- 
TEST(Task3_1, TestCase1) {
	Polynomial p1(1,2,3),p2(1,2,3);
	EXPECT_EQ(true,p1==p2);
}

TEST(Task3_2, TestCase2) {
	Polynomial p1(1,2,3);
	p1++;
	EXPECT_EQ(2,p1.GetA());
	EXPECT_EQ(3,p1.GetB());
	EXPECT_EQ(4,p1.GetC());
}

TEST(Task3_3, TestCase3) {
	Polynomial p1(1,2,3);
	--p1;
	EXPECT_EQ(0,p1.GetA());
	EXPECT_EQ(1,p1.GetB());
	EXPECT_EQ(2,p1.GetC());
}
TEST(Task3_4, TestCase3) {
	Polynomial p1(1,2,3),p2(1,2,3);
	p2*=p1;
	EXPECT_EQ(1,p2.GetA());
	EXPECT_EQ(4,p2.GetB());
	EXPECT_EQ(9,p2.GetC());
}



