#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;

//Variable global matriz 9x9 sudoku
vector<vector<int>> tablero(9, vector<int>(9, 0));

//Vector global con la solución
vector<vector<int>> solucion(9, vector<int>(9, 0));

//Prototipo generar nuevo sudoku
void generar(vector<vector<int>>& nuevo);

//Prototipo de la función Imprimir Tablero
void printBoard(vector<vector<int>> imprimir);

//Prototipo de la función menú
void menuSudoku();

//Prototipo de la función filaValida
bool filaValida(vector<vector<int>>& tablero, int fila, int numero_a_comprobar);

//Prototipo de la función columnaValida
bool columnaValida(vector<vector<int>>& tablero, int columna, int numero_a_comprobar);

//Prototipo subcuadrado válido
bool subcuadradoValido(vector<vector<int>>& tablero, int fila, int columna, int numero_a_comprobar);

//Prototipo esValido
bool esValido(vector<vector<int>>& tablero, int fila, int columna, int numero);

//Prototipo función encontrarVacio
bool encontrarVacio(vector<vector<int>>& tablero, int &fila, int &columna);

//Prototipo solver
bool solver(vector<vector<int>>& tablero);

//Copia el tablero prototipo
void copiar_el_vector(vector<vector<int>>& tablero, vector<vector<int>>& solucion);

//Prototipo de vaciar el sudoku
void vaciar_el_sudoku(vector<vector<int>>& solucion);

//Prototipo de la pista
void pista(vector<vector<int>>& tablero);

//Prototipo leer un entero de forma segura
int leerEntero();

/****************************************************
 *                                                  *
 *                    FUNCIÓN MAIN                  *
 *                                                  *
 *   Punto de entrada principal del programa.      *
 *   Desde aquí se ejecuta el menú y se controla   *
 *   todo el flujo general del sistema de Sudoku.  *
 *                                                  *
 ****************************************************/
int main()
{
    srand(time(0));
    menuSudoku();
}

//Definición de la función menu
void menuSudoku()
{
    int menu {0};

    //Se repite hasta que el usuario elija Salir (antes el menú se llamaba a sí mismo)
    while (menu != 5)
    {
        cout << "\n==============================\n";
        cout << "        MENU SUDOKU           \n";
        cout << "==============================\n";
        cout << "1. Generar nuevo Sudoku\n";
        cout << "2. Ver Sudoku Resuelto\n";
        cout << "3. Dar una Pista\n";
        cout << "4. Mostrar Sudoku Actual\n";
        cout << "5. Salir\n";
        cout << "==============================\n";
        cout << "Seleccione una opcion: ";
        menu = leerEntero();

        switch (menu)
        {
            case 1:
                generar(tablero);
                break;
            case 2:
                printBoard(solucion);
                break;
            case 3:
                pista(tablero);
                printBoard(tablero);
                break;
            case 4:
                printBoard(tablero);
                break;
            case 5:
                break;
            default:
                cout << "\nSeleccione una opción válida\n";
        }
    }
}

//Lee un entero; si el usuario escribe letras, limpia la entrada y devuelve -1
int leerEntero()
{
    int numero {};
    if (!(cin >> numero))
    {
        if (cin.eof())
        {
            exit(0);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return numero;
}

//Definición de la función imprimir tablero
void printBoard(vector<vector<int>> imprimir)
{
    cout << endl << "   A B C   D E F   G H I" << endl << endl;
    for(int i = 0; i < imprimir.size(); i++)
    {
        cout << i+1 << "  ";
        for(int j = 0; j < imprimir[i].size(); j++)
        {
            cout << imprimir[i][j] << " ";
            if (j+1 == 3 or j+1 == 6)
            {
                cout << "| ";
            }
        }
        if ((i+1)%3 == 0)
        {
            cout << "\n";
        }
        cout << endl;
    }
}


bool filaValida(vector<vector<int>>& tablero, int fila, int numero_a_comprobar)
{
    for(int i = 0; i < tablero[fila].size(); i++)
    {
        if(tablero[fila][i] == numero_a_comprobar)
        {
            return false;
        }
    }
    return true;
}

bool columnaValida(vector<vector<int>>& tablero, int columna, int numero_a_comprobar)
{
    for(int i = 0; i < tablero.size(); i++)
    {
        if(tablero[i][columna] == numero_a_comprobar)
        {
            return false;
        }
    }
    return true;
}

bool subcuadradoValido(vector<vector<int>>& tablero, int fila, int columna, int numero_a_comprobar)
{
    int inicioFila    = (fila / 3) * 3;     // 0, 3 o 6
    int inicioColumna = (columna / 3) * 3;  // 0, 3 o 6

    for (int i = inicioFila; i < inicioFila + 3; i++)
    {
        for (int j = inicioColumna; j < inicioColumna + 3; j++)
        {
            if (tablero[i][j] == numero_a_comprobar)
            {
                return false;
            }
        }
    }

    return true;
}

bool esValido(vector<vector<int>>& tablero, int fila, int columna, int numero)
{
    return filaValida(tablero, fila, numero) && 
    columnaValida(tablero, columna, numero) &&
    subcuadradoValido(tablero, fila, columna, numero);
}

bool encontrarVacio(vector<vector<int>>& tablero, int &fila, int &columna)
{
    for (fila = 0; fila < 9; fila++)
    {
        for (columna = 0; columna < 9; columna++)
        {
            if(tablero[fila][columna] == 0)
            return true;
        }
    }
    return false;
}

bool solver(vector<vector<int>>& tablero)
{
    int numeros[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i = 8; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
    }
    int fila {};
    int columna {};

    if (!encontrarVacio(tablero, fila, columna))
    {
        return true;
    }
    if(encontrarVacio(tablero, fila, columna))
    {
        for(int i = 0; i <= 8; i++)
        {
            if(esValido(tablero, fila, columna, numeros[i]))
            {
                tablero[fila][columna] = numeros[i] ;
                if (solver(tablero))
                {
                    return true;
                }
                tablero[fila][columna] = 0;
            }
        }
        
    }
    return false;
}

void generar(vector<vector<int>>& nuevo_sudoku)
{
    vaciar_el_sudoku(solucion);
    solver(solucion);
    copiar_el_vector(solucion, tablero);
    int dificultad{};
    int columna_aleatoria {};
    int fila_aleatoria {};
    cout << "\nEscoja una opción\n1. Fácil\n2. Medio\n3. Difícil\n4. Muy Difícil\n";
    dificultad = leerEntero();

    //Se vuelve a preguntar: con una opción inválida el número se usaba tal cual
    //y un valor mayor a 81 dejaba el programa en un bucle infinito
    while (dificultad < 1 || dificultad > 4)
    {
        cout << "Opción incorrecta, escoja entre 1 y 4: ";
        dificultad = leerEntero();
    }

    switch (dificultad)
    {
        case 1:
        dificultad = 20;
        break;
        case 2:
        dificultad = 26;
        break;
        case 3:
        dificultad = 32;
        break;
        case 4:
        dificultad = 40;
        break;
    }
    for (int k{0}; k<= dificultad;)
    {
        columna_aleatoria = rand()%9;
        fila_aleatoria = rand()%9;

        if(nuevo_sudoku[fila_aleatoria][columna_aleatoria] != 0)
        {
            nuevo_sudoku[fila_aleatoria][columna_aleatoria] = 0;
            k++;
        }
    }
    printBoard(tablero);
}

void copiar_el_vector(vector<vector<int>>& tablero, vector<vector<int>>& solucion)
{
    for (int i {0}; i < tablero.size(); i++)
    {
        for (int j{0}; j<tablero[i].size(); j++)
        {
            solucion[i][j] = tablero[i][j];
    
        }
    }
}

void vaciar_el_sudoku(vector<vector<int>>& solucion)
{
    for (int i {0}; i < solucion.size(); i++)
    {
        for (int j{0}; j<solucion[i].size(); j++)
        {
            solucion[i][j] = 0;
    
        }
    } 
}

void pista(vector<vector<int>>& tablero)
{
    bool comprobador = false;
    for(int i = 0; i<tablero.size(); i++)
    {
        for(int j = 0; j<tablero[i].size(); j++)
        {
            if(tablero[i][j] == 0)
            {
                tablero[i][j] = solucion[i][j];
                comprobador = true;
                break;
            }
            
        }
        if (comprobador)
        {
            break;
        }
    }
}    
