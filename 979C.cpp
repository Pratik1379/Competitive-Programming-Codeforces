#include<bits/stdc++.h>
using namespace std;
long int n;
int x,y;
bool vis[300001]={false};
bool vis2[300001]={false};
vector<int> a[300001];
long int cnt=0,cnt2=0;
void dfs(int s)
{
    vis[s]=true;
    cnt++;
    for(unsigned int i=0;i<a[s].size();i++)
    {
        if(a[s][i]!=y && !vis[a[s][i]])
            dfs(a[s][i]);
    }
}
void dfs2(int s)
{
    vis2[s]=true;
    cnt2++;
    for(unsigned int i=0;i<a[s].size();i++)
    {
        if(a[s][i]!=x && !vis2[a[s][i]])
            dfs2(a[s][i]);
    }
}
int main()
{
    cin>>n>>x>>y;
    int u,v;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(x);
    dfs2(y);
    long int sui=(n*(n-1))/2+(cnt*(cnt-1))/2+(cnt2*(cnt2-1))/2;
    cout<<sui;
    return 0;
}
