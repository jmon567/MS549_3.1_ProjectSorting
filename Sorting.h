#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <functional>

#ifndef SORTING_H
#define SORTING_H

using namespace std;

void bubbleSort(vector<int>& arr);
void mergeSort(vector<int>& arr, int left, int right);

double measureTime(function<void()> func);

#endif // SORTING_H




