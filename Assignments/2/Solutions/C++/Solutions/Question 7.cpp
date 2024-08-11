/*
   Muhammad Waqas Shahid Khan
   22I - 2469
   BS SE-E
*/

#include <iostream>

using namespace std;

class Student
{
private:
	int stdID; // Student Identity Number
	string name; // Student Name
	string* courseCodes; // Courses taken by Student
	int numCourses; // Number of Courses taken by Student
	int* courseGrades; 
	float gpa;

public:

	Student(int input_stdID = -1 , string n = "-" , string *cc=NULL , int nc = 0 , int *cg=NULL /*, float input_gpa=-1*/)
	{
		stdID = input_stdID;
		/*cout << stdID << endl;*/
		name = n;
		/*cout << name << endl;*/
		numCourses = nc;
		/*cout << numCourses<<endl;*/
		courseCodes = new string[numCourses];
	
		if (cc == NULL)
		{
			for (int i = 0; i < numCourses; i++)
			{
				courseCodes[i] = "-";
			}
		}
		else
		{
			for (int i = 0; i < numCourses; i++)
			{
				courseCodes[i] = cc[i];
				/*cout << courseCodes[i] << endl;*/
			}
		}

		

		courseGrades = new int[numCourses];

		if (cg == NULL)
		{
			for (int i = 0; i < numCourses; i++)
			{
				courseGrades[i] = -1;
			}
		}
		else
		{
			for (int i = 0; i < numCourses; i++)
			{
				courseGrades[i] = cg[i];
				/*cout << courseGrades[i] << endl;*/
			}
		}

		gpa = 0;
		/*gpa = input_gpa;*/
		/*cout << gpa;*/
	}

	int getStdID()
	{
		return stdID;
	}

	string getName()
	{
		return name;
	}

	int getNumCourses()
	{
		return numCourses;
	}

	string getCourseCode(int i)
	{
		return courseCodes[i];
	}

	int getCourseGrade(int i)
	{
		return courseGrades[i];
	}

	float getGPA()
	{
		gpa = 0;

		for (int i = 0; i < numCourses; i++)
		{
			gpa += courseGrades[i];
			/*cout << courseGrades[i] << endl;*/
		}
		
		gpa = gpa / numCourses;

		return gpa;
	}

	void setStdID(int id)
	{
		stdID = id;
	}

	void setName(string firstName)
	{
		name = firstName;
	}

	void setCourseGrade(string courseCode, int grade)
	{
		for (int i = 0; i < numCourses; i++)
		{
			if (courseCodes[i] == courseCode)
			{
				courseGrades[i] = grade;
			}
		}
	}

	void addCourse(string courseCode, int grade)
	{
		string* new_cc = new string[numCourses + 1];
		int* new_cg = new int[numCourses + 1];

		for (int i = 0; i < numCourses; i++)
		{
			new_cc[i] = "";
			new_cc[i] = courseCodes[i];
			new_cg[i] = 0;
			new_cg[i] = courseGrades[i];
		}

		numCourses += 1;
		new_cc[numCourses] = courseCode;
		new_cg[numCourses] = grade;
	}

	void calcGPA()
	{
		gpa = 0;
		for (int i = 0; i < numCourses; i++)
		{
			gpa += courseGrades[i];
		}

		gpa = gpa / numCourses;

		/*cout << gpa << endl;*/
	}

};

Student getStudentAt(Student students[], int index)
{
	return students[index];
}

float calcClassGPA(Student students[], int numStudents)
{
	float class_gpa = 0;

	for (int i = 0; i < numStudents; i++)
	{
		class_gpa += students[i].getGPA();
	}

	class_gpa = class_gpa / numStudents;

	return class_gpa;
}

float getMaxGPA(Student students[] , int numStudents)
{
	float max = students[0].getGPA();
	/*cout << max << endl;*/
	for (int i = 0; i < numStudents; i++)
	{
		/*cout << students[i].getGPA() << endl;*/
		if (max < students[i].getGPA())
		{
			max = students[i].getGPA();
		}
	}

	return max;
}

/*int*/ float getMinGPA(Student students[], int numStudents) // In question return type is int but it should be float 
{
	float min = students[0].getGPA();

	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].getGPA() < min)
		{
			min = students[i].getGPA();
		}
	}

	return min;
}

void printStudentrecord(Student student)
{
	cout << endl << "---Student Details---" << endl;
	cout << endl<< "Student ID : " << student.getStdID() << endl;
	cout << endl<<"Name : " << student.getName() << endl;
	cout << endl << "Course Codes : " << endl;
	for (int i = 0; i < student.getNumCourses(); i++)
	{
		cout << student.getCourseCode(i) << endl;
	}
	cout << endl << "Grades : " << endl;
	for (int i = 0; i < student.getNumCourses(); i++)
	{
		cout << student.getCourseGrade(i) << endl;
	}

	cout << endl<< "GPA : " << student.getGPA() << endl << endl;

	cout << "------- END ---------" << endl << endl;
}

void printAllStudentRecords(Student students[], int numStudents)
{
	for (int i = 0; i < numStudents; i++)
	{
		cout << endl << "---Student Details---" << endl;
		cout << endl<< "Student ID : " << students[i].getStdID() << endl;
		cout << endl<< "Name : " << students[i].getName() << endl;
		cout << endl<< "Course Codes : " << endl;
		for (int j = 0; j < students[i].getNumCourses(); j++)
		{
			cout << students[i].getCourseCode(j) << endl;
		}
		cout <<endl<< "Grades : " << endl;
		for (int j = 0; j < students[i].getNumCourses(); j++)
		{
			cout << students[i].getCourseGrade(j) << endl;
		}

		cout <<  endl<<  "GPA : " << students[i].getGPA() << endl;
		cout << endl<< "------- END ---------" << endl << endl;
	}
}

int main()
{
	string* cc = new string[2];
	for (int i = 0; i < 2; i++)
	{
		*(cc+i) = "-";
		*(cc + i) = "Micha";
	}
	cc[1] = "Oho";

	int* cg = new int[2];
	for (int i = 0; i < 2; i++)
	{
		*(cg + i) = -1;
		*(cg + i) = i+2;
	}

	Student obj(1234 , "Waqas Khan" , cc , 2 ,cg );
	cg[0] = 1;
	cg[1] = 2;
	Student obj2(5678, "Sami Khan", cc, 2, cg);

	Student students[2] = { obj , obj2 };

	printAllStudentRecords(students, 2);

	return 0;
}
