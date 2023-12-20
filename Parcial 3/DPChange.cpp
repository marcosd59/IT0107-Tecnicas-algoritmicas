#include <iostream>
#define INFINITY 2147483647
using namespace std;

int DPChange(int M, int c[], int d, int bestNumCoins[])
{
    for (int i = 0; i < M; i++)
    {
        bestNumCoins[i] = 0;
    }

    bestNumCoins[0] = 0;

    for (int m = 0; m < M; m++)
    {
        bestNumCoins[m] = INFINITY;
        for (int i = 0; i < d; i++)
        {
            if (m >= c[i])
            {
                if (bestNumCoins[m - c[i]] + 1 < bestNumCoins[m])
                {
                    bestNumCoins[m] = bestNumCoins[m - c[i]] + 1;
                }
            }
        }
    }

    return *bestNumCoins;
}

int main()
{
    int c[3] = {1, 3, 7};
    int d = 3;
    int M = 3;
    int bestNumCoins[M];

    DPChange(M, c, d, bestNumCoins);

    cout << "BetterChange = [ ";

    for (int j = 0; j < M; j++)
    {
        cout << bestNumCoins[j] << ", ";
    }
    cout << "]" << endl;

    return 0;
}