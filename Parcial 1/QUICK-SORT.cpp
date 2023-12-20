/*********************************************************************
Fecha de creacion: 28/09/2022
Fecha de ultima actualizacion: 28/09/2022
Nombre del programador: Marcos Damian Pool Canul
Nombre del programa: QuickSort
Descripcion: Ordenamiento por el metodo QuickSort.
Entradas: Arreglos de numeros enteros.
Salidas: Arreglo ordenado.
*********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

void PRINT(int A[], int n);
void SWAP(int A[], int pos1, int pos2);
void QUICKSORT(int A[], int p, int r);
int PARTITION(int A[], int p, int r);

int main()
{
    int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);
    int p = 0;
    int r = 9;

    cout << "\t Arreglo desordenado";
    PRINT(A, n);
    QUICKSORT(A, p, r);
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

void SWAP(int A[], int pos1, int pos2)
{
    int aux;
    aux = A[pos1];
    A[pos1] = A[pos2];
    A[pos2] = aux;
}

void QUICKSORT(int A[], int p, int r)
{
    int q;

    if (p < r)
    {
        q = PARTITION(A, p, r);
        QUICKSORT(A, p, q - 1);
        QUICKSORT(A, q + 1, r);
    }
}

int PARTITION(int A[], int p, int r)
{
    int x, i, j, aux;

    x = A[r];
    i = p - 1;
    for (j = p; j <= r - 1; j++)
    {
        if (A[j] <= x)
        {
            i = i + 1;
            SWAP(A, j, i);
        }
    }
    SWAP(A, i + 1, r);
    return i + 1;
}
