#include <iostream>
using namespace std;
void IsGreater(int, int, int);
int fact(int);
void calculator(char, float, float);

int main() {

	IsGreater(1, 2, 3);
	IsGreater(6, 2, 3);
	IsGreater(3, 3, 3);

	cout <<  fact(10) << endl;
	cout <<  fact(5) << endl;
	cout <<  fact(7) << endl;

	calculator('*', 5, 6);
	calculator('/', 25, 5);
	calculator('+', 100, 6);
	calculator('-', 15, 3);

}

void calculator(char o, float num1, float num2) {

	float result;

	switch (o) {
	case '+':
		result = num1 + num2;
		num1 = num1 * 10;
		cout << num1 << " + " << num2 << " = " << result << endl;
		break;//insert a breakpoint here
	case '-':
		result = num1 + num2;
		num2 = num2 + 10;
		cout << num1 << " - " << num2 << " = " << result << endl;

		break; //insert a breakpoint here
	case '*':
		result = num1 * num2;
		num1 = num1 - 10;
		cout << num1 << " * " << num2 << " = " << result << endl;

		break; //insert a breakpoint here
	case '/':
		result = num1 / num2;
		num2 = num2 - 10;
		cout << num1 << " / " << num2 << " = " << result << endl;

		break; //insert a breakpoint here
	default:
		cout << "Error! operator is not correct";
		break;
	}
}
int fact(int n) {
	int i, factorial = 1;
	for (i = 1; i <= n; ++i) {
		factorial *= i; //insert a breakpoint here
	}

	return factorial; //insert a breakpoint here
}
void IsGreater(int a, int b, int c) {
	if (a > b) {
		a = a + 10;
		if (a > c)
			b = b - 10;
		cout << "A is Largest" << endl; //insert a breakpoint here
	} else if (a < b) {
		a = a - 1;
		b = b - a;
		cout << "B is Smallest" << endl; //insert a breakpoint here
	} else {

		c = c * 1000;
		b = c + a;
		cout << "A is Smallest" << endl; //insert a breakpoint here
	}
}
