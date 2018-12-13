#include<bits/stdc++.h>
using namespace std;
vector<int> a[200001];
int par[200001];
bool vis[200001]={false};
bool check[200001]={false};
int level[200001];
multiset<pair<int,int>,greater<pair<int,int>>> m;
int
void dfs(int s,int p,int x)
{
    par[s]=p;
    vis[s]=true;
    level[s]=x;
    if(x>2)
    {
        m.insert(make_pair(x,s));
    }
    for(unsigned int i=0;i<a[s].size();i++)
    {
        if(!vis[a[s][i]])
        {
            dfs(a[s][i],s,x+1);
        }
    }
}
int main()
{
    int n,x,y;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,-1,0);
    int cnt=0;
    while(!m.empty())
    {
        pair<int,int> p=*m.begin();
        cnt++;
        int parent=par[p.second];
        if(level[parent]>2 && !check[parent])
        {
            check[parent]=true;
            pair<int,int> myp;
            myp.first=level[parent];
            myp.second=parent;
            m.erase(myp);
        }
        for(unsigned int i=0;i<a[parent].size();i++)
        {
            int x=level[a[parent][i]];
            if(x>2 && !check[a[parent][i]])
            {
                check[a[parent][i]]=true;
                pair<int,int> myp;
                myp.first=level[a[parent][i]];
                myp.second=a[parent][i];
                m.erase(myp);
            }
        }
    }
    cout<<cnt<<endl;
}
