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
    // std::ifstream file("data_easy.txt");
    std::ifstream file("data.txt");

    int currentPos = 50;

    while (getline(file, dataLine))
    {
        char c = dataLine[0];
        int number = stoi(dataLine.substr(1)) % 100;
        switch (c)
        {
        case 'R':
            currentPos += number;
            currentPos = currentPos % 100;
            break;
        case 'L':
            currentPos -= number;
            if (currentPos < 0)
            {
                currentPos = 100 + currentPos;
            }
            break;
        }
        if (currentPos == 0)
        {
            result++;
        }
    }
    std::cout << "Result: " << result << std::endl;

    file.close();
}