// Given an array arr[] of n positive integers.
//  Push all the zeros of the given array to the right end of the array while maintaining the order
//  of non-zero elements.
//  Do the mentioned change in the array in-place.
#include <bits/stdc++.h>
using namespace std;

// brute force T.C=O(N)& S.C=O(N)
void m1(vector<int> v, int n)
{
    int cs = 0;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != 0)
        {
            temp.push_back(v[i]); // storing the non zero element
            cs++;
        }
    }
    for (int i = 0; i < cs; i++)
        v[i] = temp[i];
    for (int i = cs; i < n; i++)
        v[i] = 0; // filling the remaining space with 0
    for (int i = 0; i < n; i++)
        cout << v[i] << endl;
}

// optimal 
//time complexity=O(n) and space complexity=O(1)
void m2(vector<int> v, int n)
{
    int j;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < n; i++)
    {
        if (v[i] != 0)
        {
            swap(v[i], v[j]);
            j++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    m1(v, n);
    m2(v, n);
}