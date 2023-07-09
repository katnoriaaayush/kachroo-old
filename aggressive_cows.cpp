#include<bits/stdc++.h>

using namespace std;

bool check(int m,int n, int k, int arr[])
{
    int curr_cows=1;
    int left=0;

    for(int i=1;i<n;i++)
    {
        if(arr[i]-arr[left]>=m)
        {
            left=i;
            ++curr_cows;
            if(curr_cows==k)
                return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, arr[1000], cows;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cin >> cows;

        sort(arr,arr+n);

        int l=0;
        int r = arr[n-1]-arr[0]+1;

        while(l<r)
        {
            int mid = (l+r+1)/2;

            if(check(mid, n, cows, arr))
                l=mid;
            else
                r=mid-1;
        }
        cout << "Answer: "<<l<<endl;
    }
}