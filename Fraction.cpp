#include <iostream>
#include <cmath>

using namespace std;

#include "Fraction.h"


Fraction::Fraction()
{
	Numer = 0;
	Denom = 1;
}

Fraction::Fraction(int n, int d)
{
	if (d <= 0)
		d = 1;
	Numer = n;
	Denom = d;
	LowTerms();
}

Fraction::Fraction(double n)
{
	Denom = 100000;
	n *= (double)Denom;
	Numer = (long)n;
	LowTerms();
}

Fraction::Fraction(const Fraction& f)
{
	Numer = f.Numer;
	Denom = f.Denom;
}

void Fraction::Input(void)
{
	char div, again = 1;

	while (again)
	{
		cout << "Enter NN/DD: ";
		cin >> Numer >> div >> Denom;

		if (Denom <= 0)
		{
			cout << "Denominator must be > 0, try again" << endl;
			continue;
		}
		again = 0;
	}
}

void Fraction::Print(void) const
{
	cout << Numer << "/" << Denom;
}

void Fraction::LowTerms(void)
{
	return;
}

void Fraction::Add(const Fraction& f1, const Fraction& f2)
{
	Numer = (f1.Numer * f2.Denom) + (f1.Denom * f2.Numer);
	Denom = (f1.Denom * f2.Denom);
	LowTerms();
}

void Fraction::Sub(const Fraction& f1, const Fraction& f2)
{
	Numer = (f1.Numer * f2.Denom) - (f1.Denom * f2.Numer);
	Denom = (f1.Denom * f2.Denom);
	LowTerms();
}

void Fraction::Mul(const Fraction& f1, const Fraction& f2)
{
	Numer = (f1.Numer * f2.Numer);
	Denom = (f1.Denom * f2.Denom);
	LowTerms();
}

void Fraction::Div(const Fraction& f1, const Fraction& f2)
{
	Numer = (f1.Numer * f2.Denom);
	Denom = (f1.Denom * f2.Numer);
	LowTerms();
}

Fraction Fraction::Add(const Fraction& f) const
{
	Fraction r;

	r.Numer = (Numer * f.Denom) + (Denom * f.Numer);
	r.Denom = (Denom * f.Denom);
	r.LowTerms();
	return r;
}

Fraction Fraction::Sub(const Fraction& f) const
{
	Fraction r;

	r.Numer = (Numer * f.Denom) - (Denom * f.Numer);
	r.Denom = (Denom * f.Denom);
	r.LowTerms();
	return r;
}

Fraction Fraction::Mul(const Fraction& f) const
{
	Fraction r;

	r.Numer = (Numer * f.Numer);
	r.Denom = (Denom * f.Denom);
	r.LowTerms();
	return r;
}

Fraction Fraction::Div(const Fraction& f) const
{
	Fraction r;

	r.Numer = (Numer * f.Denom);
	r.Denom = (Denom * f.Numer);
	r.LowTerms();
	return r;
}

Fraction Fraction::operator+(const Fraction& f) {
	Fraction g;
	g = g.Add(f);
	return g;
}
Fraction Fraction::operator-(const Fraction& f) {
	Fraction g;
	g = g.Sub(f);
	return g;
}
Fraction Fraction::operator*(const Fraction& f) {
	Fraction g;
	g = g.Mul(f);
	return g;
}
Fraction Fraction::operator/ (const Fraction& f) {
	Fraction g = g.Div(f);
	return g;
}

Fraction Fraction::operator+=(const Fraction& f) {
	Numer = Numer + f.Numer;
	Denom = Denom + f.Denom;
	Fraction g(Numer, Denom);
	return g;
}
Fraction Fraction::operator-=(const Fraction& f) {
	Numer = Numer - f.Numer;
	Denom = Denom - f.Denom;
	Fraction g(Numer, Denom);
	return g;
}
Fraction Fraction::operator*=(const Fraction& f) {
	Numer = Numer * f.Numer;
	Denom = Denom * f.Denom;
	Fraction g(Numer, Denom);
	return g;
}
Fraction Fraction::operator/=(const Fraction& f) {
	Numer = Numer / f.Numer;
	Denom = Denom / f.Denom;
	Fraction g(Numer, Denom);
	return g;
}

Fraction::operator double() const {
	double f;
	f = (double)Numer / (double)Denom;
	return f;
}
Fraction::operator float() const {
	double f;
	f = (float)Numer / (float)Denom;
	return f;
}

ostream& operator<<(std::ostream& out, Fraction const& f) {
	out << f.Numer << "/" << f.Denom;
	return out;
}
istream& operator>>(istream& out, Fraction& f) {
	cout << "Enter Numer and Denom: ";
	cin >> f.Numer >> f.Denom;
	return out;
}

Fraction Fraction::operator++(int) {
	Fraction tmp = *this;
	++Numer;
	++Denom;
	return tmp;
}
Fraction& Fraction::operator++() {
	++Numer;
	++Denom;
	return *this;
}
Fraction Fraction::operator--(int) {
	Fraction tmp = *this;
	--Numer;
	--Denom;
	return tmp;
}
Fraction& Fraction::operator--() {
	--Numer;
	--Denom;
	return *this;
}

bool Fraction::operator <(const Fraction& f) const {
	double leftNum = Numer / Denom;
	double rightNum = f.Numer / f.Denom;
	bool b = leftNum < rightNum;
	return b;
}

bool Fraction::operator >(const Fraction& f) const {
	double leftNum = Numer / Denom;
	double rightNum = f.Numer / f.Denom;
	bool b = leftNum > rightNum;
	return b;
}

bool Fraction::operator ==(const Fraction& f) const {
	double leftNum = Numer / Denom;
	double rightNum = f.Numer / f.Denom;
	bool b = (leftNum = rightNum);
	return b;
}


bool Fraction::operator>=(const Fraction& f) const {
	bool g = (*this > f);
	if (g)
		return true;
	bool e = (*this == f);
	if (e)
		return true;
}
bool Fraction::operator<=(const Fraction& f) const {
	bool g = (*this < f);
	if (g)
		return true;
	bool e = (*this == f);
	if (e)
		return true;
}
Fraction Fraction::operator=(const Fraction& f) {
	Numer = f.Numer;
	Denom = f.Denom;
	return *this;
}

