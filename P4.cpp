//Given a sorted array a[] of size n,
// delete all the duplicated elements from a[]
// & modify the array such that only distinct 
//elements should be present there.
#include<bits/stdc++.h>
using namespace std;


// using set but T.C is nlogn
void dup(vector<int>&arr)
{
    set<int>s;
    for(auto it=arr.begin();it!=arr.end();it++)
    {
        s.insert(*(it));
    }
    for(auto it=s.begin();it!=s.end();it++)
    cout<<*(it)<<" ";
}
void dup1(vector<int>arr)
{
   int i,j,nn;
   i=0;
   for(j=1;j<arr.size();j++)
   {
    if(arr[j]!=arr[i])
    {
     arr[++i]=arr[j];
     nn=i;
    }
   }
   for(i=0;i<=nn;i++)
   cout<<arr[i]<<" ";
   return;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
  {
     cin>>arr[i];;
  }
  dup1(arr);
  return 0;

}