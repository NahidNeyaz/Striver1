// You are given an array of prices
//  where prices[i] is the price of a given 
//  stock on an ith day.
// You want to maximize your profit by 
// choosing a single day to buy one stock and 
// choosing a different day in the future to 
// sell that stock. Return the maximum profit
//  you can achieve from this transaction.
//  If you cannot achieve any profit, return 0.

#include<bits/stdc++.h>
using namespace std;

//tc=O(N)
//sc=O(N)
void solve(vector<int>&v,int n)
{
    int cost;
    int maxp=0;
    int mini=INT_MAX;
    for(int i=1;i< n;i++)
    {
        cost=v[i]-mini;
        maxp=max(maxp,cost);
        mini=min(mini,v[i]);
    }
    cout<<maxp<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    solve(v,n);
}