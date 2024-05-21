// find the number that appear once and others exist twice
#include <bits/stdc++.h>
using namespace std;

// brute force
// tc=O(n*n)
// sc=O(1)
void solve1(int ar[], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        int a = ar[i];
        for (int j = 0; j < n; j++)
        {
            if (a == ar[j])
                c++;
        }
        if (c == 1)
            cout << ar[i] << endl;
    }
}

// better
// tc=O(n+n+n)
// sc=O(m+1)
void solve2(int ar[], int n)
{
    int m;
    m = ar[0];
    for (int i = 0; i < n; i++)
        m = max(m, ar[i]);
    int hash[m + 1] = {0};
    for (int i = 0; i < n; i++)
        hash[ar[i]]++;
    for (int i = 0; i < n; i++)
    {
        if (hash[i] == 1)
            cout << i << endl;
    }
}

// better-2
// tc=o(n)
// sc=O(n)
void solve3(int ar[], int n)
{
    unordered_map<int, int> un;
    for (int i = 0; i < n; i++)
        un[ar[i]]++;
    for (auto it : un)
    {
        if (it.second == 1)
            cout << it.first << endl;
    }
}

//optimal
//tc=O(n)
//sc=O(1)
void solve4(int ar[],int n)
{
    int XOR=0;
    for(int i=0;i<n;i++)
    {
        XOR=XOR^ar[i];
    }
    cout<<XOR<<endl;
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    solve1(ar, n);
    solve2(ar, n);
    solve3(ar, n);
    solve4(ar, n);
    return 0;
}
