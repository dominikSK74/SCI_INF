#include "SortAlgorithm.h"

void SortAlgorithm::bubbleSort(std::vector<int>& vec)
{
	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < vec.size()-1; ++i)
	{
		for (int j = 0; j < vec.size()-1; ++j)
		{
			if (vec.at(j) > vec.at(j + 1))
			{
				int temp = vec.at(j);
				vec.at(j) = vec.at(j + 1);
				vec.at(j + 1) = temp;
			}
		}
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_secound = end - start;
	std::cout << "Bubble sort: " << elapsed_secound.count() << std::endl;
}

void SortAlgorithm::insertionSort(std::vector<int>& vec)
{
	auto start = std::chrono::steady_clock::now();
	int i, key, j;
	for (i = 1; i < vec.size(); i++) {
		key = vec.at(i);
		j = i - 1;

		while (j >= 0 && vec.at(j) > key)
		{
			vec.at(j + 1) = vec.at(j);
			j = j - 1;
		}
		vec.at(j + 1) = key;
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_secound = end - start;
	std::cout << "Insertion sort: " << elapsed_secound.count() << std::endl;
}

void SortAlgorithm::selectionSort(std::vector<int>& vec)
{
	auto start = std::chrono::steady_clock::now();
	int i, j, index;

	for (i = 0; i < vec.size() - 1; i++) {
		index = i;

		for (j = i + 1; j < vec.size(); j++) {
			if (vec.at(j) < vec.at(index))
			{
				index = j;
			}
		}
		std::swap(vec.at(index), vec.at(i));
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_secound = end - start;
	std::cout << "Selection sort: " << elapsed_secound.count() << std::endl;
}

void SortAlgorithm::standardSort(std::vector<int>& vec)
{
	auto start = std::chrono::steady_clock::now();
	std::sort(vec.begin(), vec.end());
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_secound = end - start;
	std::cout << "Standard sort: " << elapsed_secound.count() << std::endl;
}

void SortAlgorithm::quickSort(int left, int right, std::vector<int>& vec) {
	int i = (left + right) / 2;
	int piwot = vec.at(i);
	vec.at(i) = vec.at(right);
	int j = left;
	for (int i = left; i < right - 1; i++)
	{
		if (vec.at(i) < piwot)
		{
			int temp = vec.at(i);
			vec.at(i) = vec.at(j);
			vec.at(j) = temp;
			j++;
		}
	}
	vec.at(right) = vec.at(j);
	vec.at(j) = piwot;
	if (left < j - 1) {
		quickSort(left, j - 1, vec);
	}
	if (j + 1 < right) {
		quickSort(j + 1, right, vec);
	}
}