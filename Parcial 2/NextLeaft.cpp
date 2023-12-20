#include <iostream>
using namespace std;

int NextLeaft(int a[], int L, int k)
{
    for (int i = L; i >= 0; i--)
    {
        if (a[i] < k)
        {
            a[i] = a[i] + 1;
            return *a;
        }
        a[i] = 1;
    }
    return *a;
}

int main()
{
    int a[] = {1, 1, 1, 1};
    int L = 4;
    int k = 2;

    NextLeaft(a, L, k);

    cout << "array = [ ";

    for (int i = 0; i < L; i++)
    {
        cout << a[i] << ", ";
    }
    cout << "]" << endl;

    return 0;
}