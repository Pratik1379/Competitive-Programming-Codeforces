#include<bits/stdc++.h>
using namespace std;
int out[200001],in[200001];
vector<int> a[200001];
int t=0;
bool vis[200001]={false};
vector<int> p;
void dfs(int s)
{
    vis[s]=true;
    p.push_back(s);
    t++;
    in[s]=t;
    for(unsigned int i=0;i<a[s].size();i++)
    {
        if(!vis[a[s][i]])
            dfs(a[s][i]);
    }
    t++;
    out[s]=t;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    int par;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&par);
        a[par].push_back(i);
    }
    dfs(1);
    map<int,int> l;
    for(int i=0;i<n;i++)
    {
        l.insert(make_pair(p[i],i));
    }
    int u,k;
    while(q--)
    {
        scanf("%d%d",&u,&k);
        int ind=l.at(u);
        int j=ind+k-1;
        int fl=0;
        if(j<n)
        {
           int my=p[j];
           if(out[u]>=out[my] && in[u]<=in[my])
           {
               fl=1;printf("%d\n",my);
           }
        }
        if(fl==0)
        {
            printf("-1\n");
        }
    }
    return 0;
}
