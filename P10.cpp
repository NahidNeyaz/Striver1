// mmaximum no. of 1's continuosly
#include <bits/stdc++.h>
using namespace std;

//brute force
//tc=o(n)
//sc=O(1)
void solve1(int ar[], int n)
{
    int c = 0;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] == 1)
        {
            c++;
            m = max(m, c);
        }
        else
            c = 0;
    }
    cout << c << endl;
}

int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    solve1(ar, n);
    return 0;
}