/*-------------------------------------------------------------------------------------------
FILE NAME: COMPLEX.CPP

DESCRIPTION: implementation file for Complex class

PURPOSE: definition of used class functions

USAGE: with matrix.h and matrix_math.cpp

EXAMPLES: N/A

PARAMETERS: N/A

EXIT CODES:

COMPILATION: g++

NOTES: templated class

MODIFICATION HISTORY:

-------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: Complex (constructor)
PURPOSE: initialize a complex number 
RETURNS: nothing
NOTES: re and im both default to 0
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T>::Complex(const T& re, const T& im)
{
	real = re;
	imaginary = im;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: getReal()
PURPOSE: return the real part of the Complex number
RETURNS: <T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
T Complex<T>::getReal()
{
	return real;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: getImaginary()
PURPOSE: returns imaginary part
RETURNS: <T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
T Complex<T>::getImaginary()
{
	return imaginary;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: conjugate()
PURPOSE: returns the complex conjugate of a comlex number (make imaginary part negative)
RETURNS: <T>
NOTES: 
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::conjugate() const
{
	Complex<T> answer = *this;
	answer.imaginary *= -1;
	return answer;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator =
PURPOSE: assign value of one complex number to another
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator = (const Complex& rhs) 
{
	this->real = rhs.real;
	this->imaginary = rhs.imaginary;

	return *this;
}

/*-------------------------------------------------------------------------------------------
FUNCITON NAME: overload operator =
PURPOSE: assign a real number to the real part of an imaginary number
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator = (const T & num)
{
	this->real = num;
	this->imaginary = 0;

	return *this;
}

/*-------------------------------------------------------------------------------------------------------------------------
											ADDITION OF COMPLEX THINGS
-------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator +
PURPOSE: add Complex number + T (just a real number)
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator + (const T & num) const
{
	Complex<T> answer;

	answer = *this;
	answer.real += num;

	return answer;	
}

/*-------------------------------------------------------------------------------------------
FUCNTION NAME: overload operator +=
PURPOSE: add Complex and a number (T) and set the Complex number = to result
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator += (const T& num)
{
	*this = *this + num;
	return *this;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator +
PURPSE: add 2 complex numbers
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator + (const Complex& rhs) const
{
	Complex<T> answer;

	answer.real = real + rhs.real;
	answer.imaginary = imaginary + rhs.imaginary;

	return answer;	
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator +=
PURPOSE: add 2 complex numbers and set left side = to result
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator += (const Complex& rhs)
{
	*this = *this + rhs;
	return *this;
}

/*-------------------------------------------------------------------------------------------------------------------------
											SUBTRACTION OF COMPLEX THINGS
-------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator -
PURPOSE: subtract Complex number - T (just a real number)
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator -(const T & num) const
{
	Complex<T> answer = *this;
	answer.real -= num;
	return answer;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator -=
PURPOSE: subtract a real number from a complex number and set lhs = to result
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator -= (const T& num)
{
	*this = *this - num;
	return *this;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator -
PURPOSE: subtract 2 complex numbers
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator - (const Complex& rhs) const
{
	return *this + rhs*-1;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator -=
PURPOSE: subtract 2 complex numbers and set lhs = to result
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator -=(const Complex& rhs)
{
	*this = *this - rhs;
	return *this;
}

/*-------------------------------------------------------------------------------------------------------------------------
											MULTIPLICATION OF COMPLEX THINGS
-------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator *
PURPOSE: multiply a complex number by a real number
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator *(const T & scale) const
{
	Complex<T> answer;

	answer.real = real * scale;
	answer.imaginary = imaginary * scale;

	return answer;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator *=
PURPOSE: multiplay a complex number by a real number and set lhs = result
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator *= (const T & scale)
{
	*this = *this * scale;
	return *this;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator *
PURPOSE: multiply 2 complex numbers
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator * (const Complex& rhs) const
{
	Complex<T> answer;

	answer.real = real * rhs.real - imaginary * rhs.imaginary;
	answer.imaginary = real * rhs.imaginary + imaginary * rhs.real;

	return answer;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator *
PURPOSE: multiply 2 Complex numbers and set lhs = to result
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator *= (const Complex& rhs)
{
	*this = *this * rhs;
	return *this;
}

/*-------------------------------------------------------------------------------------------------------------------------
											DIVISION OF COMPLEX THINGS
-------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator /
PURPOSE: divide a complex number by a constant
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator / (const T & scale) const
{
	Complex<T> answer;

	answer.real = real / scale;
	answer.imaginary = imaginary / scale;
	return answer;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator /=
PURPOSE: divide a complex number by a constant and set lhs = to result
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator /= (const T & scale)
{
	*this = *this / scale;
	return *this;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator /
PURPOSE: divide a complex number by another complex number
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator / (const Complex& rhs) const
{
	Complex<T> answer;

	answer = *this * rhs.conjugate();
	answer /= (rhs.real * rhs.real) + (rhs.imaginary * rhs.imaginary);

	return answer;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator /=
PURPOSE: divide 2 complex numbers and set lhs = to result
RETURNS: Complex<T>
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
Complex<T> Complex<T>::operator /= (const Complex& rhs)
{
	*this = *this / rhs;
	return *this;
}

/*-------------------------------------------------------------------------------------------------------------------------
											COMPARING COMPLEX THINGS
-------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator !=
PURPOSE: compare 2 Complex numbers
RETURNS: bool
NOTES:
-------------------------------------------------------------------------------------------*/
template <typename T>
bool Complex<T>::operator !=(const Complex& rhs) const
{
	if(real != rhs.real || imaginary != rhs.imaginary)
		return true;
	return false;	
}


/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator !=
PURPOSE: compare a complex number to a real number
RETURNS: bool
NOTES: if there is an imaginary part it cant be equal, kinda a tricky one
-------------------------------------------------------------------------------------------*/
template <typename T>
bool Complex<T>::operator !=(const T& rhs) const
{
	if(real != rhs || imaginary != 0)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator ==
PURPOSE: compare 2 complex numbers
RETURNS: bool
NOTES: both real and imaginary parts have to be equal
-------------------------------------------------------------------------------------------*/
template <typename T>
bool Complex<T>::operator ==(const Complex& rhs) const
{
	if(real == rhs.real && imaginary == rhs.imaginary)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator ==
PURPOSE: compare a complex number and a real number
RETURNS: bool
NOTES: imaginary part has to be 0
-------------------------------------------------------------------------------------------*/
template <typename T>
bool Complex<T>::operator ==(const T& rhs) const
{
	if(real == rhs &&imaginary == 0)
		return true;
	return false;
}

/*-------------------------------------------------------------------------------------------------------------------------
											IOSTREAM STUFF FOR COMPLEX THINGS
-------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator <<
PURPOSE: output operator for compex number
RETURNS: ostream&
NOTES: friend to class
-------------------------------------------------------------------------------------------*/
template <typename T>
ostream& operator << (ostream& out, const Complex<T>& z) 
{
	if(z.imaginary > 0 && z.real !=0)
		out << z.real << "+" << z.imaginary << "i";
	if(z.imaginary < 0 && z.real !=0)
		out << z.real << "-" << z.imaginary*-1 << "i";
	return out;
}

/*-------------------------------------------------------------------------------------------
FUNCTION NAME: overload operator >>
PURPOSE: input operator for complex number
RETURNS: istream&
NOTES: friend to class
-------------------------------------------------------------------------------------------*/
template <typename T>
istream& operator >> (istream& in, Complex<T>& z)
{
	//regex R("(\\+|-)?[[:digit:]]+((\\+|-)?(([[:digit:]]+)?)i)?");

	T re = 0;
	T im = 0;
	char plus_or_i;
	in >> re;
	in>> plus_or_i;
	if(plus_or_i == 'i')
	{
		z.real = 0;
		z.imaginary = re;
	}
	else if(plus_or_i == '+') 
	{
		z.real = re;
		in >> im;
		z.imaginary = im;
		in >> plus_or_i;
	}
	else if(plus_or_i == '-')
	{

		z.real = re;
		in >> im;
		z.imaginary = im * -1;
		in >> plus_or_i;
	}
	return in;

}