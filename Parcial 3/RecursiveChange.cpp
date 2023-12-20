#include <iostream>
#define INFINITY 2147483647
using namespace std;

int RecursiveChange(int M, int c[], int d)
{
    if (M == 0)
    {
        return 0;
    }

    int bestNumCoins = INFINITY;

    for (int i = 0; i < d; i++)
    {
        if (M >= c[i])
        {
            int numCoins = RecursiveChange(M - c[i], c, d);
            if (numCoins + 1 < bestNumCoins)
            {
                bestNumCoins = numCoins + 1;
            }
        }
    }
    return bestNumCoins;
}

int main()
{
    int c[3] = {1, 3, 7};
    int d = 3;
    int M = 10;

    cout << "Tu cambio es: ";
    cout << RecursiveChange(M, c, d);

    return 0;
}