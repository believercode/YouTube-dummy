// Exercise no. 1
// Computes the solution of a system of two linear equations in two variables.
// Use the Cramer's Rule (manage the case D = 0):
// a1x + b1y = c1
// a2x + b2y = c2

// x = Dx/D
// y = Dy/D

// DATA:
// 12x + 3y = 15
// 2x - 3y = 13

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a1, b1, c1, a2, b2, c2, D;
	cout << "Enter the coefficients of the first equation: \n";
	cout << "a1: ";
	cin >> a1;
	cout << "b1: ";
	cin >> b1;
	cout << "c1: ";
	cin >> c1;

	cout << "Enter the coefficients of the second equation: \n";
	cout << "a2: ";
	cin >> a2;
	cout << "b2: ";
	cin >> b2;
	cout << "c2: ";
	cin >> c2;

	D = a1*b2 - a2*b1;

	if(D == 0) {
		cout << "The system has no solution!";
	}
	else {
		double x = (b2*c1 - b1*c2) / D;
		double y = (a1*c2 - a2*c1) / D;
		cout << "The solution of the system is: (" << x << ", " << y << ")";
	}
	return 0;
	}
