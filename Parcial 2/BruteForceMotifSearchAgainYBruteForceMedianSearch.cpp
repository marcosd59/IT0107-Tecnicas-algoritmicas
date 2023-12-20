/* Inclusion de librerias */
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>
using namespace std;
#define INFINITO 2147483647
#define MAX 19

/* Portotipo de funcion */
int BestScore(char **sDNA, int l, int t, char *bestCha);
char *BruteForceMotifSearchAgain(char **DNA, int t, int n, int l);
int TotalDistance(char *s, char **DNA, int t, int n, int l);
char *BruteForceMedianSearch(char **DNA, int t, int n, int l);

/* Funcion principal */
int main()
{
    // t = El numero de filas.
    // n = El numero de columnas.
    // l = El numero de l-meros.

    // El maximo para 't' es 7, se ecuentra en el archivo data.txt

    /************************/
    int t = 4, n = 40, l = 10;
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

    cout <<"BruteForceMotifSearchAgain"<< endl << endl;

    /*cout<<"Ingresa el valor para t: ";
    cin>>t;
    cout << "Ingresa el valor de l: ";
    cin>>l;
    cout<<endl;*/

    cout << "t = " << t << ", l = " << l << endl << endl;

    ifstream datos("./datos.txt"); // Leemos la cadena de ADN desde un archivo de texto.

    /* Rellenamos la matriz con los datos */

    cout << "Secuencia de ADN de: " << t << " x " << n << endl << endl;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            datos >> DNA[i][j];
            cout << DNA[i][j];
        }
        cout << endl;
    }

    cout << endl;

    datos.close(); // Terminamos de leer el archivo.

    inicio = clock(); // Inicio del reloj.
    motivo = BruteForceMotifSearchAgain(DNA, t, n, l);
    final = clock(); // Final del reloj.

    // Calculamos la duracion.
    duracion = (double)(final - inicio) / CLOCKS_PER_SEC;

    cout << endl << "El tiempo para BruteForceMotifSearchAgain es " << duracion << endl;

    /* Imprimimos el motivo */
    cout << endl;
    cout << "el motivo es ";
    cout << "'";

    for (int i = 0; i < l; i++)
    {
        cout << motivo[i];
    }

    cout << "'" << endl << endl;
    cout << "-------------------------------------------------------" << endl << endl;
    cout <<"BruteForceMedianSearch"<< endl << endl;

    cout << "t = " << t << ", l = " << l << endl << endl;

    /* Rellenamos la matriz con los datos */

    cout << "Secuencia de ADN de: " << t << " x " << n << endl << endl;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << DNA[i][j];
        }
        cout << endl;
    }

    cout << endl;

    inicio = clock(); // Inicio del reloj.
    motivo = BruteForceMedianSearch(DNA, t, n, l);
    final = clock(); // Final del reloj.

    // Calculamos la duracion.
    duracion = (double)(final - inicio) / CLOCKS_PER_SEC;

    cout << endl;
    cout << "El tiempo para BruteForceMedianSearch es " << duracion << endl;

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
    int best = 0, score = 0;

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
                cout << bestCha[i];
                cout << " - Score: "<< bScore;
                cout << endl;
            }
        }
        if (bandera == 1) // Bandera para romper el bucle.
        {
            break;
        }
    }

    return motivo; // Devuelve el mejor motivo.
}

/* Funcion para hayar la distancia total */
int TotalDistance(char *s, char **DNA, int t, int n, int l)
{
    char *v = new char[l];
    int Distance, MinDistance = INFINITO, SumDistance = 0;

    for (int i = 0; i < t; i++)
    {
        MinDistance = INFINITO;
        for (int j = 0; j < (n - l + 1); j++)
        {
            Distance = 0;
            for (int k = 0; k < l; k++)
            {
                v[k] = DNA[i][j + k];

                if (v[k] != s[k])
                {
                    Distance++;
                }
            }

            if (Distance < MinDistance)
            {
                MinDistance = Distance;
            }
        }

        SumDistance = SumDistance + MinDistance;
    }

    return SumDistance;
}

/* Funcion para encontrar la mediana */
char *BruteForceMedianSearch(char **DNA, int t, int n, int l)
{
    int *a = new int[l];
    char *s = new char[l];
    char *mutif = new char[l];
    int endflag = 0, totaldistance = 0, BestDistance = INFINITO;

    for (int i = 0; i < l; i++)
    {
        a[i] = 0;
    }

    while (1)
    {
        for (int i = 0; i < l; i++)
        {
            if (a[i] == 0)
            {
                s[i] = 'a';
            }
            else if (a[i] == 1)
            {
                s[i] = 'c';
            }
            else if (a[i] == 2)
            {
                s[i] = 'g';
            }
            else if (a[i] == 3)
            {
                s[i] = 't';
            }
        }

        totaldistance = TotalDistance(s, DNA, t, n, l);
        if (totaldistance < BestDistance)
        {
            BestDistance = totaldistance;
            for (int i = 0; i < l; i++)
            {
                mutif[i] = s[i];
                cout << mutif[i];
            }
            cout << " - Distancia de Hamming: ";
            cout << BestDistance;
            cout << endl;
        }

        for (int i = (l - 1); i >= 0; i--) // Calcula la siguiente hoja.
        {
            if (a[i] == 3)
            {
                a[i] = 0;
                if (i == 0)
                {
                    endflag = 1;
                }
            }
            else
            {
                a[i]++;
                break;
            }
        }

        if (endflag == 1)
        {
            break;
        }
    }

    return mutif; // retorna el mejor motivo.
}