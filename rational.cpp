/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron, Computer Science II, Prof. Will
	Project 1: Rational
*/
#include <iostream>
#include "rational.hpp"

// Constructors
// Default
Rational::Rational(){
	numer = 0.0;
	denom = 1.0;
}

// One integer
Rational::Rational(int n){
	numer = n;
	denom = 1;
}

// Two integers
Rational::Rational(int n, int d){
	// Check to see if the passed denominator was 0 and ask for a new non-zero denominator
	while(d == 0){
		std::cout << "Your denominator cannot be 0, please enter a new number (integer): ";
		std::cin >> d;
	}
	// Reduce number (use helper functions)
	int reduceBy = gcd(d, n);
	n /= reduceBy;
	d /= reduceBy;
	// Set the number
	setNumerator(n);
	setDenominator(d);
}

//******************************************************
// PRE:  Two numbers of either type rational or double *
// POST: Boolean if the two passed numbers are equal   *
//******************************************************
bool operator==(Rational left, Rational right){
	return((left.getNumer() / left.getDenom()) == (right.getNumer() / right.getDenom()));
}
bool operator==(double left, Rational right){
	return(left == (right.getNumer() / right.getDenom()));
}
bool operator==(Rational left, double right){
	return((left.getNumer() / left.getDenom()) == right);
}

//********************************************************
// PRE:  Two numbers of either type rational or double   *
// POST: Boolean if the two passed numbers are not equal *
//********************************************************
bool operator!=(Rational left, Rational right){
	return((left.getNumer() / left.getDenom()) != (right.getNumer() / right.getDenom()));
}
bool operator!=(double left, Rational right){
	return(left != (right.getNumer() / right.getDenom()));
}
bool operator!=(Rational left, double right){
	return((left.getNumer() / left.getDenom()) != right);
}

//******************************************************
// PRE:  Two numbers of either type rational or double *
// POST: Boolean if the left is less than the right    *
//******************************************************
bool operator<( Rational left,  Rational right) {
	return((left.getNumer() / left.getDenom()) < (right.getNumer() / right.getDenom()));
}
bool operator<( Rational left,  double right) {
	return((left.getNumer() / left.getDenom()) < right);
}
bool operator<( double left,  Rational right) {
	return(left < (right.getNumer() / right.getDenom()));
}

//******************************************************
// PRE:  Two numbers of either type rational or double *
// POST: Boolean if the left is greater than the right *
//******************************************************
bool operator>( Rational left,  Rational right) {
	return((left.getNumer() / left.getDenom()) > (right.getNumer() / right.getDenom()));
}
bool operator>( Rational left,  double right) {
	return((left.getNumer() / left.getDenom()) > right);
}
bool operator>( double left,  Rational right) {
	return(left > (right.getNumer() / right.getDenom()));
}

//******************************************************
// PRE:  Two numbers of either type rational or double *
// POST: Boolean if the left is less than or equal to  *
//******************************************************
bool operator<=( Rational left,  Rational right) {
	return((left.getNumer() / left.getDenom()) <= (right.getNumer() / right.getDenom()));
}
bool operator<=( Rational left,  double right) {
	return((left.getNumer() / left.getDenom()) <= right);
}
bool operator<=( double left,  Rational right) {
	return(left <= (right.getNumer() / right.getDenom()));
}

//********************************************************
// PRE:  Two numbers of either type rational or double   *
// POST: Boolean if the left is greater than or equal to *
//********************************************************
bool operator>=( Rational left,  Rational right) {
	return((left.getNumer() / left.getDenom()) >= (right.getNumer() / right.getDenom()));
}
bool operator>=( Rational left,  double right) {
	return((left.getNumer() / left.getDenom()) >= right);
}
bool operator>=( double left,  Rational right) {
	return(left >= (right.getNumer() / right.getDenom()));
}

// Overloaded mathematical operators
double operator+(Rational left, Rational right) {
	return((left.getNumer() / left.getDenom()) + (right.getNumer() / right.getDenom()));
}
double operator+(double left, Rational right){
	return(left + (right.getNumer() / right.getDenom()));
}
double operator+(Rational left, double right){
	return((left.getNumer() / left.getDenom()) + right);
}

double operator-(Rational left, Rational right) {
	return((left.getNumer() / left.getDenom()) - (right.getNumer() / right.getDenom()));
}
double operator-(double left, Rational right){
	return(left - (right.getNumer() / right.getDenom()));
}
double operator-(Rational left, double right){
	return((left.getNumer() / left.getDenom()) - right);
}

double operator*(Rational left, Rational right) {
	return((left.getNumer() / left.getDenom()) * (right.getNumer() / right.getDenom()));
}

double operator/(Rational left, Rational right) {
	return((left.getNumer() / left.getDenom()) / (right.getNumer() / right.getDenom()));
}



// Helper functions
// Compute the GCD of two integer values using Euclid's algorithm.
// Can this be used in reducing a fraction?
int gcd(int a, int b){
	while (b != 0){
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

// Compute the LCM of two integer values.
// Is this to be used with finding a common denominator for performing math operations
int lcm(int a, int b){
	return (std::abs(a) / gcd(a, b)) * std::abs(b);
}

// Make this print integers when the denominator is 1.
std::ostream& operator<<(std::ostream& os, Rational r){
	return os << r.getNumer() << '/' << r.getDenom();
}

// Make this read integer values if no '/' is given as a separator.
// You may assume that there is no space between the numerator and the
// slash. Hint, find and read the reference documentation for istream::peek().
std::istream& operator>>(std::istream& is, Rational& r){
	int p, q;
	char c;
	is >> p >> c >> q;
	if (!is){
		return is;
	}
	// Require that the divider to be a '/'.
	if (c != '/') {
		is.setstate(std::ios::failbit);
		return is;
	}
	// Make sure that we didn't read p/0.
	if (q == 0) {
		is.setstate(std::ios::failbit);
		return is;
	}
	r = Rational(p, q);
	return is;
}

// Setter and getter functions
void Rational::setNumerator(int n){
	numer = n;
}

void Rational::setDenominator(int d){
	denom = d;
}

double Rational::getNumer(){
	return numer;
}

double Rational::getDenom(){
	return denom;
}
