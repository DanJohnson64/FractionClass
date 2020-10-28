#include <iostream>

using namespace std;

#include "Fraction.h"


int main()
{
	Fraction a(1, 2);
	Fraction b(2, 6);
	Fraction c, d, e;

	// a.Input();
	// b.Input();

	c = a.Add(b);
	c.Print();

	d.Add(a, b);
	d.Print();

	d = a + b;
	d += a;

	cin >> e;
	cout << d << endl << e << endl;

	Fraction g(3, 5);
	double dd = (double)g;
	cout << dd << endl;

	d++;
	++c;

	Fraction bb(7, 8);
	Fraction aa(3, 5);

	bool v = aa < bb;
	bool w = aa >= bb;

	d = bb;

	system("pause");

}