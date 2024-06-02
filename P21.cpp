// next permutation

#include <bits/stdc++.h>
using namespace std;


//tc=O(3N)
//sc=O(1)
void solve(vector<int> a, int s)
{
    int ind = -1;
    for (int i = s-2; i >=0; i--)
    {
        if (a[i] < a[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(a.begin(),a.end());
        for (int j = 0; j < s; j++)
            cout << a[j] << " " << endl;
    }
    else
    {
    for (int i = s - 1; i > ind; i--)
    {
        if (a[i] > a[ind])
        {
            swap(a[i], a[ind]);
            break;
        }
    }
    reverse(a.begin()+ind+1, a.end());
    }
    for (int i = 0; i < s; i++)
        cout << a[i] << " " << endl;
    return;
}
int main()
{
    int s;
    cin >> s;
    vector<int> a(s);
    for (int i = 0; i < s; i++)
        cin >> a[i];
    solve(a, s);
    return 0;
}
