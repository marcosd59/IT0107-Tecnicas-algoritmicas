/*********************************************************************
Fecha de creacion: 28/09/2022
Fecha de ultima actualizacion: 28/09/2022
Nombre del programador: Marcos Damian Pool Canul
Nombre del programa: QuickSort
Descripcion: Ordenamiento por el metodo SelectionSort.
Entradas: Arreglos de numeros enteros.
Salidas: Arreglo ordenado.
*********************************************************************/

#include <stdio.h>
#include <iostream>

using namespace std;

void PRINT(int A[], int n);
void SWAP(int A[], int pos1, int pos2);
void SELECTIONSORT(int A[], int n);

int main()
{
    int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "\t Arreglo desordenado";
    PRINT(A, n);
    SELECTIONSORT(A, n);
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

void SELECTIONSORT(int A[], int n)
{
    int min, aux;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        SWAP(A, i, min);
    }
}