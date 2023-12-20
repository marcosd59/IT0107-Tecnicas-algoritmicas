/*********************************************************************
Fecha de creacion: 02/09/2022
Fecha de ultima actualizacion: 02/09/2022
Nombre del programador: Marcos Damian Pool Canul
Nombre del programa: MERGE_SORT
Descripcion: Ordenamiento por el metodo merge-sort.
Entradas: Arreglos de numeros enteros.
Salidas: Arreglo ordenado.
*********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

void PRINT(int A[], int n);
void MERGE(int A[], int p, int q, int r);
void MERGE_SORT(int A[], int p, int r);

int main()
{
    int n = 8;
    int A[n] = {3, 41, 52, 26, 38, 57, 9, 49};
    int p = 0;
    int r = 7;

    cout << "\t Arreglo desordenado";
    PRINT(A, n);
    MERGE_SORT(A, p, r);
    cout << "\t Arreglo ordenado";
    PRINT(A, n);

    return 0;
}

void PRINT(int A[], int n)
{
    cout << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "[" << A[i] << "] ";
    }
    cout << endl
         << endl;
}

void MERGE(int A[], int p, int q, int r)
{
    int nL = q - p + 1;
    int nR = r - q;

    int *L = new int[nL];
    int *R = new int[nR];

    for (int i = 0; i <= nL - 1; i++)
    {
        L[i] = A[p + i];
    }

    for (int j = 0; j <= nR - 1; j++)
    {
        R[j] = A[q + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i = i + 1;
        }
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i < nL)
    {
        A[k] = L[i];
        i = i + 1;
        k = k + 1;
    }

    while (j < nR)
    {
        A[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
}

void MERGE_SORT(int A[], int p, int r)
{
    if (p >= r)
    {
        return;
    }

    int q = floor((p + r) / 2);

    MERGE_SORT(A, p, q);
    MERGE_SORT(A, q + 1, r);
    MERGE(A, p, q, r);
}