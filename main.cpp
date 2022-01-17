#include <iostream>
#include <vector>
#include <string>

#include "DynamicArray.h"
	#include "DynamicArray.cpp" // to fix Linker Tools Error LNK2019

int main(int argc, char** argv)
{
	DynamicArray::Array<int> array;

	for (auto i = 0; i < 5; ++i)
	{
		array.PushBack(rand() % 500);
	}

	auto b = array;
	array.Sort();
	b.PushBack(9999);
	b.ShowInfo();
	std::cout << "B size: " << b.Size() << std::endl;
	std::cout << "-----------------" << std::endl;
	array.ShowInfo();
	std::cout << "Array size: " << array.Size() << std::endl;
	std::cout << "SWAP-----------------SWAP" << std::endl;
	b.Swap(array);
	b.ShowInfo();
	std::cout << "B size: " << b.Size() << std::endl;
	std::cout << "-----------------" << std::endl;
	array.ShowInfo();
	std::cout << "Array size: " << array.Size() << std::endl;

	std::system("pause");

	return 0;
}