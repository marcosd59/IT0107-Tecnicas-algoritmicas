/* Inclusion de librerias */
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>
using namespace std;

/* Portotipo de funcion */
int BestScore(char **sDNA, int l, int t, char *bestCha);
char *BruteForceMotifSearchAgain(char **DNA, int t, int n, int l);

/* Funcion principal */
int main()
{
    // t = El numero de filas.
    // n = El numero de columnas.
    // l = El numero de l-meros.

    // El maximo para 't' es 7, se ecuentra en el archivo data.txt

    /************************/
    int t = 3, n = 40, l = 2;
    /************************/

    char *motivo = new char[l]; // Motivo dinamico de tamaño de los l-meros.
    char **DNA = new char *[t]; // Matriz dinamica de ADN de tamaño 't'.
    clock_t inicio, final;      // Para calcular el tiempo de ejecucion.
    double duracion;            // Almacena la duracion del programa.

    /* Creamos un arreglo dinamico */
    for (int i = 0; i < t; i++)
    {
        DNA[i] = new char[n];
    }
    /*
    cout<<"Ingresa el valor para t: ";
    cin>>t;
    cout<<endl;
    cout << "Ingresa el valor de l: ";
    cin>>l;
    cout<<endl;*/

    cout << "t = " << t << ", l = " << l << endl << endl;

    ifstream datos("./data.txt"); // Leemos la cadena de ADN desde un archivo de texto.

    /* Rellenamos la matriz con los datos */
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            datos >> DNA[i][j];
            cout << DNA[i][j];
        }
        cout << endl;
    }

    datos.close(); // Terminamos de leer el archivo.

    inicio = clock(); // Inicio del reloj.
    motivo = BruteForceMotifSearchAgain(DNA, t, n, l);
    final = clock(); // Final del reloj.

    // Calculamos la duracion.
    duracion = (double)(final - inicio) / CLOCKS_PER_SEC;

    cout << endl;
    cout << "El tiempo para BruteForceMotifSearchAgain es " << duracion << endl;

    /* Imprimimos el motivo */
    cout << endl;
    cout << "el motivo es ";
    cout << "'";

    for (int i = 0; i < l; i++)
    {
        cout << motivo[i];
    }

    cout << "'" << endl << endl;

    return 0;
}

/* Calcula la mejor puntuación para cada hoja. */
int BestScore(char **sDNA, int l, int t, char *bestCha)
{
    int sA, sC, sG, sT, Tbest = 0; // Variables para cada letra.
    int best = 0;

    for (int i = 0; i < l; i++)
    {
        sA = 0;
        sC = 0;
        sG = 0;
        sT = 0;
        for (int j = 0; j < t; j++)
        {
            if (sDNA[j][i] == 'a')
            {
                sA++;
            }
            else if (sDNA[j][i] == 'c')
            {

                sC++;
            }
            else if (sDNA[j][i] == 'g')
            {
                sG++;
            }
            else if (sDNA[j][i] == 't')
            {

                sT++;
            }
        }

        if (sA > best)
        {
            best = sA;
            bestCha[i] = 'a';
        }
        if (sC > best)
        {
            best = sC;
            bestCha[i] = 'c';
        }
        if (sG > best)
        {
            best = sG;
            bestCha[i] = 'g';
        }
        if (sT > best)
        {
            best = sT;
            bestCha[i] = 't';
        }

        Tbest = Tbest + best;
        best = 0;
    }

    return Tbest; // Devuelve el merjor score.
}

/* Funcion para encontrar el motivo. */
char *BruteForceMotifSearchAgain(char **DNA, int t, int n, int l)
{
    int *a = new int[n - l + 1];
    char **sDNA = new char *[t];
    char *bestCha = new char[l];
    char *motivo = new char[l];
    int k = 0, Tbest = 0, bScore = 0, bandera = 0;

    for (int i = 0; i < n - l + 1; i++)
    {
        a[i] = 0;
    }

    for (int i = 0; i < t; i++)
    {
        sDNA[i] = new char[l];
    }

    while (1) // While forever.
    {

        for (int i = 0; i < t; i++)
        {
            k = a[i];
            for (int j = 0; j < l; j++)
            {
                sDNA[i][j] = DNA[i][k + j];
            }
        }

        for (int i = t - 1; i >= 0; i--) // Calculamos la siguiente hoja.
        {
            if (a[i] == (n - l))
            {
                a[i] = 0;
                if (i == 0)
                {
                    bandera = 1;
                }
            }
            else
            {
                a[i]++;
                break;
            }
        }

        Tbest = BestScore(sDNA, l, t, bestCha);

        if (Tbest > bScore) // Encuentra la hoja con la mejor puntuación.
        {
            bScore = Tbest;
            for (int i = 0; i < l; i++)
            {
                motivo[i] = bestCha[i];
            }
        }
        if (bandera == 1) // Bnadera para romper el bucle.
        {
            break;
        }
    }

    return motivo; // Devuelve el mejor motivo.
}