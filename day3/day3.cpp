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
    int result = 0;
    std::string dataLine = "";
    // std::ifstream file("day3/data_easy.txt");
    std::ifstream file("day3/data.txt");

    while (getline(file, dataLine))
    {
        char firstDigit = '0';
        int largestJoltage = 0;

        for (int i = 0; i < strlen(dataLine.c_str()); ++i)
        {
            char c = dataLine[i];
            if (firstDigit < c && i < strlen(dataLine.c_str()) - 1)
            {
                firstDigit = c;
                continue;
            }
            char numberChar[2] = {firstDigit, c};
            int number = atoi(numberChar);

            if (largestJoltage < number)
            {
                largestJoltage = number;
            }
        }
        result += largestJoltage;
    }
    file.close();

    std::cout << "Result: " << result << std::endl;
}