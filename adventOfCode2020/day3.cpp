//Advent of code 2020 day 3
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

void calculateTrees(const std::vector<std::string>& map, std::vector<std::pair<int, int>> positions)
{
	int currentX;
	int currentY;
	int trees;
	int64_t result = 1;
	for (int i = 0; i < positions.size(); ++i)
	{
		currentX = 0;
		currentY = 0;
		trees = 0;
		std::cout << positions[i].first << ' ' << positions[i].second << std::endl;
		while (currentY < map.size())
		{
			currentX = currentX % map.at(currentY).size();
			if (map.at(currentY).at(currentX) == '#')
			{
				++trees;
			}
			currentX += positions[i].first;
			currentY += positions[i].second;
		}
		result *= trees;
	}
	std::cout << result << std::endl;
}

int main()
{
	int trees = 0, counter = 0;
	std::vector<std::string> map;
	std::ifstream file("dataDay3.txt");
	for (std::string line ; std::getline(file, line) ;)
	{
		map.push_back(line);
	}
	file.close();
	std::vector<std::pair<int, int>> vec;
	vec.push_back(std::make_pair(3, 1));
	//Part 1
	calculateTrees(map, vec);
	//Part 2
	vec.push_back(std::make_pair(1, 1));
	vec.push_back(std::make_pair(5, 1));
	vec.push_back(std::make_pair(7, 1));
	vec.push_back(std::make_pair(1, 2));
	calculateTrees(map, vec);

	return 0;
}