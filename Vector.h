//first attempt at making a vector class
/* 
funcitons needed to be implemented:
-will need to use templating


-[]


*/
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <stdexcept>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])     

template <typename DataType>
class vector 
{
private:
	DataType *thing;
	int size_of_vector;

public:
	vector();
	vector(int);
	vector(int, DataType);
	~vector();
	int size() const;
	int begin() const;
	int end() const;
	void resize(int);
	void resize(int, const DataType&);
	void insert(int unsigned position, int spaces, const DataType &value);
	void erase(int start, int end);
	DataType& operator [] (int index);
	const DataType& operator [] (int index) const;
	
};

#include "Vector.cpp" //because of template thing	

#endif //__VECTOR_H__