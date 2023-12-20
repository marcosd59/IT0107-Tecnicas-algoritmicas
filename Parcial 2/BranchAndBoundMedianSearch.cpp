/* Inclucion de librerias */
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;
#define INFINITO 2147483647

/*Prototipo de funcion */
int DistanciaTotal(char *s, char **DNA, int t, int n, int si);
char *BranchAndBoundMedianSearch(char **DNA, int t, int n, int l);

/* Funcion principal */
int main()
{
    // t = El numero de filas.
    // n = El numero de columnas.
    // l = El numero de l-meros.

    // El maximo para 't' es 7, se ecuentra en el archivo data.txt

    /************************/
    int t = 5, n = 40, l = 7;
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

    cout << "t = " << t << ", l = " << l << endl
         << endl;

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
    motivo = BranchAndBoundMedianSearch(DNA, t, n, l);
    final = clock(); // Final del reloj.

    duracion = (double)(final - inicio) / CLOCKS_PER_SEC; // Calculamos la duracion.

    cout << endl;
    cout << "El tiempo para BranchAndBoundMedianSearch es " << duracion << endl;

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
/* Funcion para calcular la distancia total */
int DistanciaTotal(char *s, char **DNA, int t, int n, int si)
{
    char *v = new char[si + 1];
    int Distancia, DistanciaMinima = INFINITO, SumDistancias = 0;

    for (int i = 0; i < t; i++)
    {
        DistanciaMinima = INFINITO;
        for (int j = 0; j < (n - si); j++)
        {
            Distancia = 0;
            for (int k = 0; k < (si + 1); k++)
            {
                v[k] = DNA[i][j + k];

                if (v[k] != s[k])
                {
                    Distancia++;
                }
            }

            if (Distancia < DistanciaMinima)
            {
                DistanciaMinima = Distancia;
            }
        }
        SumDistancias = SumDistancias + DistanciaMinima;
    }
    return SumDistancias;
}

/* Aqui comienza el BranchAndBoundMedianSearch */
char *BranchAndBoundMedianSearch(char **DNA, int t, int n, int l)
{
    int *a = new int[l];
    char *s = new char[l];
    char *motivo = new char[l];
    int badera = 0, DistanciaOptimisma = 0, si = 0;
    int MejorDistancia = INFINITO; // A la mejor distancia se le asigna a INFINITO

    /* Rellenamos el arreglo con 0 */
    for (int i = 0; i < l; i++)
    {
        a[i] = 0;
    }

    while (1) // While forever
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
        /* A la distancia optimista se le asigna la distancia total */
        DistanciaOptimisma = DistanciaTotal(s, DNA, t, n, si);

        if (si != (l - 1))
        {
            if (DistanciaOptimisma > MejorDistancia)
            {
                for (int i = si; i >= 0; i--) // calcula la siguente hoja
                {
                    if (a[i] == 3)
                    {

                        a[i] = 0;
                        if (i == 0)
                        {
                            badera = 1;
                        }
                    }
                    else
                    {
                        a[i]++;
                        break;
                    }
                }
                for (int j = si + 1; j < l; j++)
                {
                    a[j] = 0;
                }
            }
            else
            {
                si++;
                a[si] = 0;
            }
        }
        else
        {
            if (DistanciaOptimisma < MejorDistancia)
            {
                MejorDistancia = DistanciaOptimisma;
                for (int i = 0; i < l; i++)
                {
                    motivo[i] = s[i];
                }
            }

            for (int i = (l - 1); i >= 0; i--) // calcula la siguiente hoja
            {
                if (a[i] == 3)
                {
                    si--;
                    if (i == 0)
                    {
                        badera = 1;
                    }
                }
                else
                {
                    a[i]++;
                    break;
                }
            }
        }
        if (badera == 1) // si pasa por todas las hojas se rompe el ciclo.
        {
            break;
        }
    }
    return motivo; // retorna el mejor motivo.
}