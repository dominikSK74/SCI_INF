#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "SortAlgorithm.h"

void timeQuick(SortAlgorithm ob, std::vector<int>& vec);

void genRandomValues(std::vector<int>& vec) 
{
	srand(time(NULL));
	for (int i = 0; i < vec.size(); i++)
	{
		vec.at(i) = rand() % 1000;
	}
}

void printVec(const std::vector<int>& vec)
{
	std::cout << "======================" << std::endl;
	for (int value : vec)
	{
		std::cout << value << std::endl;
	}
	std::cout << "======================" << std::endl;
}

int main()
{
	std::vector<int> vec(10000);
	genRandomValues(vec);
	SortAlgorithm ob1;
	//printVec(vec);
	
	std::cout << "Wybierz algorytm sortowania:" << std::endl;
	std::cout << "1. Bubble sort" << std::endl;
	std::cout << "2. Insertion sort" << std::endl;
	std::cout << "3. Selection sort" << std::endl;
	std::cout << "4. Standardowa biblioteka sort()" << std::endl;
	std::cout << "5. Quick sort" << std::endl;


	int x;
	while (true) {
		std::cin >> x;

		switch (x) {
		case 1:
			genRandomValues(vec);
			ob1.bubbleSort(vec);
			break;
		case 2:
			genRandomValues(vec);
			ob1.insertionSort(vec);
			break;
		case 3:
			genRandomValues(vec);
			ob1.selectionSort(vec);
			break;
		case 4:
			genRandomValues(vec);
			ob1.standardSort(vec);
			break;
		case 5:
			genRandomValues(vec);
			timeQuick(ob1, vec);
			break;
		default:
			std::cout << "Nie rozpoznano polecenia!" << std::endl;
		}
	}
	//printVec(vec);
}

void timeQuick(SortAlgorithm ob, std::vector<int>& vec) {
	auto start = std::chrono::steady_clock::now();
	ob.quickSort(0, vec.size() - 1, vec);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_secound = end - start;
	std::cout << "Quick sort: " << elapsed_secound.count() << std::endl;
}
