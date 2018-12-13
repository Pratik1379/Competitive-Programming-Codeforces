#include <bits/stdc++.h>
using namespace std;
bool dp[501][501][501]={false};
vector<int> h;
int main()
{
    int n,k;
    cin>>n>>k;
    int sum=0;
    int a[n];
    for(int i=0;i<n;i++)
        {cin>>a[i];
        dp[i][a[i]][a[i]]=true;
        sum+=a[i];
        }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int l=1;l<=k;l++)
            {
                dp[i][j][l]=(dp[i-1][j][l]);
                if(j>=a[i])
                {
                    dp[i][j][l]=dp[i][j][l]|dp[i][j-a[i]][l];
                }
                if(l>=a[i])
                {
                    dp[i][j][l]=dp[i][j][l]|dp[i][j-a[i]][l-a[i]];
                }
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(dp[n][i][k])
            h.push_back(i);
    }
    sort(h.begin(),h.end());
    if(h[0]!=0)
    {
        h.push_back(0);
        sort(h.begin(),h.end());
    }
    cout<<h.size()<<endl;
    for(int i=0;i<h.size();i++)
    {
        cout<<h[i]<<" ";
    }
    return 0;
}
