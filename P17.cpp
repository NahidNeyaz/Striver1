
#include<bits/stdc++.h>
using namespace std;

void solve3(vector<int>&v, int n)
{
    int start;
    int end;
    long long sum=0;
    long long maxi=LLONG_MIN;
    for(int i=0;i<n;i++)
    {
        if(sum==0)
        start=i;
        sum+=v[i];
        if(sum>maxi)
        {maxi=sum;
        end=i;}
        if(sum<0)
        sum=0;
    }
    for(int i=start;i<=end;i++)
    cout<<v[i]<<endl;;
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
    solve3(v,n);
    return 0;
}