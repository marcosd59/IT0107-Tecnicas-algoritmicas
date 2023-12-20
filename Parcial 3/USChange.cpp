#include <iostream>
using namespace std;

void USChange(int M)
{
    int q = 25;
    int d = 10;
    int n = 5;
    int p = 1;

    int r = M;

    q = r / 25;
    r = r - 25 * q;

    d = r / 10;
    r = r - 10 * d;

    n = r / 5;
    r = r - 5 * n;

    p = r;

    cout << "25: " << q << endl;
    cout << "10: " << d << endl;
    cout << " 5: " << n << endl;
    cout << " 1: " << p << endl;
}

int BetterChange(int M, int c[], int d, int i[])
{
    int r = M;

    for (int k = 0; k < d; k++)
    {
        i[k] = r / c[k];
        r = r - c[k] * i[k];
    }

    return *i;
}

int main()
{
    int d = 5;
    int i[d];
    int c[5] = {25, 20, 10, 5, 1};
    int M = 78;
    cout << "Ingresa tu cambio: ";
    cin >> M;

    /*USChange(M);*/
    BetterChange(M, c, d, i);

    cout << "BetterChange = [ ";

    for (int j = 0; j < d; j++)
    {
        cout << i[j] << ", ";
    }
    cout << "]" << endl;

    return 0;
}