#include<bits/stdc++.h>
using namespace std;
vector<int> a[101];vector<int> c[101];
vector<pair<int,int>> b;
vector<pair<int,int>> add,rem;
bool vis[101]={false};
bool vis2[101]={false};
int n,l;
int endo;
int id[101]={0};
int endi[101]={0};
void dfs(int s)
{
    vis[s]=true;
    endo=s;
    for(unsigned int i=0;i<a[s].size();i++)
    {
        if(!vis[a[s][i]])
        {
            dfs(a[s][i]);
            check[s][a[s][i]]=true;
            check[a[s][i]][s]=true;
        }

    }
}
bool check[101][101]={false};
void dfs2(int s)
{
    vis2[s]=true;
    c[l].push_back(s);
    for(unsigned int i=0;i<a[s].size();i++)
    {
        if(!vis2[a[s][i]])
        {
            dfs(a[s][i]);
        }
    }
}
int main()
{
    cin>>n;
    int u,v;
    l=0;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        b.push_back(make_pair(u,v));
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis2[i])
        {
            l++;
            dfs2(i);
        }
    }
    if(l==1)
    {
        cout<<0;
    }
    else
    {
        for(int i=1;i<=l;i++)
        {
            endo=-1;
            dfs(c[i][0]);
            endi[i]=endo;
        }
        for(int i=0;i<n-1;i++)
        {
            if(!check[b[i].first][b[i].second])
            {
                rem.push_back(make_pair(b[i].first,b[i].second));
            }
        }
        for(int i=1;i<l;i++)
        {
            add.push_back(make_pair(endi[i],c[i+1][0]));
        }
        cout<<l-1<<endl;
        for(int i=0;i<l-1;i++)
        {
            cout<<rem[i].first<<" "<<rem[i].second<<" "<<add[i].first<<" "<<add[i].second<<" ";
            cout<<endl;
        }
    }
    return 0;
}
