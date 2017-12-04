/*-------------------------------------------------------------------------------

FILE NAME: Fraction.cpp

DESCRIPTION: implementation file for Fraction class

PURPOSE: define Fraction operations

USAGE: with Fraction.h

EXAMPLES: N/A

PARAMETERS: N/A

EXIT CODES: N/A

COMPILATION: g++

NOTES: no driver...use in matrix_math.cpp

MODIFICATION HISTORY:

-------------------------------------------------------------------------------*/
#ifndef __FRACTION_CPP__
#define __FRACTION_CPP__


#include "Fraction.h"

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: Fraction() constructor
PURPOSE: initialize an instance of a fraction
RETURNS: nothing
NOTES: numerator defaults to 0, denominator defaults to 1, if denominator is 0 it will be 
	   changed to 1 automatcally
-------------------------------------------------------------------------------------------*/
Fraction::Fraction(int num, int denom)
{
	numerator = num;
	denominator = denom;

	if(denom != 0)
	{
		if(denom < 0)
		{
			numerator *=-1;
			denominator = denom*-1;
		}
		else
			denominator = denom;
	}
	else 
		denominator = 1;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator =
PURPOSE: assign value of one fraction to another
RETURNS: Fraction
NOTES: 
-------------------------------------------------------------------------------------------*/		
Fraction& Fraction::operator = (const Fraction& f)
{
	numerator = f.numerator;
	denominator = f.denominator;
	return *this;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator =
PURPOSE: assign value of an int to the fraction
RETURNS: Fraction
NOTES: denominator becomes 1
-------------------------------------------------------------------------------------------*/
Fraction& Fraction::operator = (int number)
{
	numerator = number;
	denominator = 1;
	return *this;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator --
PURPOSE: reduce fraction
RETURNS: Fraction
NOTES: private member
-------------------------------------------------------------------------------------------*/
Fraction& Fraction::operator -- (int)	//postfix operator
{
	if(MIN(numerator, denominator) < 2)
		return *this;

	for(int i = MIN(numerator, denominator); i > 1 ; i--)
	{
		if(numerator % i == 0 && denominator%i == 0)
		{
			numerator /= i;
			denominator /= i;
			return *this;
		}
	}
	return *this;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator *
PURPOSE: multiply 2 fraction
RETURNS: Fraction
NOTES: 
-------------------------------------------------------------------------------------------*/
Fraction Fraction::operator * (const Fraction& f) const
{
	Fraction product(numerator * f.numerator, denominator * f.denominator);
	return product--;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator *
PURPOSE: multiply fraction by an int
RETURNS: Fraction
NOTES:
-------------------------------------------------------------------------------------------*/
Fraction Fraction::operator * (int scalar) const
{
	Fraction product(numerator * scalar, denominator);
	return product--;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator *=
PURPOSE: multiply fraction by fraction and set lhs = to result
RETURNS: Fraction
NOTES:
-------------------------------------------------------------------------------------------*/
Fraction& Fraction::operator *= (const Fraction& f) 
{
	*this = *this * f;
	*this = (*this)--;
	return *this;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator /
PURPOSE: divide 2 fractions by multiplying by reciprocal
RETURNS: Fraction
NOTES: 
-------------------------------------------------------------------------------------------*/
Fraction Fraction::operator / (const Fraction& f) const
{
	Fraction quotient(numerator * f.denominator, denominator * f.numerator);
	return quotient--;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator /
PURPOSE: divide fraction by whole number
RETURNS: Fraction
NOTES:
-------------------------------------------------------------------------------------------*/
Fraction Fraction::operator / (int dividend) const
{
	Fraction quotient(numerator, denominator * dividend);
	return quotient--;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator /=
PURPOSE: divide 2 fractions and set lhs = to result
RETURNS: Fraction
NOTES:
-------------------------------------------------------------------------------------------*/
Fraction& Fraction::operator /= (const Fraction& f)
{
	*this = *this / f;
	*this = (*this)--;
	return *this;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator /=
PURPOSE: divide 2 fractions and set lhs = to result
RETURNS: Fraction
NOTES:
-------------------------------------------------------------------------------------------*/
Fraction& Fraction::operator /= (int num)
{
	Fraction f(num);
	*this = *this / f;
	*this = (*this)--;
	return *this;
}


/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator +
PURPOSE: add 2 fractions
RETURNS: Fraction
NOTES: has to find a comon denominator.....not most efficient common denominator way but its fine
-------------------------------------------------------------------------------------------*/
Fraction Fraction::operator + (const Fraction& frac) const
{
	Fraction sum;
	Fraction f1 = frac;
	Fraction f2 = *this;

	do{
		if(f2.denominator == f1.denominator)
		{
			sum.numerator = f2.numerator + f1.numerator;
			sum.denominator = f1.denominator;
			return sum--;
		}

		f1.denominator *= f2.denominator;
		f1.numerator *= f2.denominator;
		f2.denominator *= frac.denominator;
		f2.numerator *= frac.denominator;

	}while(1);

}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator +
PURPOSE: add a whole number to a fraction
RETURNS: Fraction
NOTES:
-------------------------------------------------------------------------------------------*/
Fraction Fraction::operator + (int numb) const
{
	Fraction frac(numb);
	return *this + frac;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator +=
PURPOSE: add 2 fractions and set lhs = result
RETURNS: Fraction
NOTES:
-------------------------------------------------------------------------------------------*/
Fraction& Fraction::operator +=(const Fraction& f)
{
	*this = *this + f;
	*this = (*this)--;
	return *this;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator -
PURPOSE: subtract 2 fractions
RETURNS: Fractione
NOTES: ....could change this to just addition of -1* rhs??
-------------------------------------------------------------------------------------------*/
Fraction Fraction::operator - (const Fraction& frac) const
{
	Fraction difference;
	Fraction f1 = frac;
	Fraction f2 = *this;

	do{
		if(f2.denominator == f1.denominator)
		{
			difference.numerator = f2.numerator - f1.numerator;
			difference.denominator = f1.denominator;
			return difference--;
		}

		f1.denominator *= f2.denominator;
		f1.numerator *= f2.denominator;
		f2.denominator *= frac.denominator;
		f2.numerator *= frac.denominator;

	}while(1);

}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator -
PURPOSE: subtract a number from a fraction
RETURNS: Fraction
NOTES:
-------------------------------------------------------------------------------------------*/
Fraction Fraction::operator - (int numb) const
{
	Fraction frac(numb);
	return *this - frac;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator -=
PURPOSE: subtract 2 fractions and set lhs = to result 
RETURNS: Fraction
NOTES:
-------------------------------------------------------------------------------------------*/
Fraction& Fraction::operator -= (const Fraction& f)
{
	*this = *this - f;
	*this = (*this)--;
	return *this;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: double()
PURPOSE: cast Fraction into a double in order to compare them slightly easier
RETURNS: double
NOTES:
-------------------------------------------------------------------------------------------*/
Fraction::operator double()   //  double(frac)
{
	return double(numerator)/denominator;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator !=
PURPOSE: compare 2 fractions and see if they are not equal
RETURNS: bool
NOTES:
-------------------------------------------------------------------------------------------*/
bool Fraction::operator !=(const Fraction& f) const
{
	if(numerator != f.numerator || denominator != f.denominator)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator !=
PURPOSE: compare fraction to int
RETURNS: bool
NOTES: this might be usefule to template?
-------------------------------------------------------------------------------------------*/
bool Fraction::operator !=(int number) const
{
	if(denominator == 1 && numerator == number)
		return false;
	return true;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operaator ==
PURPOSE: compare equality of 2 fractions
RETURNS: bool
NOTES: 
-------------------------------------------------------------------------------------------*/
bool Fraction::operator ==(const Fraction& f) const
{
	if(numerator == f.numerator && denominator == f.denominator)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator ==
PURPOSE: compare fraction to an int
RETURNS: bool
NOTES: denominator has to be 1
-------------------------------------------------------------------------------------------*/
bool Fraction::operator ==(int number) const
{
	if(numerator == number && denominator == 1)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator >
PURPOSE: compare 2 fractions values
RETURNS: bool
NOTES: casts to double, may be some small error there
-------------------------------------------------------------------------------------------*/
bool Fraction::operator >(const Fraction& f) const
{
	double valueLeft = double(numerator)/denominator;
	double valueRight = double(f.numerator)/f.denominator;

	if(valueLeft > valueRight)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator <
PURPOSE: compare values of 2 fractions
RETURNS: bool
NOTES: casts to double...may have small error there
-------------------------------------------------------------------------------------------*/
bool Fraction::operator <(const Fraction& f) const
{
	double valueLeft = double(numerator)/denominator;
	double valueRight = double(f.numerator)/f.denominator;

	if(valueLeft < valueRight)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator >= 
PURPOSE: compare the values of 2 fractions
RETURNS: bool
NOTES: casts to double, may be some rounding errors etc
-------------------------------------------------------------------------------------------*/
bool Fraction::operator >=(const Fraction& f) const
{
	double valueLeft = double(numerator)/denominator;
	double valueRight = double(f.numerator)/f.denominator;

	if(valueLeft >= valueRight)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator <=
PURPOSE: compare value of 2 fractions
RETURNS: bool
NOTES: cast to double so maybe some small error
-------------------------------------------------------------------------------------------*/
bool Fraction::operator <=(const Fraction& f) const
{
	double valueLeft = double(numerator)/denominator;
	double valueRight = double(f.numerator)/f.denominator;

	if(valueLeft <= valueRight)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator >=
PURPOSE: compare value of fraction and number
RETURNS: bool
NOTES: casts to double so...error maybe?
-------------------------------------------------------------------------------------------*/
bool Fraction::operator >=(const double& n) const
{
	double valueLeft = double(numerator)/denominator;

	if(valueLeft >= n)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator <=
PURPOSE: compare fraction to a number
RETURNS: bool
NOTES: casts to double so error maybe a little
-------------------------------------------------------------------------------------------*/
bool Fraction::operator <=(const double& n) const
{
	double valueLeft = double(numerator)/denominator;
	
	if(valueLeft <= n)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator >
PURPOSE: compare fraction to a number
RETURNS: bool
NOTES: cast to double may have a little error
-------------------------------------------------------------------------------------------*/
bool Fraction::operator >(const double& n) const
{
	double valueLeft = double(numerator)/denominator;

	if(valueLeft > n)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator <
PURPOSE: compare fraction and number
RETURNS: bool
NOTES: cast to double maybe a little rounding error
-------------------------------------------------------------------------------------------*/
bool Fraction::operator <(const double& n) const
{
	double valueLeft = double(numerator)/denominator;
	
	if(valueLeft < n)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator >=
PURPOSE: compare value of fraction with int
RETURNS: bool
NOTES: cast to double could have slight error
-------------------------------------------------------------------------------------------*/
bool Fraction::operator >=(const int& n) const
{
	double valueLeft = double(numerator)/denominator;

	if(valueLeft >= n)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator <=
PURPOSE: compare fraction and int
RETURNS: bool
NOTES: casts to double
-------------------------------------------------------------------------------------------*/
bool Fraction::operator <=(const int& n) const
{
	double valueLeft = double(numerator)/denominator;
	
	if(valueLeft <= n)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator >
PURPOSE: compare fraction and int
RETURNS: bool
NOTES: cast to double
-------------------------------------------------------------------------------------------*/
bool Fraction::operator >(const int& n) const
{
	double valueLeft = double(numerator)/denominator;

	if(valueLeft > n)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator <
PURPOSE: compare fraction and int
RETURNS: bool
NOTES: casts to double
-------------------------------------------------------------------------------------------*/
bool Fraction::operator <(const int& n) const
{
	double valueLeft = double(numerator)/denominator;
	
	if(valueLeft < n)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: exp
PURPOSE: exponentiate a fraction to a int power
RETURNS: Fraction
NOTES: exponentiation by squaring algorithm
-------------------------------------------------------------------------------------------*/
Fraction exp(const Fraction& base, int exponent)
{
	if(exponent == 1)
		return base;
	if(exponent == 0)
		return 1;
	Fraction value;
	value = 1;
	Fraction base_cpy;
	base_cpy = base;
	if(exponent < 0)
	{
		base_cpy.numerator = base.denominator;
		base_cpy.denominator = base.numerator;
		exponent *= -1;
	}
	while(exponent)
	{
		if(exponent&1)
			value *= base_cpy;
		exponent>>=1;
		base_cpy *= base_cpy;
	}
	return value--;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator >>
PURPOSE:input fraction
RETURNS: istream
NOTES: friend, only really works as reading an int and changing it to a fraction
-------------------------------------------------------------------------------------------*/
istream& operator >> (istream& lhs, Fraction& frac)
{
	lhs >> frac.numerator;
	frac.denominator = 1;
	return lhs;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: operator <<
PURPOSE: output a fraction
RETURNS: ostream
NOTES: friend, fancy formatting needs special font
-------------------------------------------------------------------------------------------*/
//only a friend
ostream& operator << (ostream& lhs, const Fraction& frac)
{
	const char* super[10] = {
		"\u2070", "\u00B9", "\u00B2", "\u00B3", "\u2074", 
		"\u2075", "\u2076", "\u2077", "\u2078", "\u2079"};
	const char* sub[10] = {
		"\u2080", "\u2081", "\u2082", "\u2083", "\u2084", 
		"\u2085", "\u2086", "\u2087", "\u2088", "\u2089"};

	if(frac.denominator == 1)
	{
		lhs << frac.numerator;
		return lhs;
	}
	if(frac.numerator == 0)
	{
		lhs << frac.numerator;
		return lhs;
	}
	if(frac.numerator < 0)
		lhs << "-";


	int number = abs(frac.numerator);
	int digits = int(log10(number));
	int index;

	for(int i = digits; i >=0; i--)
	{
		index = number / pow(10, i);
		lhs << super[index];
		number-= index * pow(10, i);
	}

	lhs << "/";

	number = abs(frac.denominator);
	digits = int(log10(number));

	for(int i = digits; i >=0; i--)
	{
		index = number / pow(10, i);
		lhs << sub[index];
		number-= index * pow(10, i);
	}

	return lhs;
}

#endif //__FRACTION_CPP__