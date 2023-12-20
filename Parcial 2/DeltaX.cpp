#include <iostream>

using namespace std;

int main()
{
    int x[] = {0, 2, 4, 7, 10};
    int n = 5;
    int X;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j + i < n)
            {
                X = x[j + i] - x[j];
                cout << X << endl;
            }
        }
    }
    return 0;
}