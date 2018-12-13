#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[300001];
map<pair<int,int>,int> p;
long long int d[300001];
int par[300001];
bool vis[300001]={false};
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    long long int INF=1e15+7;
    for(int i=1;i<=n;i++)
    {
      par[i]=-1;
      d[i]=INF;
      vis[i]=false;
    }
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        adj[x].push_back(make_pair(y,w));
        adj[y].push_back(make_pair(x,w));
        if(x>y)
        {
            p.insert(make_pair(make_pair(y,x),i+1));
        }
        else
        {
            p.insert(make_pair(make_pair(x,y),i+1));
        }
    }
    if(k==0)
    {
      cout<<0;return 0;
    }
    if(k==m)
    {
      cout<<m<<endl;
      for(int i=1;i<=m;i++)
          cout<<i<<" ";
      return 0;
    }
    multiset<pair<long long int,int>> s;
    s.insert(make_pair(0,1));
    d[1]=0;
    vector<int> ans;
    int cnt=0;
    while(!s.empty())
    {
        pair<long long int,int> h=*s.begin();
        s.erase(s.begin());
        int v=h.second;
        if(vis[v])
          continue;
        vis[v]=true;
        if(v!=1)
        {
            int h=par[v];
            int te=v;
            if(te>h)
            {
                int ytemp=te;
                te=h;
                h=ytemp;
            }
            pair<int,int> o;
            o.first=te;
            o.second=h;
            int edge=p[o];
            ans.push_back(edge);
            cnt++;
            if(cnt==k)
                break;
        }
        for(int i=0;i<adj[v].size();i++)
        {
            if(!vis[adj[v][i].first])
            {
                if(d[adj[v][i].first]>h.first+adj[v][i].second)
                {
                    d[adj[v][i].first]=h.first+adj[v][i].second;
                    par[adj[v][i].first]=v;
                    s.insert(make_pair(d[adj[v][i].first],adj[v][i].first));
                }
            }
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        cout<<ans[i]<<" ";
    return 0;
}
