#include<bits/stdc++.h>
using namespace std;
int cycle=0;
vector<int> a[300001];
int b[300001][26];
int vis[300001]={0};
int deg[300001]={0};
int parent[300001];
queue<int> myq;
string st;
void dfs(int s)
{
    if(cycle==1)
        return;
    vis[s]=1;
    for(unsigned int i=0;i<a[s].size();i++)
    {
        deg[a[s][i]]--;
        if(deg[a[s][i]]==0)
            myq.push(a[s][i]);
        for(int l=0;l<26;l++)
            {
                if(l==(st[a[s][i]-1]-97))
                b[a[s][i]][l]=max(b[s][l]+1,b[a[s][i]][l]);
                else
                b[a[s][i]][l]=max(b[s][l],b[a[s][i]][l]);
            }
        if(vis[a[s][i]]==1 && cycle==0)
        {
            cycle=1;return;
        }
        if(vis[a[s][i]]==0 && cycle==0)
        {
            parent[a[s][i]]=s;
            dfs(a[s][i]);
        }
    }
    vis[s]=2;
}
int main()
{
    int n,q,x,y;
    cin>>n>>q;
    cin>>st;
    for(int i=1;i<=n;i++)
    {
      vis[i]=0;
      deg[i]=0;
      for(int j=0;j<26;j++)
      {
        b[i][j]=0;
      }
    }
    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        deg[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==0)
            myq.push(i);
    }
        while(!myq.empty())
        {
            int i=myq.front();
            myq.pop();
            if(vis[i]==0)
            {
            parent[i]=-1;
            b[i][st[i-1]-97]++;
            dfs(i);
            if(cycle==1)
            {
                break;
            }
            }
        }
        if(cycle==0)
        {
        for(int i=1;i<=n;i++)
     {
        if(vis[i]==0)
        {
            parent[i]=-1;
            b[i][st[i-1]-97]++;
            dfs(i);
            if(cycle==1)
            {
                break;
            }
        }
      }
        }
    if(cycle==1)
    {
        cout<<-1;return 0;
    }
    int maxi=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++)
        {
          //cout<<b[i][j]<<" ";
            maxi=max(maxi,b[i][j]);
        }
        //cout<<endl;
    }
    cout<<maxi<<endl;
}
