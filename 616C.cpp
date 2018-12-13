#include<bits/stdc++.h>
using namespace std;
int vis[1001][1001];
vector<pair<int,int>> h;
int n,m;string s[1001];
void dfs(int x,int y,int id)
{
    vis[x][y]=id;
    h.push_back(make_pair(x,y));
    if(s[x-1][y]!='*' && vis[x-1][y]==-1 && x>0)
            {
                dfs(x-1,y,id);
            }
    if(s[x+1][y]!='*' && vis[x+1][y]==-1 && x+1<n)
            {
                dfs(x+1,y,id);
            }
    if(s[x][y-1]!='*' && vis[x][y-1]==-1 && y>0)
            {
                dfs(x,y-1,id);
            }
    if(s[x][y+1]!='*' && vis[x][y+1]==-1 && y+1<m)
            {
                dfs(x,y+1,id);
            }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
    int val[1001][1001]={0};
    int myc=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
          vis[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]!='*' && vis[i][j]==-1)
            {
                myc++;
                dfs(i,j,myc);
                int r1=h.size();
                for(int l=0;l<r1;l++)
                {
                    val[h[l].first][h[l].second]=r1;
                }
                h.clear();
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='.')
                cout<<".";
            else
            {
                long int s1=1;
                if(i>0)
                    s1+=val[i-1][j];
                if(j>0 && vis[i-1][j]!=vis[i][j-1])
                    s1+=val[i][j-1];
                if(i+1<n && vis[i+1][j]!=vis[i-1][j] && vis[i+1][j]!=vis[i][j-1])
                    s1+=val[i+1][j];
                if(j+1<m && vis[i][j+1]!=vis[i-1][j] && vis[i][j+1]!=vis[i][j-1] && vis[i][j+1]!=vis[i+1][j])
                    s1+=val[i][j+1];
                cout<<(s1%10);
            }
        }
        cout<<endl;
    }
    return 0;
}
