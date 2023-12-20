/*********************************************************************
Fecha de creacion: 18/08/2022
Fecha de ultima actualizacion: 19/08/2022
Nombre del programador: Marcos Damian Pool Canul
Nombre del programa: INSERTION-SORT
Descripcion: Ordenamiento por el metodo isertion-sort.
Entradas: Arreglo de numeros enteros.
Salidas: Arreglo ordenado de menor a mayor.
*********************************************************************/

#include <stdio.h>

void INSERTIONSORT(int A[], int n);
void PRINT(int A[], int n);

int main()
{
    int A[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);

    printf("\t Arreglo desordenado");
    PRINT(A, n);
    INSERTIONSORT(A, n);
    printf("\t Arreglo ordenado");
    PRINT(A, n);

    return 0;
}

void INSERTIONSORT(int A[], int n)
{
    int key;
    int i = 1;
    int j = i - 1;
    for (i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

void PRINT(int A[], int n)
{
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%d] ", A[i]);
    }
    printf("\n\n");
}