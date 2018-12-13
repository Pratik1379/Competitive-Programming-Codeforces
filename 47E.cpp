#include<bits/stdc++.h>
using namespace std;
long long int mod=998244353;
long long int power2[1000001];
long long int dp[1000001];
int main()
{
    long long int p=1;
    long long int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=0;i<=n;i++)
    {
        power2[i]=p;
        p=(p*2)%mod;
    }
    dp[0]=1;
    for(long long int i=1;i<n;i++)
    {
        dp[i]=((i*power2[i-1])%mod+(power2[i]))%mod;
    }
    int l=0;
    long long int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        ans=(ans+(dp[l]*a[i])%mod)%mod;
        l++;
    }
    cout<<ans<<endl;
    return 0;
}
