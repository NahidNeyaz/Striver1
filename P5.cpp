//Given an unsorted array arr[] of size N.
// Rotate the array to the left (counter-clockwise direction) by D steps, 
//where D is a positive integer.

#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>&a,int d,int N)
{
    if(N==0)
    return;
    d=d%N;
    int temp[d];
    for(int i=0;i<d;i++)
    {
        temp[i]=a[i];
    }
    for(int i=d;i<N;i++)
    {
        a[i-d]=a[i];
    }
    for(int i=0;i<d;i++)
    {
        a[i+(N-d)]=temp[i];
    }
    for(int i=0;i<N;i++)
    cout<<a[i]<<" ";
}

// reverse it 
void r(vector<int>&a,int d, int N )
{
    reverse(a[0],a[d]);
    reverse(a[d],a[N]);
    reverse(a[0],a[N]);
    for(int i=0;i<N;i++)
    cout<<a[i]<<" ";
    return;
}

int main()
{
    int N;
    int d;
    cin>>N;
    cin>>d;
    vector<int>a(N);
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    solve(a,d,N);
    r(a,d,N);

}