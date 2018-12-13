#include<bits/stdc++.h>
using namespace std;
long int mod=998244353;
int main()
{
    int n,m;
    string s,t;
    cin>>n>>m>>s>>t;
    long int a[200001];
    long int p=1;
    int maxi=max(n,m);
    a[maxi]=0;
    if(n>=m)
    {
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]==1)
        {
            a[i]=(a[i+1]+p)%mod;
        }
        else
            a[i]=a[i+1];
        p=(p*2)%mod;
    }
    }
    else
    {
        int temp=m-n;
        for(int i=m-1;i>=temp;i--)
        {
            if(s[i-temp]==1)
            {
                a[i]=(a[i+1]+p)%mod;
            }
            else
                a[i]=a[i+1];
            p=(p*2)%mod;
        }
        for(int i=temp-1;i>=0;i--)
        {
            a[i]=a[i+1];
        }
    }
    long long int ans=0;
    for(int i=0;i<m;i++)
    {
        if(t[i]==1)
        {
            ans=(ans+a[i])%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
