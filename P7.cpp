// Given two sorted arrays of size n and m respectively,
//  find their union. The Union of two arrays can be defined
//  as the common and distinct elements in the two arrays.
//  Return the elements in sorted order.
#include <bits/stdc++.h>
using namespace std;

// brute force
// time complexity=O(nlogn+mlogm) and space complexity=O(n+m)
void m1(vector<int> v1, vector<int> v2, int n, int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(v1[i]);
    for (int i = 0; i < m; i++)
        s.insert(v2[i]);
    for (auto it = s.begin(); it != s.end(); it++)
        cout << *(it) << endl;
}

// optimal
// time complexity=O(m+n) and space complexity O(union)
void m2(vector<int> v1, vector<int> v2, int n, int m)
{
    vector<int> un;
    int i = 0;
    int j = 0;
    while (i < n && j < m) // no array is saturated
    {
        if (v1[i] <= v2[j])
        {
            if (un.empty() ||un.back() != v1[i] )
            {
                un.push_back(v1[i]);
            }
            i++;
        }
        else
        {
            if (un.empty() || un.back() != v2[j])
            {
                un.push_back(v2[j]);
            }
            j++;
        }
    }
    while (i < n)
    {
        if (un.back() != v1[i])
            un.push_back(v1[i]);
        i++;
    }
    while (j < m)
    {
        if (un.back() != v2[j])
            un.push_back(v2[j]);
        j++;
    }
    for (auto it = un.begin(); it != un.end(); it++)
        cout << *(it)<<endl;
}
int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<int> v1(n);
    vector<int> v2(m);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < m; i++)
        cin >> v2[i];
    m1(v1, v2, n, m);
    m2(v1, v2, n, m);
}