#include<bit/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int s=0;
    int r;
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]!=1)
                s++;
            if(i==0)
                r=a[i];
            else
                r=__gcd(r,a[i]);
        }
    if(r!=1)
    {
        cout<<-1;return 0;
    }
    if(s<n)
    {
        cout<<s;return 0;
    }
    int i=0;
    int end=0,len=1e8;
    while(i<n)
    {
        int j=i;
        int l=a[i];
        i++;
        while(i<n)
        {
            l=__gcd(l,a[i]);
            if(l==1)
                break;
            i++;
        }
        if(len>(i-j))
        {
            len=i-j;
            end=i;
        }
    }
    int ans=0;
    for(int k=i;k>0;k--)
    {
        r=__gcd(a[k],a[k-1]);
        ans++;
        a[k-1]=r;
        if(r==1)
        {
            break;
        }
    }
    for(int u=0;u<n;u++)
    {
        if(a[u]!=1)
            ans++;
    }
    cout<<ans<<endl;
}
