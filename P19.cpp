// rearrange tha array by sign
//no. of positive = no.of negative
#include <bits/stdc++.h>
using namespace std;



//tc=O(2N)
//sc=O(N)
void solve(int n, vector<int> &v)
{
    vector<int> p(n/2);
    vector<int> ne(n/2);
    int k = 0;
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= 0)
        {
            p[k] = v[i];
            k++;
        }
        else
        {
            ne[g] = v[i];
            g++;
        }
    }
    k = 0;
    g = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << p[k] << " ";
            k++;
        }
        else
        {
            cout << ne[g] << " ";
            g++;
        }
    }
    cout << endl;
}


void solve2(int n, vector<int>&v)
{
    vector<int>nn(n);
    int p=0;
    int o=1;
    for(int i=0;i<n;i++)
    {
        if(v[i]>=0)
        {
            nn[p]=v[i];
            p+=2;
        }
        else
        {
            nn[o]=v[i];
            o+=2;
        }
    }
    for(int i=0;i<n;i++)
    cout<<nn[i]<<" ";
    cout<<endl;

}



int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    solve(n, v);
    solve2(n, v);
    return 0;
}