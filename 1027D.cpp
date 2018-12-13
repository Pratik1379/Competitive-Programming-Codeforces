#include<bits/stdc++.h>
using namespace std;
bool vis[200001]={false};
bool vis2[200001]={false};
int mini=1e5+5;
long int sum=0;
vector<int> h;
int c[200001],a[200001];
vector<int> b[200001];
int fl=0;
void dfs2(int x)
{
    vis[x]=true;
    for(unsigned int i=0;i<b[x].size();i++)
    if(!vis[b[x][i]])
        dfs2(b[x]);
}
void cycle(int x)
{
    vis2[x]=true;
    h.push_back(x);
    if(!vis2[a[x]])
        cycle(a[x]);
}
void dfs(int x)
{
    vis[x]=true;
    if(vis2[a[x]])
        {
            vis2[x]=true;
            fl=1;return;
        }
    if(!vis[a[x]])
        dfs(a[x]);
    else
        cycle(a[x]);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
       {
           cin>>c[i];
           b[i]=0;
       }
    for(int i=1;i<=n;i++)
       {
           cin>>a[i];
           b[a[i]].push_back(i);
       }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            fl=0;
            mini=1e5+5;
            h.clear();
            dfs(i);
            int u=h.size();
            if(fl==0)
            {
            for(int j=0;j<u;j++)
                {mini=min(mini,c[h[j]]);
                dfs2(h[j]);
                }
            sum+=mini;
            }
        }
    }
    cout<<sum<<endl;
}
