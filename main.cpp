#include <iostream>
#include <string>

#include "DynamicArray.h"
	#include "DynamicArray.cpp" // to fix Linker Tools Error LNK2019

int main(int argc, char** argv)
{
	
	Array<int> array;
	Array<int> array2;
	
	for (auto i = 0; i < 10; i++)
	{
		array.PushBack(i);
		array2.PushBack(i);
	}

	auto array3 = array + array2;
	array3.ShowInfo();

	std::system("pause");

	return 0;
}