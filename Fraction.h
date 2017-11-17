/*-------------------------------------------------------------------------------

FILE NAME: Fraction.h

DESCRIPTION: holds class declaration and header file to Fraction.cpp

PURPOSE: header file for Fraction.cpp

USAGE: with Fraction.cpp

EXAMPLES: N/A

PARAMETERS: N/A

EXIT CODES: N/A

COMPILATION: g++

NOTES: no driver...use in matrix_math.cpp

MODIFICATION HISTORY:

-------------------------------------------------------------------------------*/


#ifndef __FRACTION_H__
#define __FRACTION_H__


#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


#define MIN(x,y) ((x) < (y) ? (x) : (y))


/*-------------------------------------------------------------------------------------------
CLASS NAME: Fraction
PURPOSE: implement a fraction class
NOTES: only likes int type numbers
-------------------------------------------------------------------------------------------*/
class Fraction {
	
	friend ostream& operator << (ostream& lhs, const Fraction& frac);
	friend istream& operator >> (istream& lhs, Fraction& frac);
	friend Fraction exp(const Fraction& base, int exponent);

private:
	int numerator;
	int denominator;
	Fraction& operator -- (int);
public:

	operator double();
	Fraction(int num = 0, int denom = 1);
	Fraction& operator = (const Fraction& f);
	Fraction& operator = (int number);
	Fraction operator + (const Fraction& f) const;
	Fraction operator + (int) const;
	Fraction& operator += (const Fraction& f);
	Fraction operator - (const Fraction& f) const;
	Fraction operator - (int) const;
	Fraction& operator -= (const Fraction& f);
	Fraction operator * (const Fraction& f) const;
	Fraction operator * (int) const;
	Fraction& operator *= (const Fraction& f);
	Fraction operator / (const Fraction& f) const;
	Fraction operator / (int) const;
	Fraction& operator /= (const Fraction& f);
	Fraction& operator /= (int);
	int get_sign() const;

	bool operator != (const Fraction&) const;
	bool operator !=(int number) const;
	bool operator ==(const Fraction&) const;
	bool operator ==(int number) const;
	bool operator >(const Fraction&) const;
	bool operator <(const Fraction&) const;
	bool operator >=(const Fraction&) const;
	bool operator <=(const Fraction&) const;

	bool operator >(const double&) const;
	bool operator <(const double&) const;
	bool operator >=(const double&) const;
	bool operator <=(const double&) const;

	bool operator >(const int&) const;
	bool operator <(const int&) const;
	bool operator >=(const int&) const;
	bool operator <=(const int&) const;

};


#endif //__FRACTION_H__