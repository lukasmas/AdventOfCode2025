///
/// https://adventofcode.com/2025/day/5
///

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>

int main()
{

    std::cout << "AoC 2025 DAY 5" << std::endl;
    int result = 0;
    std::string dataLine = "";
    // std::ifstream file("day5/data_easy.txt");
    std::ifstream file("day5/data.txt");

    std::map<uint64_t, uint64_t> sections = {};
    std::set<uint64_t> ids = {};

    while (getline(file, dataLine), dataLine != "")
    {
        int pos = dataLine.find('-');
        uint64_t begin = std::stoull(dataLine.substr(0, pos));
        uint64_t end = std::stoull(dataLine.substr(pos + 1, dataLine.length() - pos));
        if (sections.find(begin) != sections.end())
        {
            sections[begin] = std::max(end, sections[begin]);
        }
        else
        {
            sections[begin] = end;
        }
    }

    while (getline(file, dataLine))
    {
        ids.emplace(std::stoull(dataLine));
    }

    for (auto &range : sections)
    {
        std::set<uint64_t>::iterator it = ids.begin();
        for (const auto &id : ids)
        {
            if (id >= range.first && id <= range.second)
            {
                result++;
            }
            if (id <= range.second)
            {
                it++;
            }
        }
        if (it != ids.begin())
        {
            ids.erase(ids.begin(), it);
        }
    }

    file.close();

    std::cout << "Result: " << result << std::endl;
}