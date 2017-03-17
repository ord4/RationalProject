/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron, Computer Science II, Prof. Will
	Project 1: Rational
*/
#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <cstdlib>
#include <iosfwd>
#include <iostream>
#include <stdlib.h>

// Mathematical helper functions.
//
// Note: These are defined in rational.cpp.
int gcd(int, int);
int lcm(int, int);


// Represents a rational number. The rational numbers are the set of
// numbers that can be represented as the quotient of two integers.
class Rational{
	private:
		int numer;
		int denom;

	public:
		// Constructors
		Rational();
		Rational(int);
		Rational(int, int);


		// Setter and getter functions
		void setNumerator(int);
		void setDenominator(int);
		int getNumer();
		int getDenom();
};

// Overloaded comparison operators will return T/F for the corresponding statement
// Have to have 3 for each operator to allow  constants on either side
bool operator==(Rational, Rational);
bool operator==(double, Rational);
bool operator==(Rational, double);

bool operator!=(Rational, Rational);
bool operator!=(double, Rational);
bool operator!=(Rational, double);

bool operator<(Rational, Rational);
bool operator<(double, Rational);
bool operator<(Rational, double);

bool operator>(Rational, Rational);
bool operator>(double, Rational);
bool operator>(Rational, double);

bool operator<=(Rational, Rational);
bool operator<=(double,  Rational);
bool operator<=(Rational, double);

bool operator>=(Rational, Rational);
bool operator>=(double, Rational);
bool operator>=(Rational, double);

// Overloaded mathematical operators will perform the operations as expected
Rational operator+(Rational, Rational);
Rational operator+(double, Rational);
Rational operator+(Rational, double);

Rational operator-(Rational, Rational);
Rational operator-(double, Rational);
Rational operator-(Rational, double);

Rational operator*(Rational, Rational);
Rational operator*(double, Rational);
Rational operator*(Rational, double);

Rational operator/(Rational, Rational);

// Friend functions overloading the << and >> operators
std::ostream& operator<<(std::ostream&, Rational);
std::istream& operator>>(std::istream&, Rational&);

#endif
