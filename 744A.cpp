#include<bits/stdc++.h>
using namespace std;
vector<int> head;
vector<int> a[1001];
int deg[1001]={0};
bool vis[1001]={false};
bool vis2[1001]={false};
int uy=0,ux=0;
void dfs(int s)
{
    vis[s]=true;
    ux++;
    uy+=deg[s];
    for(unsigned int j=0;j<a[s].size();j++)
    {
        if(!vis[a[s][i]])
        {
            dfs([a[s][i]]);
        }
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int x,y;
    int check=0;
    for(int i=0;i<k;i++)
    {
        cin>>x;
        head.push_back(x);
        if(!vis2[x])
        {
            vis2[x]=true;check++;
        }
    }
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
        deg[x]++;
        deg[y]++;
        if(!vis2[x])
        {
            vis2[x]=true;check++;
        }
        if(!vis2[y])
        {
            vis2[y]=true;check++;
        }
    }
    int free=n-check;
    int ans=0;
    for(int i=0;i<k;i++)
    {
        uy=0;ux=0;
        dfs(head[i]);
        int nodes=ux+free;
        int edg1=((nodes*(nodes-1))/2)-uy;
        ans+=edg1;
    }
    cout<<ans<<endl;
}
