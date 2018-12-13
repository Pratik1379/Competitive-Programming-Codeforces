#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001];
vector<pair<double,int>> v;
int main()
{
    int n,m,x;
    double y;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(y,x));
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=m;i++)
    {
        dp[0][i]=0;
    }
    int maxi;
    for(int i=1;i<=n;i++)
    {
        maxi=dp[i-1][1];
        for(int j=1;j<=m;j++)
        {
            if(v[i-1].second==j)
            {
                dp[i][j]=1+maxi;
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
            maxi=max(maxi,dp[i-1][j+1]);
        }
    }
    maxi=0;
    for(int i=1;i<=m;i++)
      maxi=max(maxi,dp[n][i]);
    cout<<n-maxi<<endl;
}
