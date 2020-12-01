// First day of advent of code 2020
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

int main()
{
	std::vector<int> vec;
	std::ifstream file("dataDay1.txt");
	if  (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			vec.push_back(stoi(line));

		}
		file.close();
		//Sort the vectors so that we don't dó (too many ;)) unneccassry checks.
		std::sort(vec.begin(), vec.end());

		int target = 2020;
		int idx = 1;
		while (vec.at(idx - 1) + vec.at(idx) < 2020) { idx++; }
		for (int i = 0; i < idx; ++i)
		{
			for (int j = idx; j < vec.size(); ++j)
			{
				if (vec.at(i) + vec.at(j) == 2020)
				{
					std::cout << vec.at(i) * vec.at(j) << std::endl;
					goto part2;
				}
				if (vec.at(i) + vec.at(j) > 2020)
				{
					break;
				}
			}
		}
	//Part 2 of the solution, find the sum of 3 numbers that equal 2020. 
	part2: for (int i = 0; i < idx-2; ++i)
	{
		for (int j = 1; j < idx - 1; ++j)
		{
			for (int k = 2; k < idx; ++k)
			{
				if (vec.at(i) + vec.at(j) + vec.at(k) == 2020)
				{
					std::cout << vec.at(i) * vec.at(j) * vec.at(k) << std::endl;
					return 0;
				}
				if (vec.at(i) + vec.at(j) + vec.at(k) > 2020)
				{
					break;
				}
			}
		}
		
	}
	}
	return 0;
}