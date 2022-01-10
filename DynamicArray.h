#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// TODO:
//		1) operator[] to get element from array
//		2) method Get(unsigned long long index) to get index without going outside of array
//		3) method Insert(const T elem, unsigned long long index) to push elem to certain position.
//			If we went out of range more than one, throw the expetion;
//		4) method Size() to get the array size;
//

template <class T>
class Array
{
private:
	unsigned long long _size;
	T* _array;

	Array(const unsigned long long size, T array[]);

public:
	// NewArray.h
	Array();

	Array(const Array& other);

	~Array();

	// push one element in the end of array;
	void PushBack(T value);

	// delete one element in the end of array
	void PopBack(void);

	// display array information on the screen
	void ShowInfo(void) const;

	Array<T> operator=(const Array& other);

	Array<T> operator+(const Array& other) const;
};

#endif // ! DYNAMIC_ARRAY_H