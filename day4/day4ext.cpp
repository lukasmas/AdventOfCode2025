///
/// https://adventofcode.com/2025/day/4
///

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

enum position
{
    previous = 0,
    current = 1,
    next = 2,
};

constexpr char paper = '@';
constexpr char removed = 'x';

int GetMovablePaperCount(std::string rows[], std::vector<uint> &localization)
{
    int paperToMoveInRow = 0;
    for (int p = 0; p < static_cast<int>(rows[current].length()); ++p)
    {
        if (rows[current][p] == paper)
        {
            int start = p == 0 ? 0 : -1;
            int last = p == static_cast<int>(rows[current].length()) - 1 ? 0 : 1;

            uint paperAround = 0;
            for (int i = start; i <= last; i++)
            {
                if (rows[previous] != "")
                {
                    if (rows[previous][p + i] == paper)
                    {
                        paperAround++;
                    }
                }
                if (i != 0)
                {
                    if (rows[current][p + i] == paper)
                    {
                        paperAround++;
                    }
                }
                if (rows[next] != "")
                {
                    if (rows[next][p + i] == paper)
                    {
                        paperAround++;
                    }
                }
            }
            if (paperAround < 4)
            {
                localization.push_back(p);
                paperToMoveInRow++;
            }
        }
    }
    return paperToMoveInRow;
}

int RemovePaper(std::vector<std::string> &layout, std::map<uint, std::vector<uint>> &localization)
{
    int count = 0;
    for (int i = 0; i < layout.size(); ++i)
    {
        for (const auto &l : localization[i])
        {
            layout[i][l] = removed;
            count++;
        }
        localization[i].clear();
    }
    return count;
}

int main()
{
    std::cout << "AoC 2025 DAY 4" << std::endl;
    std::vector<std::string> fabricLayout;
    int result = 0;
    std::string dataLine = "";
    uint index = 0;
    // std::ifstream file("day4/data_easy.txt");
    std::ifstream file("day4/data.txt");

    std::string rows[3] = {"", "", ""};

    getline(file, rows[current]);
    fabricLayout.push_back(rows[current]);
    std::map<uint, std::vector<uint>> localization{};
    while (getline(file, rows[next]))
    {
        localization[index] = {};
        fabricLayout.push_back(rows[next]);
        result += GetMovablePaperCount(rows, localization[index]);
        rows[previous] = rows[current];
        rows[current] = rows[next];
        rows[next] = "";
        index++;
    }
    result += GetMovablePaperCount(rows, localization[index]);

    file.close();

    while (RemovePaper(fabricLayout, localization) != 0)
    {
        for (int row = 0; row < fabricLayout.size(); ++row)
        {
            rows[previous] = row == 0 ? "" : fabricLayout[row - 1];
            rows[current] = fabricLayout[row];
            rows[next] = row == fabricLayout.size() - 1 ? "" : fabricLayout[row + 1];
            result += GetMovablePaperCount(rows, localization[row]);
        }
    }

    std::cout << "Result: " << result << std::endl;
}