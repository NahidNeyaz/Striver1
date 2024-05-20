// intersection of 2 sorted arrays
#include <bits/stdc++.h>
using namespace std;

// brute force
// t.c=O(n^2)
// s.c=O(inter+v1)
void m1(int ar1[], int ar2[], int n, int m)
{
    int s = max(n, m);
    vector<int> inter;
    vector<int> v1(s, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ar1[i] == ar2[j] && v1[i] == 0)
            {
                inter.push_back(ar1[i]);
                v1[i]++;
                break;
            }
            if (ar2[j] > ar1[i])
                break;
        }
    }
    for (auto it = inter.begin(); it != inter.end(); it++)
        cout << *(it) << endl;
}
// optimal
// t.c=O(n+m)
// s.c=O(inter)
void m2(int ar1[], int ar2[], int n, int m)
{
    vector<int> inter;
    int i = 0;
    int j = 0;
    while (i < n && i < m)
    {
        if (ar1[i] < ar2[j])
            i++;
        else if (ar1[i] > ar2[j])
            j++;
        else
        {
            inter.push_back(ar1[i]);
            i++;
            j++;
        }
    }
    for (auto it = inter.begin(); it != inter.end(); it++)
        cout << *(it) << endl;
}
int main()
{
    int n;
    int m;
    cin >> n >> m;
    int ar1[n];
    int ar2[m];
    for (int i = 0; i < n; i++)
        cin >> ar1[i];
    for (int i = 0; i < m; i++)
        cin >> ar2[i];
    m1(ar1, ar2, n, m);
    m2(ar1, ar2, n, m);
}