//Advent of code 2020 day 2
#include <iostream>
#include <tuple>
#include <fstream>
#include <string>
#include <algorithm>

std::tuple<int, int, char, std::string> getParams(const std::string& str)
{
	int lower, upper;
	char target;
	std::string password;
	std::size_t dash = str.find('-');
	std::size_t semicolon = str.find(' ');
	std::size_t letter = str.find(':');
	
	lower  = stoi(str.substr(0,dash));
	upper  = stoi(str.substr(dash+1, semicolon));
	target = str[letter-1];
	password = str.substr(letter + 2);

	return std::make_tuple(lower, upper, target, password);
}


int day2()
{
	std::ifstream file("dataDay2.txt");
	if (file.is_open())
	{
		int lower, upper, occurance, counter1 = 0, counter2 = 0;
		char target;
		std::string password;
		std::string line;
		while (std::getline(file, line))
		{
			std::tie(lower, upper, target, password) = getParams(line);
			occurance = std::count(password.begin(), password.end(), target);
			if (occurance < lower || occurance > upper)
			{
				//continue;
			}
			else
			{
				++counter1;
			}
			
			if (password[lower-1] == target && password[upper-1] == target)
			{
				//continue;
			}
			else if (password[lower-1] == target || password[upper-1] == target)
			{
				++counter2;
			}
			

		}
		std::cout << counter1 << std::endl;
		std::cout << counter2 << std::endl;
	}
	return 0;
}

