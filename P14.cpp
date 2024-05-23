// sort an array containing 0,1,2

#include<bits/stdc++.h>
using namespace std;

//brute force
//sort
//tc=O(nlogn)
//sc=O(n)
void solve(vector<int>&v,int n)
{
  sort(v.begin(),v.end());
  for(int i=0;i<n;i++)
  cout<<v[i]<<" ";
  cout<<endl;
  return;
}

//better
//count
//tc=O(2N)
//sc=O(N)
void solve1(vector<int>&v, int n)
{
  int c1=0,c0=0,c2=0;
  for(int i=0;i<n;i++)
  {
    if(v[i]==0)
    c0++;
    else if(v[i]==1)
    c1++;
    else if(v[i]==2)
    c2++;
  }
  for(int i=0;i<c0;i++)
  v[i]=0;
  for(int i=c0;i<c1;i++)
  v[i]=1;
  for(int i=c1;i<c2;i++)
  v[i]=2;
  for(int i=0;i<n;i++)
  cout<<v[i]<<" ";
  cout<<endl;
  return;
}

//optimal
//imp
//dutch national algo
//tc=O(n)
//sc=O(1)
void solve2(vector<int>&v,int n)
{
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)
    {
        if(v[mid]==0)
        {
            swap(v[low],v[mid]);
            low++;
            mid++;
        }
        else if(v[mid]==1)
        mid++;
        else if(v[mid]==2)
        {
            swap(v[high],v[mid]);
            high--;
        }
    }
    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
    cout<<endl;
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
    solve2(v,n);
    return 0;
}