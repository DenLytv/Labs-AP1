#include <iostream>
#include <vector>
#include <cmath>
#define N 12

void fillArr(std::vector<int>& arr);
void calculation(std::vector<int> arr, int& maxOdd, int& evenCount);

int main()
{
	srand(static_cast<unsigned>(time(NULL)));
	std::vector<int> arr(N);
	int maxOdd = 2, evenCount = 0;

	fillArr(arr);
	calculation(arr, maxOdd, evenCount);

	if (maxOdd == 2)
		std::cout << "There are no odd numbers in array" << std::endl;
	else
		std::cout << "Max odd number: " << maxOdd << std::endl;

	std::cout << "Count of even: " << evenCount << std::endl;

	return 0;
}

void fillArr(std::vector<int>& arr)
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 201 - 100;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void calculation(std::vector<int> arr, int& maxOdd, int& evenCount)
{
	for (int i = 0; i < N; i++)
	{
		if (arr[i] % 2 == 0)
			++evenCount;
		else if (arr[i] % 2 != 0 && arr[i] > maxOdd)
			maxOdd = arr[i];
	}
}