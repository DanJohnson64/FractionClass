#pragma once
#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
	long Numer;
	long Denom;

	void LowTerms(void);

public:
	explicit Fraction();
	explicit Fraction(int n, int d = 1);
	explicit Fraction(double n);
	Fraction(const Fraction& f);

	void Input(void);
	void Print(void) const;
	
	Fraction operator+(const Fraction &f);
	Fraction operator-(const Fraction &f);
	Fraction operator*(const Fraction &f);
	Fraction operator/(const Fraction &f);

	Fraction operator+=(const Fraction &f);
	Fraction operator-=(const Fraction& f);
	Fraction operator*=(const Fraction& f);
	Fraction operator/=(const Fraction& f);

	operator double() const;
	operator float() const;

	friend std::ostream& operator<<(std::ostream& out, Fraction const& f);
	friend std::istream& operator>>(istream& out, Fraction& r);

	Fraction operator++(int);
	Fraction& operator++();
	Fraction operator--(int);
	Fraction& operator--();

	bool operator<(const Fraction& f) const;
	bool operator>(const Fraction& f) const;
	bool operator==(const Fraction& f) const;

	bool operator>=(const Fraction& f) const;
	bool operator<=(const Fraction& f) const;
	Fraction operator=(const Fraction& f);
	


	

	Fraction Add(const Fraction& f) const;
	Fraction Sub(const Fraction& f) const;
	Fraction Mul(const Fraction& f) const;
	Fraction Div(const Fraction& f) const;

	void Add(const Fraction& f1, const Fraction& f2);
	void Sub(const Fraction& f1, const Fraction& f2);
	void Mul(const Fraction& f1, const Fraction& f2);
	void Div(const Fraction& f1, const Fraction& f2);
};

#endif	// FRACTION_H
