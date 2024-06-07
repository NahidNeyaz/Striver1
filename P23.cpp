// longest subsequence in an array

#include <bits/stdc++.h>
using namespace std;

// tc=O(n*N)
bool lis(vector<int> v, int x)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == x)
            return true;
    }
    return false;
}
void solve(vector<int> v, int n)
{
    int longest = 1;
    int x;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        x = v[i];
        cnt = 1;
        while (lis(v, x + 1) == true)
        {
            x = x + 1;
            cnt++;
        }
        longest = max(longest, cnt);
    }
    cout << longest << endl;
}

void solve2(vector<int> v, int n)
{
    sort(v.begin(), v.end());
    int longest = 1;
    int cnt = 0;
    int lastsmall = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (v[i] - 1 == lastsmall)
        {
            cnt++;
            lastsmall = v[i];
        }
        else if (v[i] != lastsmall)
        {
            cnt = 1;
            lastsmall = v[i];
        }
        longest = max(longest, cnt);
    }
    cout << longest << "B" << endl;
}

void solve3(vector<int> v, int n)
{
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    int longest = 1;
    int cnt = 0;
    int x;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(v[i]);
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            cnt = 1;
            x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    cout << longest  << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    solve(v, n);
    solve2(v, n);
    solve3(v, n);
    return 0;
}