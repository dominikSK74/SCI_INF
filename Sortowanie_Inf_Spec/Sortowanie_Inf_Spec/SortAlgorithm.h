#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>

class SortAlgorithm
{
	public:
		void bubbleSort(std::vector<int>& vec);
		void insertionSort(std::vector<int>& vec);
		void selectionSort(std::vector<int>& vec);
		void standardSort(std::vector<int>& vec);
		void quickSort(int left, int right, std::vector<int>& vec);	
};

