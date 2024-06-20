#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <vector>

void CleanVec(std::vector<int>& vec);
void SortVec(std::vector<int>& vec);
void PrintVec(std::vector<int> vec);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	std::vector<int> vec(20);

	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = rand() % 41 - 20;
	}

	std::cout << "Vector:\n";
	PrintVec(vec);

	CleanVec(vec);

	std::cout << "\n\nCleaned Vector:\n";
	PrintVec(vec);

	SortVec(vec);

	std::cout << "\n\nSorted Vector:\n";
	PrintVec(vec);

	int size = vec.size();
	std::vector<int> totalVec(size);

	for (int i = 0; i < size; i++)
	{
		totalVec[i] = vec[i];
	}

	return 0;
}

void CleanVec(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] <= 0)
		{
			vec.erase(vec.begin() + i);
			i = -1;
		}
	}
}

void SortVec(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
	{
		int iMin = i;

		for (int j = i + 1; j < vec.size(); j++)
		{
			if (vec[j] < vec[iMin])
			{
				iMin = j;
			}
		}
		int temp = vec[i];
		vec[i] = vec[iMin];
		vec[iMin] = temp;
	}
}

void PrintVec(std::vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
}

