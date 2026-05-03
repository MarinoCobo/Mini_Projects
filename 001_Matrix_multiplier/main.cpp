#include <iostream>
#include <vector>
#include <string>
#include <sstream>


void matrix_Generator
(
    int rows, 
    int columns, 
    std::vector<std::vector<int>>& matrix
)
{   
    matrix.clear();
    matrix.resize(rows, std::vector<int>(columns, 0));
}


void matrix_Filler
(
    std::vector<std::vector<int>>& matrix
)
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
            ss >> integerHolder;
            matrix[i][j] = integerHolder;
        }
    }

} 
/*    for(int i = 0; i < numberOfRows - 1; i++)
    {
        int temporary{};
        std::cin.ignore();
        std::cout << "Enter row N°" << i+1;
        std::getline(std::cin, row);
        std::stringstream ss(row);
        while(ss >> temporary)
        {
            for(int j = 0; j < c.size(); j++)
            {
                c[j].push_back(temporary);
            }
        }
    }


}
    */
int main()
{
    std::vector<std::vector<int>> matrix;
    int rows;
    int columns;
    int option;

    do
    {
        std::cout << "\n===== MATRIX MULTIPLIER TEST MENU =====\n";
        std::cout << "1. Generate matrix\n";
        std::cout << "2. Fill matrix\n";
        std::cout << "3. Print matrix\n";
        std::cout << "4. Clear matrix\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> option;
        std::cin.ignore();

        switch(option)
        {
            case 1:
                std::cout << "Rows: ";
                std::cin >> rows;
                std::cout << "Columns: ";
                std::cin >> columns;
                std::cin.ignore();

                matrix_Generator(rows, columns, matrix);
                std::cout << "Matrix generated.\n";
                break;

            case 2:
                if(matrix.empty())
                {
                    std::cout << "Generate a matrix first.\n";
                }
                else
                {
                    matrix_Filler(matrix);
                    std::cout << "Matrix filled.\n";
                }
                break;

            case 3:
                if(matrix.empty())
                {
                    std::cout << "Matrix is empty.\n";
                }
                else
                {
                    for(size_t i = 0; i < matrix.size(); i++)
                    {
                        for(size_t j = 0; j < matrix[i].size(); j++)
                        {
                            std::cout << matrix[i][j] << " ";
                        }
                        std::cout << '\n';
                    }
                }
                break;

            case 4:
                matrix.clear();
                std::cout << "Matrix cleared.\n";
                break;

            case 0:
                std::cout << "Exiting.\n";
                break;

            default:
                std::cout << "Invalid option.\n";
                break;
        }

    } while(option != 0);

    return 0;
}

