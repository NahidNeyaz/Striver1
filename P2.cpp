//Given an array Arr of size N, print the second largest distinct element from an array. If the second largest element doesn't exist then return -1.

#include<bits/stdc++.h>
using namespace std;


//sort it 
int sl1(vector<int>&arr)
{
    for(auto it=arr.begin()+1;it!=arr.end();it++){
    if(*(it)<*(it-1)){
    swap(*(it),*(it-1));
    }}
    int max=arr.back();
    int i=arr.size()-2;
    while(i>=0)
    {
        if(arr[i]!=max)
        return arr[i];
        i--;
    }
    return (-1);
}


//find the largest and then assigned it
int sl2(vector<int>&arr)
{
    int l=arr[0];
    int sl=-1;
    for(auto it=arr.begin();it!=arr.end();it++)
    {
        if(*(it)>l)
        {
            sl=l;
            l=*(it);
        }
    }
    return(sl);
}




int main()
{
    int N;
    cin >>N;
    vector<int>arr(N);
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    int m1=sl1(arr);
    int m2=sl2(arr);
    cout<<m2<<endl;
    
}