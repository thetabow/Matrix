
//#include "vector.h"

//default constructor
template <typename DataType>
vector<DataType>::vector()
{
	thing = nullptr;
	size_of_vector = 0;
}

//constructor with a determined size
template <typename DataType>
vector<DataType>::vector(int s)
{
	thing = new DataType [s];
	size_of_vector = s;
}

//constructor with a determined size and preset entry for every element
template <typename DataType>
vector<DataType>::vector(int s, DataType q)
{
	thing = new DataType [s];
	size_of_vector = s;
	for(int i = 0; i < s; i++)
	{
		*(thing + i) = q;
	}
}

//destructor
template <typename DataType>
vector<DataType>::~vector()
{
	delete[] thing;
}

//returns the size of the array
template <typename DataType>
int vector<DataType>::size() const
{
	return size_of_vector;
}

//gives "start" of vector
template <typename DataType>
int vector<DataType>::begin() const
{
	return 0;
}
template <typename DataType>
int vector<DataType>::end() const
{
	return size_of_vector - 1;
}

//resizes array by adding elements to end of array
template <typename DataType>
void vector<DataType>::resize(int new_size)
{
	DataType *temp;
	temp = new DataType [new_size];
	for(int i = 0; i < size_of_vector && i < new_size; i++)
		*(temp + i) = *(thing + i);
	delete[] thing;
	thing = temp;
	size_of_vector = new_size;
}

//resizes array by adding elements to end of array and fills new elements with given value
template <typename DataType>
void vector<DataType>::resize(int new_size, const DataType& q)
{
	DataType *temp;
	temp = new DataType [new_size];
	for(int i = 0; i < size_of_vector && i < new_size; i++)
		*(temp + i) = *(thing + i);
	delete[] thing;
	thing = temp;
	if(new_size > size_of_vector)
		for(int i = size_of_vector; i < new_size; i ++)
			*(thing + i) = q;

	size_of_vector = new_size;
}

//
template <typename DataType>
void vector<DataType>::insert(int unsigned position, int spaces, const DataType &value)
{
	DataType *temp;
	int new_size = size_of_vector + spaces;
	temp = new DataType [new_size];

	if(position > 0)
		for(int i = 0; i < position; i++)
			temp[i] = thing[i];

	for(int i = position; i < position + spaces; i++)
		temp[i] = value;

	for(int i = position + spaces; i < new_size; i++)
		temp[i] = thing[i-spaces];

	delete[] thing;
	thing = temp;
	size_of_vector = new_size;
}

template <typename DataType>
void vector<DataType>::erase(int start, int end)
{
	int ditch = end - start;
	int new_size = size_of_vector - ditch;
	DataType *temp;
	temp = new DataType [new_size];

	for(int i = 0; i < start; i++)
		temp[i] = thing[i];

	for(int i = end; i < size_of_vector; i++)
		temp[i - ditch] = thing[i];

	delete[] thing;
	thing = temp;
	size_of_vector = new_size;
}


template <typename DataType>
DataType& vector<DataType>::operator [] (int index)
{
	if(index < size_of_vector)
		return *(thing + index);
	else
		throw out_of_range("Out of bounds");
}

template <typename DataType>
const DataType& vector<DataType>::operator [] (int index) const
{
	if(index < size_of_vector)
		return *(thing + index);
	else
		throw out_of_range("Out of bounds");
}