#include <iostream>
#include <vector>

#include "DynamicArray.h"
	#include "DynamicArray.cpp" // to fix Linker Tools Error LNK2019

int main(int argc, char** argv)
{
	DynamicArray::Array<unsigned long long> array;
	for (auto i = 0; i < 10; i++)
	{
		array.PushBack(i);
		if (i % 3 != 0)
			array.Remove(array.Size() - 1);
	}

	array.ShowInfo();

	std::system("pause");

	return 0;
}