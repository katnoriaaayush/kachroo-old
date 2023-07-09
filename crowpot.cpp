#include<bits/stdc++.h>

using namespace std;
int n,k;

int minStones(int arr[])
{
    int stones=0;
    int dup[n];
    for(int i=0;i<n;i++)
    {
        dup[i]=arr[i];
    }
    for(int i=n-1;i>0;i--)
    {
        dup[i]=max(0,dup[i]-dup[i-1]);
    }

    for(int i=0;i<k;i++)
    {
        stones+=(dup[i]*(n-i));
    }
    return stones;
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    
    cin>> n;
    int arr[n];
    for(int i=0;i<n;i++)
    { 
        cin >> arr[i];
    }
    cin >> k;
    sort(arr, arr+n);

    cout<<minStones(arr);

  }
}