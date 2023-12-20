#include <iostream>
using namespace std;

void ManhattanTourist(int WDown[][5], int WRigth[][5], int s[][5], int n, int m)
{
    s[0][0] = {0};

    for (int i = 0; i < n; i++)
    {
        s[i][0] = s[i - 1][0] + WDown[i][0];
    }

    for (int j = 0; j < m; j++)
    {
        s[0][j] = s[0][j - 1] + WRigth[0][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int SDown = s[i - 1][j] + WDown[i][j];
            int SRight = s[i][j - 1] + WRigth[i][j];

            if (SDown >= SRight)
            {
                s[i][j] = SDown;
            }
            else
            {
                s[i][j] = SRight;
            }
        }
    }
}

int main()
{
    int WDown[5][5] = {{0, 0, 0, 0, 0},
                       {1, 0, 2, 4, 3},
                       {4, 6, 5, 2, 1},
                       {4, 4, 5, 2, 1},
                       {5, 6, 8, 5, 3}};

    int WRigth[5][5] = {{0, 3, 2, 4, 0},
                        {0, 3, 2, 4, 2},
                        {0, 0, 7, 3, 4},
                        {0, 3, 3, 0, 2},
                        {0, 1, 3, 2, 2}};

    int s[5][5] = {{0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0}};

    int n = 5;
    int m = 5;


    ManhattanTourist(WDown, WRigth, s, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << s[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}