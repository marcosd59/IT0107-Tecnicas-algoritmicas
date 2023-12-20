/*********************************************************************
Fecha de creacion: 21/09/2022
Fecha de ultima actualizacion: 21/09/2022
Nombre del programador: Marcos Damian Pool Canul
Nombre del programa: HEAP-SORT.
Descripcion: Ordenamiento por el metodo HEAP-SORT.
Entradas: Arreglos de numeros enteros.
Salidas: Arreglo ordenado.
*********************************************************************/
#include <iostream>
using namespace std;

void HEAPIFY(int arr[], int n, int root);
void HEAPSORT(int arr[], int n);
void PRINT(int arr[], int n);

// main program
int main()
{
    int heap_arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(heap_arr) / sizeof(heap_arr[0]);
    cout << "Input array" << endl;
    PRINT(heap_arr, n);

    HEAPSORT(heap_arr, n);

    cout << "Sorted array" << endl;
    PRINT(heap_arr, n);
}

// function to HEAPIFY the tree
void HEAPIFY(int arr[], int n, int root)
{
    int largest = root;   // root is the largest element
    int l = 2 * root + 1; // left = 2*root + 1
    int r = 2 * root + 2; // right = 2*root + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    // If largest is not root
    if (largest != root)
    {
        // swap root and largest
        swap(arr[root], arr[largest]);

        // Recursively HEAPIFY the sub-tree
        HEAPIFY(arr, n, largest);
    }
}

// implementing heap sort
void HEAPSORT(int arr[], int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        HEAPIFY(arr, n, i);
    }

    // extracting elements from heap one by one
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // again call max HEAPIFY on the reduced heap
        HEAPIFY(arr, i, 0);
    }
}

/* print contents of array - utility function */
void PRINT(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
        cout << "\n";
    }
}