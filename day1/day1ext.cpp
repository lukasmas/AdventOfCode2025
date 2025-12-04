///
/// https://adventofcode.com/2025/day/1
///

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

int main()
{
    std::cout << "AoC 2025 DAY 1" << std::endl;
    int result = 0;
    std::string dataLine = "";
    // std::ifstream file("day1/data_easy.txt");
    std::ifstream file("day1/data.txt");

    int currentPos = 50;

    while (getline(file, dataLine))
    {
        int number = stoi(dataLine.substr(1)) % 100;
        result += (stoi(dataLine.substr(1)) / 100);
        bool was0 = currentPos == 0;
        switch (dataLine[0])
        {
        case 'R':
            currentPos += number;
            result += currentPos / 100;
            currentPos = currentPos % 100;
            break;
        case 'L':
            currentPos -= number;
            if (currentPos <= 0)
            {
                int tmp = (currentPos / -100) + 1;
                result += was0 ? 0 : tmp;
                currentPos = (tmp * 100 + currentPos) % 100;
                break;
            }
        }
    }
    std::cout << "Result: " << result << std::endl;
    file.close();
}