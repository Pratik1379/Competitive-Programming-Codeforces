#include<bits/stdc++.h>
using namespace std;
bool vis[100001]={false};
int cost[100001];
vector<int> adj[100001];
int check=0;
void dfs2(int x,int col)
{
    vis[x]=true;
    if(cost[x]!=col)
    {
        check=1;return;
    }
    for(unsigned int i=0;i<adj[x].size();i++)
    {
        if(!vis[adj[x][i]])
        {
            dfs2(adj[x][i],col);
        }
        if(check==1)
            return;
    }
}
bool dfs(int x)
{
    vis[x]=true;
    for(unsigned int i=0;i<adj[x].size();i++)
    {
        dfs2(adj[x][i],cost[adj[x][i]]);
        if(check==1)
            return false;
    }
    return true;
}
int main()
{
    int n,x,y;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        cin>>cost[i];
    int c1=-1,c2=-1;
    for(int i=1;i<=n;i++)
    {
        for(unsigned int k=0;k<adj[i].size();k++)
        {
            if(cost[adj[i][k]]!=cost[i])
            {
                c1=i;
                c2=adj[i][k];
                break;
            }
        }
        if(c1!=-1)
            break;
    }
    if(c1==-1)
        cout<<"YES"<<endl<<1;
    else
    {
        if(dfs(c1))
        {
            cout<<"YES"<<endl<<c1;
        }
        else
        {
            for(int i=1;i<=n;i++)
                vis[i]=false;
            check=0;
            if(dfs(c2))
            cout<<"YES"<<endl<<c2;
            else
            cout<<"NO";
        }
    }
    return 0;
}
