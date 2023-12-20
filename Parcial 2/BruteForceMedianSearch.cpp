#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>

using namespace std;
#define INFTY 2147483647

int TotalDistance(char *s, char **DNA, int t, int n, int l);
char *BruteForceMedianSearch(char **DNA, int t, int n, int l);

int main()
{
    //***************************************
    // change the t, n, l ,ntimes here
    //****************************************
    int t = 4, n = 57, l = 3;
    char *mutif = new char[l];
    char **DNA = new char *[t];

    clock_t start, finish;
    double duration;

    for (int i = 0; i < t; i++)
    {
        DNA[i] = new char[n];
    }
    /*
    cout<<"Ingresa el valor para t: ";
    cin>>t;
    cout<<endl;
    cout << "Ingresa el valor de l: ";
    cin>>l;
    cout<<endl; */

    cout << "t=" << t << ",l=" << l << endl;

    ifstream fin("./data.txt");

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fin >> DNA[i][j];
            cout << DNA[i][j];
        }
        cout<<endl;
    }
    fin.close();

    start = clock();
    mutif = BruteForceMedianSearch(DNA, t, n, l);

    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "Average time for BruteForceMedianSearch is " << duration;
    cout << endl;
    cout << "the motif is ";

    cout << "'";
    for (int i = 0; i < l; i++)
    {
        cout << mutif[i];
    }
    cout << "'";
    cout << endl;
    cout << endl;

    return 0;
}

int TotalDistance(char *s, char **DNA, int t, int n, int l)
{
    char *v = new char[l];
    int Distance, MinDistance = INFTY, SumDistance = 0;

    for (int i = 0; i < t; i++)
    {
        MinDistance = INFTY;
        for (int j = 0; j < (n - l + 1); j++)
        {
            Distance = 0;
            for (int k = 0; k < l; k++)
            {
                v[k] = DNA[i][j + k];

                if (v[k] != s[k])
                {
                    Distance++;
                }
            }

            if (Distance < MinDistance)
            {
                MinDistance = Distance;
            }
        }

        SumDistance = SumDistance + MinDistance;
    }

    return SumDistance;
}

char *BruteForceMedianSearch(char **DNA, int t, int n, int l)
{
    int *a = new int[l];
    char *s = new char[l];
    char *mutif = new char[l];
    int endflag = 0, totaldistance = 0, BestDistance = INFTY;

    for (int i = 0; i < l; i++)
    {
        a[i] = 0;
    }

    while (1)
    {

        // cout << "while";
        for (int i = 0; i < l; i++)
        {
            if (a[i] == 0)
            {
                s[i] = 'a';
            }
            else if (a[i] == 1)
            {
                s[i] = 'c';
            }
            else if (a[i] == 2)
            {
                s[i] = 'g';
            }
            else if (a[i] == 3)
            {
                s[i] = 't';
            }
        }

        totaldistance = TotalDistance(s, DNA, t, n, l);
        if (totaldistance < BestDistance)
        {
            BestDistance = totaldistance;
            for (int i = 0; i < l; i++)
            {
                mutif[i] = s[i];
                // cout << mutif[i];
            }
            // cout << BestDistance<<endl;
            // cout << endl;
        }

        for (int i = (l - 1); i >= 0; i--) // calculate the next leaf
        {
            if (a[i] == 3)
            {
                a[i] = 0;
                if (i == 0)
                {
                    endflag = 1;
                }
            }
            else
            {
                a[i]++;
                break;
            }
        }

        if (endflag == 1) // if go over all the leaves, break loop
            break;
    }

    return mutif; // return the best mutif
}