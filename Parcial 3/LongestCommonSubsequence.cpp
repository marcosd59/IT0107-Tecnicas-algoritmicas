/********************************************************************
Fecha de creacion: 20/11/2022
Fecha de ultima actualizacion: 30/11/2022
Nombre del programador: Marcos Damian Pool Canul
Nombre del programa: Subsecuencia común más larga
Descripcion: Encuentra la subsecuencia más larga común a dos cadenas.
Entradas: Dos cadenas, v y w.
Salidas: La subsecuencia común más larga de v y w.
********************************************************************/

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

/* Variables globales para que puedan ser accesible a través de todas las funciones */
const int MAX_SIZE = 20;
int longitudes[MAX_SIZE][MAX_SIZE];
char direcciones[MAX_SIZE][MAX_SIZE];

/* Prototipos de  las funciones */
void LCS(int v, int w);
void PrintLCS(string secuencia, int i, int j);

/* Programa principal */
int main()
{
    // string secUno = "";
    // string secDos = "";

    string secUno = "AGATTAC";
    string secDos = "CGCTTAACA";

    cout << "v = " << secUno << endl;
    cout << "w = " << secDos << endl;

    // cout << "Ingrese la primera subsecuencia de longitud 20 o menos: ";
    // cin >> secUno;
    // cout << "Ingrese la segunda subsecuencia de longitud 20 o menos: ";
    // cin >> secDos;

    int LongitudUno = secUno.length();
    int LongitudDos = secDos.length();

    if (LongitudUno > MAX_SIZE || secDos.length() > MAX_SIZE)
    {
        cout << "Ha introducido una subsecuencia de longitud superior a 20. El programa ahora se cerrará.";
        exit(EXIT_FAILURE);
    }

    // Crear valores límite que sean iguales a 0.
    for (size_t i = 1; i <= LongitudUno; i++)
    {
        longitudes[i][0] = 0;
    }
    for (size_t i = 1; i <= LongitudDos; i++)
    {
        longitudes[0][i] = 0;
    }

    // Rellenado de ambas tablas con longitudes/direcciones.
    for (size_t i = 1; i <= LongitudUno; i++)
    {
        for (size_t j = 1; j <= LongitudDos; j++)
        {
            if (secUno.at(i - 1) == secDos.at(j - 1))
            {
                longitudes[i][j] = longitudes[i - 1][j - 1] + 1;
                direcciones[i][j] = 'd';
            }
            else if (longitudes[i - 1][j] >= longitudes[i][j - 1])
            {
                longitudes[i][j] = longitudes[i - 1][j];
                direcciones[i][j] = 'a';
            }
            else
            {
                longitudes[i][j] = longitudes[i][j - 1];
                direcciones[i][j] = 'i';
            }
        }
    }

    LCS(LongitudUno, LongitudDos);
    cout << endl << "La subsecuencia es: ";
    PrintLCS(secUno, LongitudUno, LongitudDos);
}

/* Encuentra la longitud más larga */
void LCS(int v, int w)
{
    int MasLargo = 0;

    for (int x = 0; x <= v; x++)
    {
        for (int y = 0; y <= w; y++)
        {
            cout << left << setw(2) << setfill(' ') << longitudes[x][y];
            MasLargo = max(MasLargo, longitudes[x][y]);
        }
        cout << endl;
    }
    cout << "La longitud de la subsecuencia mas larga es " << MasLargo;
}

/* Imprime las cadenas */
void PrintLCS(string secuencia, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }

    if (direcciones[i][j] == 'd')
    {
        PrintLCS(secuencia, i - 1, j - 1);
        cout << secuencia.at(i - 1);
    }

    else if (direcciones[i][j] == 'a')
    {
        PrintLCS(secuencia, i - 1, j);
    }

    else
    {
        PrintLCS(secuencia, i, j - 1);
    }
}