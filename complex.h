/*--------------------------------------------------------------------------------------------------------------

FILE NAME: complex.h

DESCRIPTION: holds class declaration and header file to complex.cpp

PURPOSE: header file for complex.cpp

USAGE: with complex.cpp

EXAMPLES: N/A

PARAMETERS: N/A

EXIT CODES: N/A

COMPILATION: g++

NOTES: no driver...use in matrix_math.cpp
	   Complex numbers must currently be of the form a+bi where a and b arent 0

MODIFICATION HISTORY:
Author:			Date: 			Version:		Details:
----------------------------------------------------------------------------------------------------------------
Zuriah Quinton  11/27/17		1.0				make a complex numbers class because I don't want to work on 
												inverse of a matrix (basic operations implemented)
Zuriah Quinton  11/28/17		1.1				comparison operators, so so many comparison operators...
Zuriah Quinton  12/01/17		2.0				fix input output operators

---------------------------------------------------------------------------------------------------------------*/

#ifndef __COMPLEX_H__
#define __COMPLEX_H__


#include <regex>
#include <iostream>



/*-----------------------------------------------------------------------------------------
CLASS NAME: Complex
PURPOSE: Implement a Complex type of number class
NOTES: use any number type for template
-----------------------------------------------------------------------------------------*/
template <typename T>
class Complex
{

template <typename B>
friend istream& operator >> (istream& in, Complex<B>& z);
template <typename B>
friend ostream& operator << (ostream& out, const Complex<B>& z);

private:
	T real;
	T imaginary;
public:

	Complex(const T & re = 0, const T & im = 0);

	T getReal();
	T getImaginary();
	Complex conjugate() const;
	Complex operator =(const Complex &);
	Complex operator =(const T &);

	Complex operator + (const T &) const;
	Complex operator +=(const T &);
	Complex operator + (const Complex &) const;
	Complex operator +=(const Complex &);

	Complex operator - (const T &) const;
	Complex operator -=(const T &);
	Complex operator - (const Complex &) const;
	Complex operator -=(const Complex &);

	Complex operator * (const T &) const;
	Complex operator *= (const T &);
	Complex operator * (const Complex &) const;
	Complex operator *=(const Complex &);

	Complex operator / (const T &) const;
	Complex operator /=(const T &);
	Complex operator / (const Complex &) const;
	Complex operator /=(const Complex &) ;

	bool operator !=(const Complex &)const;
	bool operator !=(const T &) const;
	bool operator ==(const Complex &)const;
	bool operator ==(const T &) const;
	

};

#include "complex.cpp"

#endif //__COMLEX_H__