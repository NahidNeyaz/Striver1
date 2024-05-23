// Majority element(>N/2)
#include <bits/stdc++.h>
using namespace std;
// brute force
// tc=O(n*N)
// sc=O(n)
void solve(vector<int> &v, int n)
{

    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[i] == v[j])
                c++;
        }
        if (c > (n / 2.0))
        {
            cout << v[i] << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}

// better
// tc=O(nlogn)+O(n)
// sc=O(n)
void solve1(vector<int> &v, int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[v[i]]++;
    for (auto it : mp)
    {
        if (it.second > (n / 2))
        {
            cout << it.first << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}

// optimal
// moore's voting algo
// tc=O(2n)
// sc=O(1)
void solve2(vector<int> &v, int n)
{
    int cnt = 0;
    int ele;
    for (int i = 0l; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            ele = v[i];
        }
        else if (v[i] == ele)
            cnt++;
        else
            cnt--;
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == ele)
            c++;
    }
    if (c > n / 2)
    {
        cout << ele << endl;
        return;
    }
    cout << -1 << endl;
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    solve(v, n);
    solve1(v, n);
    solve2(v, n);
    return 0;
}
