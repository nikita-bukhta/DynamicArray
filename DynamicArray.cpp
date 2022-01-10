#include "DynamicArray.h"

#include <iostream>

template <class T>
Array<T>::Array()
{
	_size = 0;
	_array = nullptr;
}

template <class T>
Array<T>::Array(const Array& other)
{
	this->_size = other._size;

	this->_array = new T[this->_size];

	for (int i = 0; i < this->_size; i++)
		this->_array[i] = other._array[i];
}


template <class T>
Array<T>::Array(const unsigned long long size, T array[])
{
	this->_size = size;
	this->_array = new T[size];

	for (auto i = 0; i < size; i++)
	{
		this->_array[i] = array[i];
	}
}

template<class T>
Array<T>::~Array()
{
	if (_array != nullptr)
	{
		delete[] _array;
		_array = nullptr;
	}
}

template<class T>
void Array<T>::PushBack(T value)
{
	T* temp = new T[++_size];

	// copy all elems;
	for (auto i = 0; i < (_size - 1); i++)
		temp[i] = _array[i];

	// add new elem;
	temp[_size - 1] = value;

	// clear our array
	this->~Array();

	_array = temp;
}

template<class T>
void Array<T>::PopBack(void)
{
	if (_size <= 0)
		throw "You can't delete element from array, which size is less than 1!";

	T* temp = new T[--_size];

	// copy all elems and miss the last;
	for (auto i = 0; i < _size; i++)
		temp[i] = _array[i];

	// clear our array
	this->~Array();

	_array = temp;
}

template<class T>
void Array<T>::ShowInfo(void) const
{
	for (auto i = 0; i < _size; i++)
		std::cout << _array[i] << std::endl;
}

template<class T>
Array<T> Array<T>::operator=(const Array& other)
{
	// clear our array
	this->~Array();

	this->_size = other._size;
	this->_array = new T[this->_size];

	for (auto i = 0; i < this->_size; i++)
		this->_array[i] = other._array[i];

	return *this;
}

template<class T>
Array<T> Array<T>::operator+(const Array& other) const
{
	const auto newArraySize = this->_size + other._size;
	T* tempArray = new T[newArraySize];

	// Copy first array;
	for (auto i = 0; i < this->_size; i++)
		tempArray[i] = this->_array[i];

	// Copy second array;
	for (auto i = this->_size; i < newArraySize; i++)
		tempArray[i] = other._array[i - this->_size];

	Array<T> temp(newArraySize, tempArray);

	return temp;
}
