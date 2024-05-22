#include <bits/stdc++.h>
using namespace std;

void solve(int x, int y)
{
    int f = 0, rem = 0;
    f=ceil(y/2.0);
    rem = (15*f)-(4*y);
    if (x > rem)
    {
        int extra=x-rem;
        f+=ceil(extra/15.0);
    }
    cout << f << endl;
}
int main()
{
    int t;
    cin >> t;
    int x;
    int y;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}