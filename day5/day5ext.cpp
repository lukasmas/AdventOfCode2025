///
/// https://adventofcode.com/2025/day/5
///

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

bool TryExtendRange(std::vector<std::pair<uint64_t, uint64_t>> &sections, uint64_t begin, uint64_t end)
{
    for (auto &p : sections)
    {
        if (begin >= p.first && end <= p.second)
        {
            // Already included in range
            return true;
        }

        if (begin < p.first && end >= p.first && end <= p.second)
        {
            // Extend from left site
            p.first = begin;
            return true;
        }

        if (begin >= p.first && end > p.second && begin <= p.second)
        {
            // Extend from right site
            p.second = end;
            return true;
        }

        if (begin <= p.first && end >= p.second)
        {
            // Extend from both site
            p.second = end;
            p.first = begin;
            return true;
        }
    }
    return false;
}

int main()
{
    std::cout << "AoC 2025 DAY 5" << std::endl;
    uint64_t result = 0;
    std::string dataLine = "";
    // std::ifstream file("day5/data_easy.txt");
    std::ifstream file("day5/data.txt");

    std::vector<std::pair<uint64_t, uint64_t>> sections = {};
    std::map<uint64_t, uint64_t> sectionsMap = {};

    while (getline(file, dataLine), dataLine != "")
    {
        int pos = dataLine.find('-');
        uint64_t begin = std::stoull(dataLine.substr(0, pos));
        uint64_t end = std::stoull(dataLine.substr(pos + 1, dataLine.length() - pos));
        if (sectionsMap.find(begin) != sectionsMap.end())
        {
            sectionsMap[begin] = std::max(end, sectionsMap[begin]);
        }
        else
        {
            sectionsMap[begin] = end;
        }
    }
    for (const auto &s : sectionsMap)
    {
        if (!TryExtendRange(sections, s.first, s.second))
        {
            sections.push_back({s.first, s.second});
        }
    }

    for (const auto &s : sections)
    {

        result += s.second - s.first + 1;
    }

    file.close();

    std::cout << "Result: " << result << std::endl;
}