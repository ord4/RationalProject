// COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
//
// rational.hpp: Definition of rational class and its interace.

#include "rational.hpp"

#include <iostream>


// -------------------------------------------------------------------------- //
// Helper functions

// Compute the GCD of two integer values using Euclid's algorithm.
int
gcd(int a, int b)
{
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}


// Compute the LCM of two integer values.
int
lcm(int a, int b)
{
  return (std::abs(a) / gcd(a, b)) * std::abs(b);
}


// -------------------------------------------------------------------------- //
// Rational implementation


// TODO: Make this print integers when the denominator is 1.
std::ostream&
operator<<(std::ostream& os, Rational r)
{
  return os << r.num() << '/' << r.den();
}


// TODO: Make this read integer values if no '/' is given as a separator.
// You may assume that there is no space between the numerator and the
// slash. Hint, find and read the reference documentation for istream::peek().
std::istream&
operator>>(std::istream& is, Rational& r)
{
  int p, q;
  char c;
  is >> p >> c >> q;
  if (!is)
    return is;

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
