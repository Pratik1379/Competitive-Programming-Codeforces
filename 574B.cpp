#include<bits/stdc++.h>
using namespace std;
vector<int> a[10001];
vector<pair<int,int>> p;
int deg[10001]={0};
int main()
{
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        p.push_back(make_pair(u,v));
        deg[u]++;
        deg[v]++;
    }
    int s=1e6+7;
    for(int i=0;i<m;i++)
    {
        int l=p[i].first,k=p[i].second;
        for(unsigned int i=0;i<a[l].size();i++)
        {
            for(unsigned int j=0;j<a[k].size();j++)
            {
                if(a[k][j]==a[l][i] && a[k][j]!=l)
                {
                    int r=deg[a[k][j]]+deg[l]+deg[k]-6;
                    s=min(s,r);
                }
            }
        }
    }
    if(s==1e6+7)
        cout<<-1;
    else
        cout<<s;
    return 0;
}
