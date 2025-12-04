///
/// https://adventofcode.com/2025/day/4
///

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

enum position
{
    previous = 0,
    current = 1,
    next = 2,
};

constexpr char paper = '@';

int GetMovablePaperCount(std::string rows[])
{
    int paperToMoveInRow = 0;
    for (int p = 0; p < static_cast<int>(rows[current].length()); ++p)
    {
        if (rows[current][p] == paper)
        {
            int start = p == 0 ? 0 : -1;
            int last = p == static_cast<int>(rows[current].length()) - 1 ? 0 : 1;
            std::string positions = "";

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
                paperToMoveInRow++;
            }
        }
    }
    return paperToMoveInRow;
}

int main()
{

    std::cout << "AoC 2025 DAY 4" << std::endl;
    int result = 0;
    std::string dataLine = "";
    // std::ifstream file("day4/data_easy.txt");
    std::ifstream file("day4/data.txt");

    std::string rows[3] = {"", "", ""};

    getline(file, rows[current]);

    while (getline(file, rows[next]))
    {
        result += GetMovablePaperCount(rows);
        rows[previous] = rows[current];
        rows[current] = rows[next];
        rows[next] = "";
    }
    result += GetMovablePaperCount(rows);

    file.close();

    std::cout << "Result: " << result << std::endl;
}