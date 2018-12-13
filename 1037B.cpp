#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;long int m;
    cin>>n>>m;
    long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long long int ans=0;
    if(a[n/2]<m)
    {
    for(int i=n-1;i>=n/2;i--)
    {
        if(a[i]<m)
            ans+=(m-a[i]);
    }
    }
    else if(a[n/2]>m)
    {
        for(int i=0;i<=n/2;i++)
        {
        if(a[i]>m)
            ans+=(a[i]-m);
        }
    }
    cout<<ans;
    return 0;
}
