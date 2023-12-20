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

void AllLeaves(int L, int k)
{
    int a[4] = {1, 1, 1, 1};
    int b[4] = {1, 1, 1, 1};
    int cont = 0;

    while (1)
    {
        for (int i = 0; i < L; i++)
        {
            cout << a[i];
        }

        cout << endl;

        a[4] = NextLeaft(a, L, k);

        for (int i = 0; i < L; i++)
        {
            if (a[i] == b[i])
            {
                cont++;
            }
        }

        if (cont == L)
        {
            return;
        }

        else
        {
            cont = 0;
        }
    }
}

int main()
{
    int a[] = {1, 1, 1, 1};
    int L = 4;
    int k = 2;

    AllLeaves(L, k);

    return 0;
}