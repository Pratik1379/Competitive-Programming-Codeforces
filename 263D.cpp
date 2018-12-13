#include<bits/stdc++.h>
using namespace std;
vector<int> h;
bool vis[100001]={false};
int parent[100001];
int fl=0;
int n,m,k;
void dfs(int s)
{
    vis[s]=true;
    if(fl==1)
        return;
    for(unsigned int i=0;i<a[s].size();i++)
    {
        if(!vis[a[s][i]])
        {
            parent[a[s][i]]=s;
            dfs(a[s][i]);
        }
        else if(parent[s]!=a[s][i] && fl==0)
        {
            cycle[s]=true;
            int y=s;
            while(y!=a[s][i])
            {
               h.push_back(y);
               y=parent[y];
            }
            cycle[a[s][i]]=true;
            h.push_back(a[s][i]);
            if(h.size()>k)
            {fl=1;
            return;
            }
            else
            {
                h.clear();
            }
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    int x,y;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    parent[1]=-1;
    dfs(1);
    int r1=h.size();
    cout<<r1<<endl;
    for(int i=0;i<r1;i++)
    {
        cout<<h[i]<<" ";
    }
}
