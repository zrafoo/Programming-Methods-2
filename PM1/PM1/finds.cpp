/*
* @file finds.cpp
* @brief файл реализации поисков
*/
#include "finds.h"
#include <string>

/** @brief  Реализация линейного поиска
	*/
int linear(std::vector<lect>& data, int start, int size, std::string l)
{
	for (int i = start; i <= size; i++)
		if (data[i].name == l) return i;
	return -1;
}
/** @brief Реализация бинарного поиска
	*/
int binary(std::vector<lect>& data, int start, int end, std::string l)
{
	if (start > end)
		return -1;
	const int middle = start + ((end - start) / 2);

	if (data[middle].name == l)
		return middle;
	else if (data[middle].name > l)
		return binary(data, start, middle - 1, l);

	return binary(data, middle + 1, end, l);
}
