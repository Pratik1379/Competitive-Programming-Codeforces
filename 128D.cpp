#include <iostream>
using namespace std;

int main() {
    int n1,n2,k1,k2;cin>>n1>>n2>>k1>>k2;
    int dp[n1+1][n2+1][k1+1][k2+1];int i,j,k,l,a,b;
    for(i=0;i<=n1;i++)
    {
        for(j=0;j<=n2;j++)
        {
            for(k=0;k<=k1;k++)
            {
                for(l=0;l<=k2;l++)
                {
                    dp[i][j][k][l]=0;
                }
            }
        }
    }
    long long int sum=0;
    for(i=0;i<=n1;i++)
    {
        for(j=0;j<=n2;j++)
        {
            for(k=0;k<=k1;k++)
            {
                for(l=0;l<=k2;l++)
                {
                    if(i+j==0)
                    {
                        dp[i][j][k][l]=1;
                    }
                    else
                    {
                     if(k>0&&i>0)
                     {
                        dp[i][j][k][l]=dp[i-1][j][k-1][k2]+dp[i][j][k][l];
                     }
                     if(l>0&&j>0)
                     {
                        dp[i][j][k][l]=dp[i][j-1][k][l-1]+dp[i][j][k][l];
                     }
                        dp[i][j][k][l]=(dp[i][j][k][l])%100000000;
                    }
                }
            }
        }
    }
