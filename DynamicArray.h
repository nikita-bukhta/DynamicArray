#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// TODO:
//	2) add Replace(const T& newValue, const unsigned long long index) method ;
//	3) add Find(const T& value) method;
//	4) add Sort methodl
//	5) add reverse method;

namespace DynamicArray
{
	// Array with many useful methods.
	//	Built with dynamic array;
	// 
	// DynamicArray.h
	template <class T>
	class Array
	{
	private:
		unsigned long long _size;
		T* _array;

		// I think that user shouldn't use this, because
		//	they can make some errors with memory!
		//
		// DynamicArray.h
		Array(const unsigned long long size, T array[]);

		// If	index in range return true;
		// Else throw exception;
		//
		// index - which index we check;
		// includeAddingNewElement - check if we want to
		//	check if index == _size;
		//
		// DynamicArray.h
		bool IndexInRange(const unsigned long long index, bool includeAddingNewElement = false);

	public:
		// DynamicArray.h
		Array();

		// constructor of copying;
		//
		// DynamicArray.h
		Array(const Array& other);

		// DynamicArray.h
		~Array();

		// push one element in the end of array;
		// 
		// DynamicArray.h
		void PushBack(T value);

		// delete one element in the end of array;
		//
		// DynamicArray.h
		void PopBack(void);

		// display array information on the screen;
		//
		// DynamicArray.h
		void ShowInfo(void) const;

		// return COPPY of value in array by index if it is exist;
		// 
		// const unsigned long long index - index of element;
		// 
		// throw std::out_of_range exception if index
		//	is out of range;
		//
		// DynamicArray.h
		T At(const unsigned long long index) const;

		// insert element into our array between
		//	_array[index - 1] && _array[index + 1];
		//
		// index - where we want to insert element;
		// value - what we want to insert;
		//
		// throw std::out_of_range exception if index
		//	is out of range;
		//
		// DynamicArray.h
		void Insert(const unsigned long long index, const T& value);

		// Remove element from array by index;
		//
		// index - which element we want to remove by this index;
		//
		// throw std::out_of_range exception if index
		//	is out of range;
		//
		// DynamicArray.h
		void Remove(const unsigned long long index);

		// Change element of array with specified index to
		//	specified value;
		//
		// value - what we want to paste;
		// index - where we want to replace;
		//
		// throw std::out_of_range exception if index
		//	is out of range;
		//
		// DynamicArray.h
		void Replace(const unsigned long long index, const T& value);

		// Return count of elements in array;
		unsigned long long Size(void) const;

		// get element of _array;
		T& operator[](const unsigned long long index) const;

		Array<T> operator=(const Array& other);

		Array<T> operator+(const Array& other) const;
	};
}

#endif // ! DYNAMIC_ARRAY_H