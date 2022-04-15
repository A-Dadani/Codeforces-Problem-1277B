/****************************************************
 *					Problem 1277B					*
 * https://codeforces.com/problemset/problem/1277/B *
 ****************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <utility>
#include <cmath>

int main()
{
	unsigned short int nCases;
	std::cin >> nCases;
	while (nCases--)
	{
		unsigned int vecSize;
		unsigned int ans = 0;
		std::vector<std::pair<unsigned int, unsigned char>> vec;
		std::cin >> vecSize;
		vec.resize(vecSize);
		for (auto& e : vec)
		{
			unsigned int temp;
			std::cin >> temp;
			if (temp % 2) continue;
			std::bitset<32> bin;
			bin |= temp;
			for (e.second = 0; bin[e.second] == 0; ++e.second);
			e.first = temp / (unsigned int)std::pow(2u, e.second);
		}
		std::sort(vec.begin(), vec.end(), [](std::pair<unsigned int, unsigned char> lhs, 
											std::pair<unsigned int, unsigned char> rhs) 
			{
			return (lhs.first == rhs.first ? lhs.second > rhs.second : lhs.first > rhs.first);
			});
		vec.erase(std::unique(vec.begin(), vec.end(), [](std::pair<unsigned int, unsigned char> lhs,
														std::pair<unsigned int, unsigned char> rhs) 
			{
				return (lhs.first == rhs.first);
			}), vec.end());
		for (const auto& e : vec) ans += e.second;
		std::cout << ans << "\n";
	}
	return 0;
}