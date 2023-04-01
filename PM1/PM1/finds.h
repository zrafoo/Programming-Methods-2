/*
* @file finds.h
* @brief header поисков
*/
#pragma once
#include <vector>
#include <string>
#include "lect.h"
/** @brief Линейный поиск
	*/
int linear(std::vector<lect>& data, int start,int size, std::string l);
/** @brief Бинарный поиск
	*/
int binary(std::vector<lect>& data, int start, int end, std::string l);