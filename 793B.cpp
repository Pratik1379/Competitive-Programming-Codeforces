#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[1001];
int sx,sy,dx,dy;
bool vis[1000][1000][5]={false};
void dfs(int x,int y,int turn,int dir)
{
    vis[x][y][dir]=true;
    if(dir==1)
    {
        if(turn<2)
        {
            if(y+1<m && !vis[x][y+1][2] && s[x][y+1]!='*' && s[x][y+1]!='S' )
                dfs(x,y+1,turn+1,2);
            if(y>0 && !vis[x][y-1][3] && s[x][y-1]!='*' && s[x][y-1]!='S')
                dfs(x,y-1,turn+1,3);
        }
         if(x+1<n && !vis[x+1][y][1] && s[x+1][y]!='*'  && s[x+1][y]!='S')
                dfs(x+1,y,turn,1);
    }
    else if(dir==2)
    {
        if(turn<2)
        {
            if(x+1<n && !vis[x+1][y][1] && s[x+1][y]!='*' && s[x+1][y]!='S')
                dfs(x+1,y,turn+1,1);
            if(x>0 && !vis[x-1][y][4] && s[x+1][y]!='*'  && s[x+1][y]!='S')
                dfs(x-1,y,turn+1,4);
        }
         if(y+1<m && !vis[x][y+1][2] && s[x][y+1]!='*' && s[x][y+1]!='S')
            dfs(x,y+1,turn,2);
    }
    else if(dir==3)
    {
            if(turn<2)
            {
            if(x+1<n && !vis[x+1][y][1] && s[x+1][y]!='*'  && s[x+1][y]!='S')
                dfs(x+1,y,turn+1,1);
            if(x>0 && !vis[x-1][y][4] && s[x+1][y]!='*'  && s[x+1][y]!='S')
                dfs(x-1,y,turn+1,4);
            }
            if(y>0 && !vis[x][y-1][3] && s[x][y-1]!='*'  && s[x][y-1]!='S')
            dfs(x,y-1,turn,3);
    }
    else
    {
        if(turn<2)
        {
            if(y+1<m && !vis[x][y+1][2] && s[x][y+1]!='*' && s[x][y+1]!='S')
                dfs(x,y+1,turn+1,2);
            if(y>0 && !vis[x][y-1][3] && s[x][y-1]!='*' && s[x][y-1]!='S')
                dfs(x,y-1,turn+1,3);
        }
         if(x>0 && !vis[x-1][y][4] && s[x-1][y]!='*' && s[x-1][y]!='S' )
                dfs(x-1,y,turn,4);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='S')
            {
                sx=i;sy=j;
            }
            else if(s[i][j]=='T')
            {
                dx=i;dy=j;
            }
        }
    }
    if(sx+1<n && s[sx+1][sy]!='*')
    {
        dfs(sx+1,sy,0,1);
    }
    if(vis[dx][dy][1]||vis[dx][dy][2]||vis[dx][dy][3]||vis[dx][dy][4])
    {
        cout<<"YES";return 0;
    }
    for(int i=0;i<n;i++)
        {
        for(int j=0;j<m;j++)
            {
                vis[i][j][1]=false;
                vis[i][j][2]=false;
                vis[i][j][3]=false;
                vis[i][j][4]=false;
            }
        }
    if(sy+1<m && s[sx][sy+1]!='*')
     {
         dfs(sx,sy+1,0,2);
     }
    if(vis[dx][dy][1]||vis[dx][dy][2]||vis[dx][dy][3]||vis[dx][dy][4])
    {
        cout<<"YES";return 0;
    }
    for(int i=0;i<n;i++)
        {
        for(int j=0;j<m;j++)
            {
                vis[i][j][1]=false;
                vis[i][j][2]=false;
                vis[i][j][3]=false;
                vis[i][j][4]=false;
            }
        }
    if(sy>0 && s[sx][sy-1]!='*')
       {
       dfs(sx,sy-1,0,3);}
    if(vis[dx][dy][1]||vis[dx][dy][2]||vis[dx][dy][3]||vis[dx][dy][4])
    {
        cout<<"YES";return 0;
    }
    for(int i=0;i<n;i++)
        {
        for(int j=0;j<m;j++)
            {
                vis[i][j][1]=false;
                vis[i][j][2]=false;
                vis[i][j][3]=false;
                vis[i][j][4]=false;
            }
        }
    if(sx>0 && s[sx-1][sy]!='*')
        dfs(sx-1,sy,0,4);
    if(vis[dx][dy][1]||vis[dx][dy][2]||vis[dx][dy][3]||vis[dx][dy][4])
    {
        cout<<"YES";return 0;
    }
    cout<<"NO";
    return 0;
}
