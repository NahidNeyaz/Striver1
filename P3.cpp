//Given an array arr[] of size N, check if it is sorted in non-decreasing order or not. 
#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>&arr)
{
    int flag=1;
    for(auto it=arr.begin();it!=arr.end();it++)
    {
        if(*(it)>*(it+1))
        flag=0;
    }
    cout<<flag<<endl;
}
int main()
{
    int N;
    cin>>N;
    vector<int>arr(N);
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    solve(arr);
    return 0;
}