///
/// https://adventofcode.com/2025/day/3
///

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

int main()
{
    std::cout << "AoC 2025 DAY 3" << std::endl;
    uint64_t result = 0;
    std::string dataLine = "";
    // std::ifstream file("day3/data_easy.txt");
    std::ifstream file("day3/data.txt");
    constexpr uint digits = 12;

    while (getline(file, dataLine))
    {
        std::string largestJoltage = "000000000000";

        // uint d = strlen(dataLine.c_str()) - i >= digits ? 0 : digits - (strlen(dataLine.c_str()) - i);
        // std::cout << "d: " << d << " i: " << i << std::endl;
        size_t i = 0;
        size_t tmp = 0;
        for (uint d = 0; d < digits; ++d)
        {
            for (; i < strlen(dataLine.c_str()); ++i)
            {
                char c = dataLine[i];
                if (largestJoltage[d] < c)
                {
                    if (strlen(dataLine.c_str()) - i < digits - d)
                    {
                        break;
                    }
                    largestJoltage[d] = c;
                    tmp = i + 1;

                    // for (int j = 1; j < digits - d; ++j)
                    // {
                    //     std::cout << j + j << " : " << largestJoltage[j + d] << " : " << dataLine[j + i] << std::endl;
                    //     if (largestJoltage[j + d] < dataLine[j + i])
                    //     {
                    //         largestJoltage[j + d] = dataLine[j + i];
                    //     }
                    // }
                    // break;
                }
            }
            i = tmp;
        }
        // std::cout << largestJoltage << std::endl;
        // break;

        std::cout << dataLine << ": " << largestJoltage << std::endl;
        result += std::stoull(largestJoltage);
    }
    file.close();

    std::cout << "Result: " << result << std::endl;
}