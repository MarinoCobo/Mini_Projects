# C++ Mini Projects

Small, self-contained C++ programs exploring algorithms, mathematics and
systems programming. Each project lives in its own numbered folder.

| # | Project | What it does |
|---|---------|--------------|
| 001 | [Matrix multiplier](001_Matrix_multiplier/) | Reads two matrices from the console and multiplies them, using a `Matrix` class split into header and implementation. |
| 002 | [RSA encrypter/decrypter](002_RSA_Encrypter_Decrypter/) | Generates 9-digit primes, derives RSA keys with the extended Euclidean algorithm, and encrypts/decrypts a text message. |
| 003 | [Sudoku](003_Sudoku/) | Generates random Sudoku boards with a backtracking solver, removes cells by difficulty, and gives hints from the stored solution. |

## Building

Each project is a plain C++17 program:

```sh
cd 001_Matrix_multiplier
g++ -std=c++17 *.cpp -o matrix && ./matrix
```
