#include<bits/stdc++.h>
using namespace std;
int w[300001];
vector<pair<int,int>> v;
bool vis[300001]={false};
long int dp[300001];
long int ans=0;
void dfs(int s)
{
    vis[s]=true;
    long int max1=-1;
    int vertex=-1;
    for(int i=0;i<v[s].size();i++)
    {
        if(!vis[v[s][i].first])
         {
        dfs(v[s][i].first);
        if((dp[v[s][i].first]-v[s][i].second)>maxi)
        {
            maxi=dp[v[s][i].first]-v[s][i].second;
            vertex=v[s][i].first;
        }
        }
    }
    maxi=max(maxi,0);
    dp[s]=w[s]+maxi;
    maxi=0;
    if(vertex>0)
    {
        maxi=-1;
        for(int i=0;i<v[s].size();i++)
        {
            if(v[s][i]!=vertex)
            {
                maxi=max(maxi,dp[v[s][i].first]-v[s][i].second);
            }
        }
        maxi=max(maxi,0);
    }
    ans=max(ans,dp[s]+maxi);
}
int main()
{
    int n,x,y,z;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=1;i<n;i++)
    {
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    dfs(1);
    cout<<ans;
    return 0;
}
