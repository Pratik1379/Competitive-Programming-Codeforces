#include<bits/stdc++.h>
using namespace std;
bool vis[1001][1001][5]={false};
bool pres[1001][1001]={false};
vector<pair<int,int>> v;
void dfs(int f,int g,int h)
{
    if(vis[f][g][h])
        return;
    vis[f][g][h]=true;
    if(h==1)
    {
        if(g<1000)
        {
            if(pres[f][g+1])
            {
                dfs(f,g+1,1);dfs(f,g+1,2);dfs(f,g+1,3);dfs(f,g+1,4);
            }
            else
            dfs(f,g+1,1);
        }
    }
    else if(h==2)
    {
        if(f<1000)
        {
            if(pres[f+1][g])
            {
                dfs(f+1,g,1);dfs(f+1,g,2);dfs(f+1,g,3);dfs(f+1,g,4);
            }
            else
            dfs(f+1,g,2);
        }
    }
    else if(h==3)
    {
        if(g>0)
        {
            if(pres[f][g-1])
            {
                dfs(f,g-1,1);dfs(f,g-1,2);dfs(f,g-1,3);dfs(f,g-1,4);
            }
            else
                dfs(f,g-1,3);
        }
    }
    else
    {
        if(f>0)
        {
            if(pres[f-1][g])
            {
                dfs(f-1,g,1);dfs(f-1,g,2);dfs(f-1,g,3);dfs(f-1,g,4);
            }
            else
                dfs(f-1,g,4);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int ans=0;
    int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        pres[x][y]=true;
        v.push_back(make_pair(x,y));
    }
    for(int i=0;i<n;i++)
    {
        x=v[i].first;y=v[i].second;
        if(!vis[x][y][1])
        {
            ans++;
            dfs(x,y,1);dfs(x,y,2);dfs(x,y,3);dfs(x,y,4);
        }
    }
    ans--;
    cout<<ans;
}
