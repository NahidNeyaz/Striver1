// Missing number
#include <bits/stdc++.h>
using namespace std;

// bruteforce
// t.c =O(n*n)
// sc=O(1)
void solve1(int ar[], int n)
{
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (ar[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << i << endl;
    }
}

// better
//tc=O(n+n)
//sc=O(n)
void solve2(int ar[], int n)
{
    int hash[n + 1] = {0};
    for (int i = 0; i < n - 1; i++)
        hash[ar[i]] = 1;
    for (int i = 1; i < n; i++)
    {
        if (hash[i] == 0)
            cout << i << endl;
    }
}

//optimal1
//tc=O(N)
//sc=O(1)
void solve3(int ar[],int n)
{
    int s=0;
    for(int i=0;i<n-1;i++)
    s+=ar[i];
    int ss;
    ss=n*(n+1)/2;
    int mn=0;
    mn=ss-s;
    cout<<mn<<endl;
}

//optimal4 XOR
//tc=O(n)
//sc=O(1)
void solve4(int ar[],int n)
{
  int XOR1=0;
  int XOR2=0;
  for(int i=0;i<n-1;i++)
  {
    XOR1=XOR1^ar[i];
    XOR2=XOR2^(i+1);
  }
  XOR2=XOR2^n;
  int ans=XOR1^XOR2;
  cout<<ans<<endl;
}



int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n - 1; i++)
        cin >> ar[i];
    solve1(ar, n);
    solve2(ar,n);
    solve3(ar,n);
    solve4(ar,n);
}