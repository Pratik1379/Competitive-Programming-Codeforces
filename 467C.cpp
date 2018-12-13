#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    long long int pre[n+1];
    long long int a[n+1];
    pre[0]=0;
    long long int b[n-m+2];
    long long int dp[k+1][n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=a[i]+pre[i-1];
    }
    long long int s1=0;
    for(int i=1;i<=m;i++)
        s1+=a[i];
    b[1]=s1;
    for(int i=2;i<=n-m+1;i++)
    {
        b[i]=b[i-1]+a[i+m-1]-a[i-1];
    }
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
            dp[i][j]=0;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=i*m;j<=n;j++)
        {
            if(j==i*m)
            {
                dp[i][j]=max(dp[i][j],pre[i*m]);
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],max(dp[i][j],dp[i-1][j-m]+b[j-m+1]));
            }
        }
    }
    cout<<dp[k][n];

}
