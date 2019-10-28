#pragma once
#include <string>
#include <iostream>
template<typename T>
void PrintTable(T* tab, int size) {

	for (int i = 0; i < size; i++)
	{
		std::cout << tab[i] << "; ";
	}
	std::cout << std::endl;
}

