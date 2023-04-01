/*
* @file main.cpp
* @brief main-файл
*/
#include <iostream>
#include "lect.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "sortings.h"
#include <chrono>
#include "finds.h"
#include <map>
#include <iterator>

using namespace std;
/*
Массив данных о преподавателях: 
ФИО преподавателя, факультет, ученое звание, ученая степень 
(сравнение по  полям - факультет, ФИО, степень, звание)
*/
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    // Подсчёт времени сортировки 100, 500, 1000, 2500, 5000, 20000,40000, 80000 и 100000 строк таблицы
    //
    int data_size = 100000; // TO CHANGE
    std::string key = "Andre F. Frost"; // TO CHANGE
    std::vector<lect> data(data_size);
    int i = 0;

    std::ifstream file("Array.txt");

    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            if (i >= data_size) break;
            std::string l_name1, l_name2, l_name3, l_fac, l_degree, l_title1, l_title2;
            std::istringstream iss(line);
            iss >> l_name1 >> l_name2 >> l_name3 >> l_fac >> l_degree >> l_title1 >> l_title2;
            std::string l_name = l_name1 + " " + l_name2 + " " + l_name3;
            std::string l_title = l_title1 + " " + l_title2;
            data[i].setData(l_name, l_fac, l_degree, l_title);
            i++;
        }
    }
    else { std::cout << "не удалось открыть файл Array.txt"; }
    file.close();


    auto start = chrono::steady_clock::now();
    quickSort(data, 0, data_size - 1);
    auto end = chrono::steady_clock::now();
    cout << "Sorting (size is " << data_size<<")" << " :" << '\n' << "Elapsed time in microseconds : "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()<< '\n' << '\n';

    auto start2 = chrono::steady_clock::now();
    int ans = linear(data, 0, data_size - 1, key);
    auto end2 = chrono::steady_clock::now();
    std::cout << "Linear,position is " << ans << '\n';
    cout << "Elapsed time in microseconds : "
        << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << '\n' << '\n';


    auto start1 = chrono::steady_clock::now();
    ans = binary(data, 0, data_size - 1, key);
    auto end1 = chrono::steady_clock::now();
    std::cout << "Binary, position is " << ans << '\n';
    cout << "Elapsed time in microseconds : "
        << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << '\n' << '\n';


    std::ofstream outf1{ "LAB2.txt" };
    for (int i = 0; i < data.size(); i++)
    {
        outf1 << data[i].getName() << '\t' << data[i].getFac() << '\t' << data[i].getDegree() << '\t' << data[i].getTitle() << '\n';
    }
    outf1.close();




    std::ifstream file1("Array.txt");
    std::multimap<string, string> cont;

    if (file1.is_open())
    {
        std::string line;
        while (getline(file1, line))
        {
            if (i >= data_size) break;
            std::string l_name1, l_name2, l_name3, l_fac, l_degree, l_title1, l_title2;
            std::istringstream iss(line);
            iss >> l_name1 >> l_name2 >> l_name3 >> l_fac >> l_degree >> l_title1 >> l_title2;
            std::string l_name = l_name1 + " " + l_name2 + " " + l_name3;
            std::string l_other = l_fac + '\t' + l_degree + '\t' + l_title1 + " " + l_title2;
            cont.insert(pair<string, string>(l_name, l_other));
            i++;
        }
    }
    else { std::cout << "не удалось открыть файл Array.txt"; }
    file1.close();


    auto start3 = chrono::steady_clock::now();
    cont.find(key);
    auto end3 = chrono::steady_clock::now();
    std::cout << "Multimap \n" << "Elapsed time in microseconds : "<< chrono::duration_cast<chrono::microseconds>(end3 - start3).count() << '\n' << '\n';

    return 0;
}
