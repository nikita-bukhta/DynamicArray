#include "DynamicArray.h"

#include <iostream>
#include <string>
#include <stdexcept>

using namespace DynamicArray;

// includeAddingNewElement = false by defalt
//	but compiler don't allow write it in header
//	and cpp files;
template<class T>
bool DynamicArray::Array<T>::IndexInRange(const unsigned long long index, bool includeAddingNewElement)
{
	if ((includeAddingNewElement && index > _size) || (!includeAddingNewElement && index >= _size))
		throw std::out_of_range("Index (" + std::to_string(index) +
			") out of range ([0; " + std::to_string(_size) + "))!");

	return true;
}

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

	for (auto i = 0; i < this->_size; ++i)
		this->_array[i] = other._array[i];
}


template <class T>
Array<T>::Array(const unsigned long long size, T array[])
{
	this->_size = size;
	this->_array = new T[size];

	for (auto i = 0; i < size; ++i)
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
	for (auto i = 0; i < (_size - 1); ++i)
		temp[i] = _array[i];

	// add new elem;
	temp[_size - 1] = value;

	// clear our array in order to escape the memory leak;
	this->~Array();

	_array = temp;
}

template<class T>
void Array<T>::PopBack(void)
{
	if (_size <= 0)
		throw std::exception("You can't delete element from array, which size is less than 1!");

	T* temp = new T[--_size];

	// copy all elems and miss the last;
	for (auto i = 0; i < _size; ++i)
		temp[i] = _array[i];

	// clear our array in order to escape the memory leak;
	this->~Array();

	_array = temp;
}

template<class T>
void Array<T>::ShowInfo(void) const
{
	for (auto i = 0; i < _size; ++i)
		std::cout << _array[i] << std::endl;
}

template<class T>
T DynamicArray::Array<T>::At(const unsigned long long index) const
{
	// if we don't out of range;
	if (index < _size)
		return *(_array + index);

	throw std::out_of_range("Index (" + std::to_string(index) +
		") out of range ([0; " + std::to_string(_size) + "))!");
}

template<class T>
void DynamicArray::Array<T>::Insert(const unsigned long long index, const T& value)
{
	if (IndexInRange(index, true))
	{
		++_size;
		T* newArray = new T[_size];

		unsigned long long i;
		for (i = 0; i < index; ++i)
			newArray[i] = _array[i];

		newArray[i] = value;

		for (++i; i < _size; ++i)
		{
			newArray[i] = _array[i - 1];
		}

		// clear our array in order to escape the memory leak;
		this->~Array();
		_array = newArray;
	}
}

template<class T>
void DynamicArray::Array<T>::Remove(const unsigned long long index)
{
	if (IndexInRange(index))
	{
		const unsigned long long newSize = _size - 1;
		T* newArray = new T[newSize];

		unsigned long long i;
		for (i = 0; i < index; ++i)
			newArray[i] = _array[i];

		for (++i; i < _size; ++i)
			newArray[i - 1] = _array[i];

		// clear our array in order to escape the memory leak;
		this->~Array();
		_array = newArray;
		_size = newSize;
	}
}

template<class T>
void DynamicArray::Array<T>::Replace(const unsigned long long index, const T& value)
{
	if (IndexInRange(index))
		_array[index] = value;
}

template<class T>
unsigned long long DynamicArray::Array<T>::Size(void) const
{
	return _size;
}

template<class T>
T& Array<T>::operator[](const unsigned long long index) const
{
	return *(_array + index);
}

template<class T>
Array<T> Array<T>::operator=(const Array& other)
{
	// clear our array in order to escape the memory leak;
	this->~Array();

	this->_size = other._size;
	this->_array = new T[this->_size];

	for (auto i = 0; i < this->_size; ++i)
		this->_array[i] = other._array[i];

	return *this;
}

template<class T>
Array<T> Array<T>::operator+(const Array& other) const
{
	const auto newArraySize = this->_size + other._size;
	T* tempArray = new T[newArraySize];

	// Copy first array;
	for (auto i = 0; i < this->_size; ++i)
		tempArray[i] = this->_array[i];

	// Copy second array;
	for (auto i = this->_size; i < newArraySize; ++i)
		tempArray[i] = other._array[i - this->_size];

	Array<T> temp(newArraySize, tempArray);

	return temp;
}
