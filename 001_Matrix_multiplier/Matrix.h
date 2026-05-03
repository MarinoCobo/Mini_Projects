#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

class Matrix
{
    private:
       std::vector<std::vector<int>>& matrix; 
    public:
        void resize(std::vector<std::vector<int>>& matrix);
        void fill(std::vector<std::vector<int>>& matrix);
        void clear(std::vector<std::vector<int>>& matrix);
        void fill(std::vector<std::vector<int>>& matrix);
        void print();
        void changeNumber();
};

#endif