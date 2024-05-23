// longest subarray with sum k
#include <bits/stdc++.h>
using namespace std;

// brute force
// tc=O(n*n)
// sc=O(1)
void solve(int ar[], int k, int n)
{
    int len = 0;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = 0;
        for (int j = i; j < n; j++)
        {
            // s=0;
            // for(int k=i;k<=j;k++)
            // s+=ar[k];
            s += ar[j];
            if (k == s)
                len = max(len, j - i + 1);
        }
    }
    cout << len << endl;
}

// better
// tc=O(n*nlogn)
// sc=O(n)
// POSITIVE, NEGATIVE,ZEROES
void solve1(int ar[], int k, int n)
{
    map<long long, int> mp;
    long long sum = 0;
    int maxl = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ar[i];
        if (sum == k)
        {
            maxl = max(maxl, i + 1);
        }
        long long rem = sum - k;
        if (mp.find(rem) != mp.end())
        {
            int l = i - mp[rem];
            maxl = max(maxl, l);
        }
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }
    cout << maxl << endl;
}

// optimal
// tc=O(2n)
// sc=O(1)
void solve2(int ar[], int k, int n)
{
    int left = 0;
    int right = 0;
    int maxl = 0;
    long long sum = ar[0];
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= ar[left];
            left++;
        }
        if (sum == k)
        {
            int len = right - left + 1;
            maxl = max(maxl, len);
        }
        right++;
        sum += ar[right];
    }
    cout << maxl << endl;
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    int k;
    cin >> k;
    solve(ar, k, n);
    solve1(ar, k, n);
    solve2(ar, k, n);
    return 0;
}