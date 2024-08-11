#include "Counter.cpp"
#include "Distance.cpp"
#include "Complex.cpp"
#include "Date.cpp"
#include <gtest/gtest.h>


//-------------------Task1----------------- (1)
TEST(Task0_1, TestCase1) {
	Course obj("CS250", "Fundamental Programming", "CS", 3, "Ali Khan", 'A'), obj2(obj);
	EXPECT_EQ("CS250", obj.getCourseCode());
	EXPECT_EQ("Fundamental Programming", obj.getCourseTitle());
	EXPECT_EQ("CS", obj.getCourseType());
	EXPECT_EQ(3, obj.getCreditHours());
	EXPECT_EQ("Ali Khan", obj.getTeacher());
	

	obj.setCourseTitle("Differential Equations");
	obj.setCourseType("Science");
	EXPECT_EQ("Differential Equations", obj.getCourseTitle());
}

TEST(Task0_2, TestCase2) {
	Course course1("CS250", "Fundamental Programming", "CS", 3, "Ali Khan", 'A');
	Course course2("CS250", "Object Oriented Programming", "CS", 3, "Ali Khan", 'G');
	Course course3("CS250", "Data Strcutures", "CS", 3, "Ali Khan", 'B');
	Course course4("CS250", "Differential Equations", "Science", 3, "Hamda Khan", 'A');
	Course course5("CS250", "History", "Humanity", 3, "Maimoona Rasool", 'A');

	Course courses[5] = {
		course1,
		course2,
		course3,
		course4,
		course5
	};

	Semester semester;
	semester.setCourseCount(5);
	semester.setCourses(courses);
	semester.setSemesterCode("Spring 2023");

	EXPECT_EQ("Ali Khan", mostTeachersCount(semester));
}

//-------------------Task2----------------- (1)
TEST(T1_1, First) {   						

	Counter obj1;
	Counter obj2(5);
	ASSERT_EQ(2,obj1.getObjCount());
	
}

TEST(T1_2, Second) {   						

	Counter obj3(10);
	obj3=-obj3;
	ASSERT_EQ(-10,obj3.getCount());
}


TEST(T1_3, Third) {   						

	Counter obj3(10);
	Counter obj2;
	obj2=-obj3;
	ASSERT_EQ(-10,obj2.getCount());
}


//-------------------Task 3----------------- (3)


TEST(T2_1, First) {   						

	Cube d1(2,10);
	ASSERT_EQ(20,d1.getArea());
	
	
}

TEST(T2_2, Second) {   						

	Cube d1(5,20);
	Cube d2(2,15);
	Cube d3=d1-d2;
	ASSERT_EQ(5,d3.getWidth());
	ASSERT_EQ(3,d3.getHeight());
	
	
}
TEST(T23, Third) {   						

	Cube d1(5,15);
	Cube d2(2,20);
	
	ASSERT_EQ(false,d1>=d2;);
	ASSERT_EQ(false,d1<d2;;
	
	
}

//-------------------Task 4----------------- (3)


TEST(T3_1, First) {   						

	Complex c1;
    	ASSERT_EQ(0.0, c1.getReal());
    	ASSERT_EQ(0.0, c1.getImaginary());
    
	
	
}


TEST(T3_2, Second) {   						

	Complex c1(5.0,6.0);
    	Complex c2(7.0,8.0);
    	Complex c3 = c1+c2; 
    	ASSERT_EQ(12.0, c3.getReal());
    	ASSERT_EQ(14.0, c3.getImaginary());
}\

TEST(T3_3, Third) {   						

	Complex c1(12.0,6.0);
    	Complex c2(7.0,8.0);
    	c1 = c1-c2;
    	ASSERT_EQ(5.0, c1.getReal());
    	ASSERT_EQ(-2.0, c1.getImaginary());
    	ASSERT_EQ(true, c1!=c2);
}

//-------------------Task5----------------- (4)

TEST(T4_1, First) {   						

	Date d1(2012,12,31);
	Date d2(1995,12,28);
	d2=d1;
	ASSERT_EQ(31, d2.getDay());
}

TEST(T4_2, Second) {   						

	Date d1(2012,12,31);
	d1=d1+1;
	ASSERT_EQ(1, d1.getDay());
	ASSERT_EQ(1, d1.getMonth());
	ASSERT_EQ(2013, d1.getYear());
}
TEST(T4_22, Second) {   						

	Date d1(2012,09,03);
	Date d2(2018,12,19);
	d2=d2-d1;
	ASSERT_EQ(16, d2.getDay());
	ASSERT_EQ(3, d2.getMonth());
	ASSERT_EQ(6, d2.getYear());
	
}
TEST(T4_222, Second) {   						

	Date d1(2012,09,03);
	Date d2;
	d2=d1-14;
	ASSERT_EQ(19, d2.getDay());
	ASSERT_EQ(08, d2.getMonth());
	ASSERT_EQ(2012, d2.getYear());
	
}
TEST(T4_3, Third) {   						

	Date d1(2012,12,31);
	Date d2(1995,12,28);
	d2=d1;
	ASSERT_EQ(false, d1>d2);
	ASSERT_EQ(true, d1>=d2);
	ASSERT_EQ(false, d1<=d2);
	
	
}

