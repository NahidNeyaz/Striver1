//two sum

#include<bits/stdc++.h>
using namespace std;

//brute force
//tc=O(n*n)
//sc=O(1)
void solve(int n,int ar[],int t)
{
    int flag=0;
    int f,s;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ar[i]+ar[j]==t)
            {
                f=i;
                s=j;
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    cout<<"NO"<<endl;
    else
    cout<<"YES at "<<f<<" and "<<s<<endl;
    return;
}

//better 
//tc=O(NlogN)
//sc=O(n)
void solve2(int n, int ar[], int t)
{
    map<int, int>mp;
    int flag=0;
    int f,s;
    for(int i=0;i<n;i++)
    {
        int a=ar[i];
        int more=t-a;
        if(mp.find(more)!=mp.end())
        {
            f=i;
            s=mp[more];
            flag=1;
            break;
        }
        mp[a]=i;
    }
    if(flag==0)
    cout<<"NO"<<endl;
    else
    cout<<"YES at "<<f<<" and "<<s<<endl;
}

//opimal
//ttc=O(N)+O(NlogN)
//sc=O(1)
void solve3(int n,int ar[], int t)
{
    int left=0;
    int right=n-1;
    int sum=0;
    int f,s,flag=0;
    sort(ar,ar+n);
    while(left<right)
    {
        sum=ar[left]+ar[right];
        if(sum==t)
        {
         flag=1;
         break;
        }
        else if(sum>t)
        right--;
        else
        left++;
    }
    if(flag==1)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    return;
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    cin>>ar[i];
    int t;
    cin>>t;
    solve(n,ar,t);
    solve2(n,ar,t);
    solve3(n,ar,t);
    return 0;
}