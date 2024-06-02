// leader in an array

#include <bits/stdc++.h>
using namespace std;

// tc=O(n*n)
void solve(vector<int> v, int n)
{
    vector<int> ans;
    int j;
    for (int i = 0; i < n; i++)
    {
        string leader = "t";
        for (j = i + 1; j < n; j++)
        {
            if (v[j] > v[i])
            {
                leader = "f";
                break;
            }
        }
        if (leader == "t")
            ans.push_back(v[i]);
    }
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *(it) << endl;
}

// optimal
// tc=O(N)
void solve2(vector<int> v, int n)
{
    int maxi = INT_MIN;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] > maxi)
        {
            ans.push_back(v[i]);
        }
        maxi = max(v[i], maxi);
    }
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *(it) << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    solve(v, n);
    solve2(v,n);
    return 0;
}
