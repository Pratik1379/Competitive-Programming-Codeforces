#include<bits/stdc++.h>
using namespace std;
long int mod=998244353;
int main()
{
    int n,k;
    cin>>n>>k;
    long int dp[n+1][k+1][4];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j][0]=0;dp[i][j][1]=0;dp[i][j][2]=0;dp[i][j][3]=0;
        }
    }
    dp[1][1][0]=1;dp[1][1][1]=0;dp[1][1][2]=0;dp[1][1][3]=1;
    dp[1][2][0]=0;dp[1][2][1]=1;dp[1][2][2]=1;dp[1][1][3]=1;
    for(int i=2;i<=n;i++)
        {
            dp[i][1][0]=1;dp[i][1][1]=0;dp[i][1][2]=0;dp[i][1][3]=1;
        }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
                dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%mod;
                dp[i][j][1]=(dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j-2][2]+dp[i-1][j-1][3])%mod;
                dp[i][j][2]=(dp[i-1][j-1][0]+dp[i-1][j-2][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%mod;
                dp[i][j][3]=(dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3])%mod;
        }
    }
    long int ans=(dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%mod;
    cout<<ans;
}
