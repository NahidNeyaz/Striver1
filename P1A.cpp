#include<bits/stdc++.h>
using namespace std;

void solve(int n, int m, int a)
{
double dl=n;
double w=m;
cout<<ceil(dl/a)<<endl;
cout<<ceil(w/a)<<endl;
long long rq;
rq=ceil(dl/a)*ceil(w/a);
cout<<rq<<endl;
}
int main()
{
    int n,m,a;
    cin>>n>>m>>a;
    solve(n,m,a);
    return 0;
}