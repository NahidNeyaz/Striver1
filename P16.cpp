//MAximum subarray sum

#include<bits/stdc++.h>
using namespace std;


//brute force
//tc= O(n*N*N)
//sc=O(1)
void solve(vector<int>&v, int n)
{
    long long maxi=LONG_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            long long sum=0;
            for(int k=i;k<=j;k++)
            {
             sum+=v[k];
             maxi=max(maxi,sum);
            }
        }
    }
    cout<<maxi<<endl;
    return;
}

//better
//tc==O(N*N)
//sc=O(1)
void solve1(vector<int>&v, int n)
{
    long long maxi=LLONG_MIN;
    for(int i=0;i<n;i++)
    {
        long long sum=0;
        for(int j=i;j<n;j++)
        {
         sum+=v[j];
         maxi=max(maxi,sum);
        }
    }
    cout<<maxi<<endl;
    return;
}

//optimal
//kadane's algo
//tc=O(n)
//sc=O(1)
void solve3(vector<int>&v, int n)
{
    long long sum=0;
    long long maxi=LLONG_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum>maxi)
        maxi=sum;
        if(sum<0)
        sum=0;
    }
    cout<<maxi<<endl;
    return;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    solve(v,n);
    solve1(v,n);
    solve3(v,n);
    return 0;
}
