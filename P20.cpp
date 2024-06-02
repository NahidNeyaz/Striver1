// Rearrange array based on sign
// positve!=negative

#include <bits/stdc++.h>
using namespace std;


//tc=O(N)
//sc=O(N)
void solve(vector<int> v, int n)
{
    vector<int> p;
    vector<int> ne;
    vector<int> ans(n);
    int index=0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= 0)
            p.push_back(v[i]);
        else
            ne.push_back(v[i]);
    }
    int po = 0;
    int neg = 0;
    if (p.size() >= ne.size())
    {
        for (int i = 0; i < ne.size(); i++)
        {
            ans[i * 2] = p[po];
            ans[i * 2 + 1] = ne[neg];
            po++;
            neg++;
        }
        index = ne.size() * 2;
        for (int i = ne.size(); i < p.size(); i++)
        {
            ans[index] = p[po];
            po++;
            index++;
        }
    }
    else
    {
        for (int i = 0; i < p.size(); i++)
        {
            ans[i * 2] = p[po];
            ans[i * 2 + 1] = ne[neg];
            po++;
            neg++;
        }
        int index = p.size() * 2;
        for (int i = p.size(); i < ne.size(); i++)
        {
            ans[index] = ne[neg];
            neg++;
            index++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i]<<" ";
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    solve(v, n);
    return 0;
}