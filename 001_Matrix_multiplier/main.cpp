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

std::vector<std::vector<int>> matrixMultiplier
(
    std::vector<std::vector<int>>& a,
    std::vector<std::vector<int>>& b

)
{
    std::vector<std::vector<int>> resultVector;
    int temporary = 0;
    if (a[0].size() == b.size())
    {
        resultVector.resize(a.size(), std::vector<int>(b[0].size(), 0));
        for(size_t r = 0; r < a.size(); r++)
        {
            for(size_t c = 0; c < b[0].size(); c++)
            {
                for(size_t j = 0; j < a[0].size(); j++)
                {
                    temporary += a[r][j] * b[j][c];
                }
                resultVector[r][c] = temporary;
                temporary = 0;
            }
        }
    }
    return resultVector;
}
int main()
{
    std::vector<std::vector<int>> matrixA;
    std::vector<std::vector<int>> matrixB;
    std::vector<std::vector<int>> result;

    int rowsA;
    int columnsA;
    int rowsB;
    int columnsB;
    int option;

    do
    {
        std::cout << "\n===== MATRIX MULTIPLIER TEST MENU =====\n";
        std::cout << "1. Generate Matrix A\n";
        std::cout << "2. Fill Matrix A\n";
        std::cout << "3. Print Matrix A\n";
        std::cout << "4. Generate Matrix B\n";
        std::cout << "5. Fill Matrix B\n";
        std::cout << "6. Print Matrix B\n";
        std::cout << "7. Multiply A * B\n";
        std::cout << "8. Print result\n";
        std::cout << "9. Clear all matrices\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> option;
        std::cin.ignore();

        switch(option)
        {
            case 1:
                std::cout << "Rows for A: ";
                std::cin >> rowsA;
                std::cout << "Columns for A: ";
                std::cin >> columnsA;
                std::cin.ignore();

                matrix_Generator(rowsA, columnsA, matrixA);
                std::cout << "Matrix A generated.\n";
                break;

            case 2:
                if(matrixA.empty())
                {
                    std::cout << "Generate Matrix A first.\n";
                }
                else
                {
                    matrix_Filler(matrixA);
                    std::cout << "Matrix A filled.\n";
                }
                break;

            case 3:
                if(matrixA.empty())
                {
                    std::cout << "Matrix A is empty.\n";
                }
                else
                {
                    std::cout << "Matrix A:\n";
                    for(size_t i = 0; i < matrixA.size(); i++)
                    {
                        for(size_t j = 0; j < matrixA[i].size(); j++)
                        {
                            std::cout << matrixA[i][j] << " ";
                        }
                        std::cout << '\n';
                    }
                }
                break;

            case 4:
                std::cout << "Rows for B: ";
                std::cin >> rowsB;
                std::cout << "Columns for B: ";
                std::cin >> columnsB;
                std::cin.ignore();

                matrix_Generator(rowsB, columnsB, matrixB);
                std::cout << "Matrix B generated.\n";
                break;

            case 5:
                if(matrixB.empty())
                {
                    std::cout << "Generate Matrix B first.\n";
                }
                else
                {
                    matrix_Filler(matrixB);
                    std::cout << "Matrix B filled.\n";
                }
                break;

            case 6:
                if(matrixB.empty())
                {
                    std::cout << "Matrix B is empty.\n";
                }
                else
                {
                    std::cout << "Matrix B:\n";
                    for(size_t i = 0; i < matrixB.size(); i++)
                    {
                        for(size_t j = 0; j < matrixB[i].size(); j++)
                        {
                            std::cout << matrixB[i][j] << " ";
                        }
                        std::cout << '\n';
                    }
                }
                break;

            case 7:
                if(matrixA.empty() || matrixB.empty())
                {
                    std::cout << "Generate and fill both matrices first.\n";
                }
                else
                {
                    result = matrixMultiplier(matrixA, matrixB);
                    std::cout << "Multiplication attempted.\n";
                }
                break;

            case 8:
                if(result.empty())
                {
                    std::cout << "Result matrix is empty.\n";
                }
                else
                {
                    std::cout << "Result:\n";
                    for(size_t i = 0; i < result.size(); i++)
                    {
                        for(size_t j = 0; j < result[i].size(); j++)
                        {
                            std::cout << result[i][j] << " ";
                        }
                        std::cout << '\n';
                    }
                }
                break;

            case 9:
                matrixA.clear();
                matrixB.clear();
                result.clear();
                std::cout << "All matrices cleared.\n";
                break;

            case 0:
                std::cout << "Exiting.\n";
                break;

            default:
                std::cout << "Invalid option.\n";
                break;
        }

    } while(option != 0);

}


