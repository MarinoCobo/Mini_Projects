#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <sstream>

using namespace std;

//************************************************ PROTOTIPOS DE FUNCIONES *************************************************** */

//Prototipo_generador_de_primos_de_9_dígitos
long long generadorDePrimos();

//Prototipo comprobadorDePrimos
bool comprobadorDePrimos(long long num);

//Prototipo para generar el número s en as + bt = g (devuelve g)
long long sGenerator(long long a, long long b, long long &s, long long &t);

//Prototipo nGenerator
long long nGenerator(long long phi);


class GenradorDeEncriptado
{
    //************************************************ PRIVATE *************************************************** */
    private:
    
    //Función local que recibe un número encriptado  y lo almacena en un Vector
    void encriptedStorage(long long key)
    {
        encriptedMessage.push_back(key);
    }

    //Función local que recibe un número decriptado (como char) y lo almacena en un Vector
    void decriptedStorage(char message)
    {
        decriptedMessage.push_back(message);
    }


    //Función que hace el proceso de exponete y módulo para encriptar o decriptar los mensajes
    long long exponenciacionModular(long long base, long long exponente, long long modulo)
    {
        long long resultado = 1;
        long long baseActual = base % modulo;
         

        while (exponente > 0)
        {
            if (exponente % 2 == 1)
                resultado = (long long)((__int128)resultado * baseActual % modulo);

            baseActual = (long long)((__int128)baseActual * baseActual % modulo);
            exponente /= 2;
        }

        return resultado;
    }

    

    //************************ PUBLIC *************************** */

    public:
        
    //************************************************ Declaración de Variables *************************************************** */
    //Números primos aleatorios de 9 dígitos 
    long long p = generadorDePrimos();
    long long q = generadorDePrimos();
    
    //Número para la encriptación y decriptación de mensajes
    long long s;
    long long z = p*q;
    long long phi = (p-1)*(q-1);
    long long n = 65537;

        //Número tal que ap + bq = mcd
    long long t; 

    //Máximo común divisor de n y phi (1)
    long long g = sGenerator(n, phi, s, t);

    //************************************************ Declaración de Vectores *************************************************** */
    vector<char> decriptedMessage;
    vector<long long> encriptedMessage;


    //************************************************ Declaración de Variables Públicas *************************************************** */
    void generadorDeVariables(long long& pe, long long& qu, long long& zeta, long long& fi, long long& ge)
    {
        pe = generadorDePrimos();
        qu = generadorDePrimos();
        zeta = p*q;
        fi = (p-1)*(q-1);
        ge = sGenerator(n, phi, s, t);
    }
    

    
 
    void imprimirVariables()
    {
    //Imprime la verificación de que n*s mod phi = 1
    long long resultado = (long long)((__int128)n * s % phi);
    resultado = (resultado + phi) % phi;
    cout << "Claves públicas:\n";
    cout << "z: " << z << endl;
    cout << "n: " << n << endl;
    }

    /*Función local que encripta un char que se le alimente, llama a la función exponenciacionModular 
    con los valores char del string para encriptar el mensaje*/
    void messageEncripter(string texto, long long ene, long long zeta)
    {
        for (char miChar : texto)
        {
            long long c = exponenciacionModular(miChar, ene, zeta);
            encriptedStorage(c);
        }
    }

    /*Función que recibe como parámetros un vector con el mensaje encriptado y el valor s para la decodificación
    llama a la función exponenciacionModular con los valores almacenados en el vector para encriptar el mensaje*/
    void messageDecripter(vector<long long> vectorConMensajeEncriptado, long long ese)
    {
        for (int i = 0; i < vectorConMensajeEncriptado.size(); i++)
        {
            char c = exponenciacionModular(vectorConMensajeEncriptado[i], ese, z);
            decriptedStorage(c);
        }
    }

    //Función que imprime los códigos almacenados en el vector encriptedMessage
    void encriptedPrinter()
    { 
        for(int i = 0; i<encriptedMessage.size(); i++)
        {
            cout << encriptedMessage[i] << " ";
        }
        encriptedMessage.clear();
    }

    //Funcion que imprime el mensaje decriptado almacenado en el vector decriptedMessage
    void decriptedPrinter()
    {
        for(int i = 0; i<decriptedMessage.size(); i++)
        {
            cout << decriptedMessage[i];
        }
    }

    /* Función que recibe un string (de números) y lo lee para convertir cada número individual en
    long long y almacenarlos en un vector para su próxima decodificación. */
    vector<long long> recibeCodificado(const string& codigo )
    {
        vector<long long> numeros;
        stringstream ss(codigo);
        long long valor;

        while(ss >> valor)
        {
            numeros.push_back(valor);
        }
        return numeros;
    }

    /*Función que imprime el valor s (necesario para la decodificación del mensaje)*/
    void sPrinter()
    {
        cout << (s % phi + phi) % phi;
    }
   

};

int main()
{
    srand(time(0));     
    GenradorDeEncriptado encriptado;
    string contrasenia;
    cout << "Ingrese una contraseña maestra: ";
    getline(cin, contrasenia);
    int opcion;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Generar código secreto\n";
        cout << "2. Imprimir valores código\n";
        cout << "3. Codificar mensaje\n";
        cout << "4. Decodificar mensaje\n";
        cout << "5. Imprimir contraseña secreta (s)\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                // generarCodigo();
                cout << "Generando código para encriptación\n";
                encriptado.generadorDeVariables(encriptado.p, encriptado.q, encriptado.z, encriptado.phi, encriptado.g);
                encriptado.imprimirVariables();
                break;

            case 2:
                // imprimirValores();
                cout << "Imprimiendo valores...\n";
                encriptado.imprimirVariables();
                break;

            case 3:
            {
                // codificarMensaje();
                cout << "Escriba el mensaje que quiere encriptar y presione 'Enter':\n";
                string mensaje;
                cin.ignore();
                getline(cin, mensaje);
                long long ene;
                long long zeta;
                cout << "Ingrese el valor n para encriptar: ";
                cin >> ene;
                cout << "Ingrese el valor z para encriptar: ";
                cin >> zeta;
                encriptado.messageEncripter(mensaje, ene, zeta);
                cout << "Codificando mensaje...\n";
                cout << "Mensaje codificado exitosamente!\n";
                cout << "Mensaje codificado:\n\n";
                encriptado.encriptedPrinter();
                break;
            }
                

            case 4:
            {
                // decodificarMensaje();
                cout << "Ingrese el mensaje a decodificar: \n";
                string mensaje_codificado;
                cin.ignore();
                getline(cin, mensaje_codificado);

                cout << "Escriba la clave para decriptar: ";
                long long contraseniaParaDecriptar;
                cin >> contraseniaParaDecriptar;

                encriptado.messageDecripter(encriptado.recibeCodificado(mensaje_codificado), contraseniaParaDecriptar);
                cout << "Decodificando mensaje...\n";
                encriptado.decriptedPrinter();
                break;
            }

            case 5:
            {
                cout << "Ingrese la contraseña: ";
                string contrasenia_ingresada;
                cin >> contrasenia_ingresada;
                cout << "La clave secreta (s) es:\n";
                cin.ignore(1000, '\n');
                if (contrasenia_ingresada == contrasenia)
                {
                    encriptado.sPrinter();
                }
                else
                {
                    long long temporal = generadorDePrimos();
                    cout << temporal;
                }
                break;
            }

            case 0:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opción inválida.\n";
        }

    } while (opcion != 0);

    return 0;
    
}

//Funcion_generador_de_primos
long long generadorDePrimos()
{
    //Genera un número random entre 
    long long numero = (rand() % 899999999) + 100000000;
    if (comprobadorDePrimos(numero) == false)
    {
        numero = generadorDePrimos();
    }
    return numero;
}

long long sGenerator(long long a, long long b, long long &s, long long &t)
{
    if (b==0)
    {
        s = 1;
        t = 0;
        return a;
    }
    
    long long prime_s;
    long long prime_t;
    long long q = a/b;
    long long r = a % b;
    long long g = sGenerator(b, r, prime_s, prime_t);
    s = prime_t;
    t = prime_s - prime_t*q;
    return g;
}

long long nGenerator(long long phi)
{
    long long n = generadorDePrimos();
    
    while (phi % n == 0)
    {
        n = generadorDePrimos();
    }
    return n;
}

bool comprobadorDePrimos (long long num)
{
    for (long long i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    } 
    return true;
}

