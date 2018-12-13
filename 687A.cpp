#include<bits/stdc++.h>
using namespace std;
vector<int> a[100001];
int color[100001]={0};
bool vis[100001]={false};
int fl=0;
void dfs(int s)
{
    vis[s]=true;
    for(unsigned int i=0;i<a[s].size();i++)
    {
        if(color[a[s][i]]==color[s] && color[s]!=0)
        {
            fl=1;return;
        }
        color[a[s][i]]=-1*color[s];
        if(!vis[a[s][i]] && a[a[s][i]].size()>0)
            dfs(a[s][i]);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v1,v2;
    int u,v;
    for(int i=0;i<n;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i] && a[i].size()>0)
        {
            color[i]=1;
            dfs(i);
            if(fl==1)
                break;
        }
    }
    if(fl==1)
        cout<<-1;
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(color[i]==1)
                v1.push_back(i);
            else if(color[i]==-1)
                v2.push_back(i);
        }
        int r1=v1.size();
        int r2=v2.size();
        cout<<r1;
        for(int i=0;i<r1;i++)
            cout<<v1[i]<<" ";
        cout<<endl;
        for(int i=0;i<r2;i++)
            cout<<v2[i]<<" ";
    }
    return 0;
}
