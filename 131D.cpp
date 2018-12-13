#include<bits/stdc++.h>
using namespace std;
vector<int> a[3001];
bool cycle[3001]={false};
bool vis[3001]={false};
int level[3001];
int parent[3001];
int fl=0;
void dfs(int s)
{
    vis[s]=true;
    if(fl==1)
        return;
    //cout<<s<<endl;

    for(unsigned int i=0;i<a[s].size();i++)
    {
        if(!vis[a[s][i]])
        {
            parent[a[s][i]]=s;
            dfs(a[s][i]);
        }
        else if(parent[s]!=a[s][i] && fl==0)
        {
            //cout<<s<<" "<<a[s][i]<<endl;
            cycle[s]=true;
            int y=s;
            while(y!=a[s][i])
            {
               cycle[y]=true;
               y=parent[y];
            }
            cycle[a[s][i]]=true;
            fl=1;
            return;
        }
    }

}
void dfs2(int s,int lev)
{
level[s]=lev;
vis[s]=true;
for(unsigned int i=0;i<a[s].size();i++)
{
    if(!vis[a[s][i]] && !cycle[a[s][i]])
    {
    dfs2(a[s][i],lev+1);
    }
}
}
int main()
{
    int n,u,v;
    cin>>n;
    int deg[3001]={0};
    for(int i=0;i<n;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        deg[u]++;
        deg[v]++;
        a[v].push_back(u);
        level[i+1]=-1;
        parent[i+1]=-1;
    }
    parent[1]=-1;
    dfs(1);
    /*for(int i=1;i<=n;i++)
    {
      if(cycle[i])
        cout<<i<<" ** ";
    }*/
    for(int i=1;i<=n;i++)
        vis[i]=false;
    for(int i=1;i<=n;i++)
    {
        if(cycle[i])
        {
            dfs2(i,0);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<level[i]<<" ";
}
