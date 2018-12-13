#include<bits/stdc++.h>
using namespace std;
vector<int> a[100001];
bool vis[100001]={false};
bool change[100001]={false};
int n;
int in[100001],out[100001];
vector<int> b;
int cnt=0;
vector<int> h;
void dfs(int s)
{
    vis[s]=true;
    for(unsigned int i=0;i<a[s].size();i++)
    {
        if(!vis[a[s][i]])
        {
            parent[a[s][i]]=s;
            dfs(a[s][i]);
        }
    }
}
void bfs(int s)
{
    queue<int> Q;
    Q.push(s);
    vis[s]=true;
    while(!Q.empty())
    {
        int p=Q.front();
        b.push_back(p);
        Q.pop();
        for(unsigned int i=0;i<a[s].size();i++)
        {
            if(!vis[a[s][i]])
            {
                vis[a[s][i]]=true;
                Q.push(a[s][i]);
            }
        }
    }
}
int main()
{
    int u,v;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        cin>>in[i];
    for(int i=1;i<=n;i++)
        cin>>out[i];
    parent[1]=-1;
    dfs(1);
    for(int i=1;i<=n;i++)
        vis[i]=false;
    bfs(1);
    if(in[1]!=out[1])
    {
        cnt++;
        change[1]=true;
        h.push_back(1);
    }
    for(int i=0;i<n-1;i++)
    {
        int j=parent[b[i]];
        int u=0;
        while(j!=-1)
        {
            if(change[j])
                u++;
            j=parent[j];
        }
        if(u&1 && in[b[i]]==out[b[i]])
        {
            change[b[i]]=true;
            h.push_back(b[i]);
            cnt++;
        }
        if(u%2==0 && in[b[i]]!=out[b[i]])
        {
            change[b[i]]=true;
            h.push_back(b[i]);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        cout<<h[i]<<endl;
    return 0;
}
