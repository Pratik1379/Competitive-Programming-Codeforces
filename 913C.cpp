#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long int k,l;
    cin>>n>>k;
    l=k;
    long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        a[i]=min(2*a[i-1],a[i]);
    }
    long int r=pow(2,n-1);
    long int cost=0;
    for(int i=n-1;i>=0;i--)
    {
        long int j=l/r;
        cost+=j*a[i];
        l=l-j*r;
        r=r/2;
        if(l<=0)
            break;
    }
    long int u=log2(k);
    u++;
    while(u<=31)
    {
        l=pow(2,u);
        r=pow(2,n-1);
        long int cnt=0;
        for(int i=n-1;i>=0;i--)
        {
        long int j=l/r;
        cnt+=j*a[i];
        l=l-j*r;
        r=r/2;
        if(l<=0)
            break;
        }
        cost=min(cost,cnt);
    }
    cout<<cost;
}
