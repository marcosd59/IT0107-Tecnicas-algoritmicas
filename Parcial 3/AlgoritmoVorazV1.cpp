#include <iostream>
using namespace std;

/* Variables Globales */

// char ADN1[7] = {'G', 'A', 'T', 'T', 'C', 'C', 'A'};
// char ADN2[7] = {'T', 'T', 'G', 'A', 'T', 'T', 'A'};

char ADN1[12] = {'A', 'G', 'C', 'T', 'C', 'A', 'C', 'A', 'G', 'G', 'C', 'A'};
char ADN2[12] = {'G', 'C', 'T', 'G', 'G', 'C', 'C', 'A', 'G', 'G', 'C', 'A'};

int t = 1;                              // El número de filas.
int l = 4;                              // El número de l-meros.
int n = sizeof(ADN1) / sizeof(ADN1[0]); // El tamaño de la cadena.

/* Funcion para calcular el mejor score de 2 secuencias de ADN */
int score(char *ADN1, char *ADN2)
{
    int score = 0; // Variable para almacenar el score.
    for (int i = 0; i < n; i++)
    {
        if (ADN1[i] == ADN2[i]) // Comparamos si tiene en mismo elementos.
        {
            score += 1; // Sumamos 1 punto al score.
        }
    }
    return score;
}

/* Funcion de Branch para obtener el score */
void Branch(char *ADN, int n, int l)
{
    char CADENA[12]; // Creamos una cadena para almacenar las combinaciones.

    for (int i = 0; i < n - l + 1; i++)
    {
        for (int j = 0; j < l; j++)
        {
            int pos = i + j;
            if (pos <= n)
            {
                CADENA[j] = ADN[pos];
                cout << CADENA[j]; // Imprimimos la cadena.
            }
        }
        cout << " Score: " << score(CADENA, ADN2) + l << endl; // Obtenemos el score.
    }
}

int main()
{
    Branch(ADN1, n, l);
    return 0;
}