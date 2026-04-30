#include <iostream>
#include <vector>
#include <string>
#include <sstream>


void matrix_Generator
(
    int rows, 
    int columns, 
    std::vector<int>& r,
    std::vector<std::vector<int>> c
)
{   
    std::vector<int> rowsVector;
    std::vector<std::vector<int>> columnsVector;
}


void matrix_Filler
(
    int rows,  
    std::vector<int>& r,
    std::vector<std::vector<int>>& c
)
{
    std::string temporary;
    int number;
    for(int i = 0; i < rows - 1; i++)
    {
        std::cout << "Enter row N°" << i + 1;
        std::getline(std::cin, temporary);
        std::stringstream ss(temporary);
        for (size_t j = 0; j < c[i].size(); j++)
        {
            ss >> number;
            c[0].push_back(number);
        }
         
    }

} 