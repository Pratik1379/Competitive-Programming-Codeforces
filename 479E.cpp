#include<bits/stdc++.h>
using namespace std;
long int mod=1e9+7;
int main()
{
    int n,a,b,k;
    cin>>n>>a>>b>>k;
    long long int dp[n+1][k+1];
    int left[n+1],right[n+1];
    for(int i=1;i<=n;i++)
    {
        if(i==a && abs(a-b)>1)
            dp[i][0]=1;
        else
            dp[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        int l,r;
        if(i==b)
            continue;
        if(i>=b)
        {
            l=(i+b)/2;
            r=n;
            left[i]=l;
            right[i]=r;
        }
        else
        {
            l=0;
            if((i+b)&1)
            r=(i+b)/2;
            else
            r=(i+b)/2-1;
            left[i]=l;
            right[i]=r;
        }
    }
    /*for(int i=1;i<=n;i++)
    {
      if(i==b)
        continue;
      cout<<left[i]<<" "<<right[i]<<endl;
    }*/
    long long int pre[n+1];
    pre[0]=0;
    for(int j=1;j<=k;j++)
    {
        for(int i=1;i<=n;i++)
        {
            pre[i]=(pre[i-1]+dp[i][j-1])%mod;
           // cout<<pre[i]<<" ";
        }
       // cout<<endl;
        for(int i=1;i<=n;i++)
        {
            if(i==b)
                dp[i][j]=0;
            else
            {
                dp[i][j]=(pre[right[i]]-pre[left[i]]-dp[i][j-1]+mod+mod+mod)%mod;
               // cout<<dp[i][j]<<" ";
            }
        }
       // cout<<endl;
    }
    long long int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(i!=b)
            sum=(sum+dp[i][k])%mod;
    }
    cout<<sum<<endl;
    return 0;
}
