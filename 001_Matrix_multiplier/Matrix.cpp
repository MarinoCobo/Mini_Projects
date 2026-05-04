#include "Matrix.h"
#include <iostream>
#include <sstream>
#include <iomanip>


void Matrix::resize(int r, int c)
{
    matrix.clear();
    matrix.resize(r, std::vector<int> (c, 0));
}

void Matrix::fill()
{
    std::string temporary;
    int integerHolder;

    for(size_t i = 0; i < matrix.size(); i++)
    {
        std::cout << "Enter row N°" << i + 1 << ": ";
        std::getline(std::cin, temporary);
        std::stringstream ss(temporary);

        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            if (!(ss >> integerHolder))
            {
                std::cout << "Invalid input. Not enough valid integers.\n";
                i -= 1;
            }
            else
            {
            matrix[i][j] = integerHolder;
            }
        }

        std::string extra;
        if (ss >> extra)
        {
            std::cout << "Invalid input. Too many values.\n";
            i-= 1;
        }
    }
}

void Matrix::print()
{
    if (matrix.empty() || matrix[0].empty())
    {
        std::cout << "Matrix is empty.\n";
        return;
    }

    const int width = 5;

    for (size_t row = 0; row < matrix.size(); row++)
    {
        std::cout << "|";

        for (size_t col = 0; col < matrix[row].size(); col++)
        {
            std::cout << std::setw(width) << matrix[row][col] << " |";
        }

        std::cout << '\n';

        for (size_t col = 0; col < matrix[row].size(); col++)
        {
            std::cout << "-------";
        }

        std::cout << "-\n";
    }
}

void Matrix::changeNumber()
{
}

