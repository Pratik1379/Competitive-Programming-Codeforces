#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans;
    cin>>n;
    long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int maxi=1;
    int left[n];
    int right[n];
    left[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])
        {
            left[i]=left[i+1]+1;
        }
        else
        {
            left[i]=0;
        }
    }
    right[0]=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            right[i]=right[i-1]+1;
        }
        else
            right[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            maxi=max(maxi,left[i]);
        }
        else if(i==n-1)
        {
            maxi=max(maxi,right[i]);
        }
        else
            maxi=max(maxi,max(right[i-1]+left[i+1]+1));
    }
    cout<<maxi;
}
