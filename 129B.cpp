#include<bits/stdc++.h>
using namespace std;
int deg[101]={0};
bool vis[101]={false};
vector<int> a[101];
void dfs(int s)
{
    for(unsigned int i=0;i<a[s].size();i++)
    {
        deg[a[s][i]]--;
    }
}
int main()
{
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        deg[u]++;deg[v]++;
    }
    int check=0;
    int pl=0;
    while(1)
    {
        pl++;
        vector<int> h;
        for(int i=1;i<=n;i++)
        {
            if(deg[i]==1)
            {
                check=1;
                h.push_back(i);
            }
        }
        if(check==0)
            break;
        for(unsigned int i=0;i<h.size();i++)
        {
            dfs(h[i]);
            deg[h[i]]=0;
        }
    }
    cout<<pl;
}
