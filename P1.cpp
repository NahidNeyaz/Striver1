//Given an array A[] of size n. The task is to find the largest element in it.

#include<bits/stdc++.h>
using namespace std;

//optimal approach:
int  largest(vector <int> &a)
{
    int max;
    max= a[0];// assign a max value
  for(auto it=a.begin();it!=a.end();it++)
  {
    if(*(it)>max)// compare 
    max=*(it);// change
  }
  return max;// return 
}

//Brute force approach:by sorting and getting the last index value
// void Csort(vector<int>&a)
// {
//     for(auto it=a.begin()+1;it!=a.end();it++)
//     {
//         if(*(it-1)>*(it))
//         {
//             swap(*(it-1),*it);
//     }
//     cout<< a.back()<<endl;
// }
// }


int main()
{
int n;
cin>>n;
int i;
vector<int>a(n);
for(i=0;i<n;i++)
cin>>a[i];
//Csort(a);
int gt=largest(a);
cout << gt<<"\n";
return 0;
}

