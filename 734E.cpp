#include<bits/stdc++.h>
using namespace std;
int n;int black=0;int white=0;
int color[200001];
vector<int> a[200001];
bool vis[200001]={false};
void dfs(int s)
{
    vis[s]=true;
    for(int i=0;i<a[s].size();i++)
    {
        if(!vis[a[s][i]] && color[s]==color[a[s][i]])
        {
            dfs(a[s][i]);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>n;
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(color[i]==0)
                black++;
            else
                white++;
            dfs(i);
        }
    }
    cout<<min(black,white);
}
