#include<bits/stdc++.h>
using namespace std;
string a[11];
int h,w;
bool vis[11][11][4]={false};
int cnt=0;
void dfs(int y,int z,int c)
{
    cout<<y<<" "<<z<<" "<<c<<endl;
    if(!vis[y][z][0] && !vis[y][z][1] && !vis[y][z][2] && !vis[y][z][3] )
    cnt++;
    vis[y][z][c]=true;
    if(c==0)
    {
        if(y>0 && a[y-1][z]!='*')
        {
            if(!vis[y-1][z][0])
            dfs(y-1,z,0);
            else
                return;
        }
        else if(z+1<w && a[y][z+1]!='*' )
        {
            if(!vis[y][z+1][1])
            dfs(y,z+1,1);
            else
                return;
        }
        else if(y+1<h && a[y+1][z]!='*')
        {
            if(!vis[y+1][z][2])
                 dfs(y+1,z,2);
            else
                return;
        }

        else if(z>0 && a[y][z-1]!='*'  )
        {
            if(!vis[y][z-1][3])
                dfs(y,z-1,3);
            else
                return;
        }

    }
    else if(c==1)
    {
        if(z+1<w && a[y][z+1]!='*' )
            {
            if(!vis[y][z+1][1])
            dfs(y,z+1,1);
            else
                return;
        }
        else if(y+1<h && a[y+1][z]!='*' )
            {
            if(!vis[y+1][z][2])
                 dfs(y+1,z,2);
            else
                return;
        }
        else if(z>0 && a[y][z-1]!='*')
            {
            if(!vis[y][z-1][3])
                dfs(y,z-1,3);
            else
                return;
        }
        else if(y>0 && a[y-1][z]!='*')
            {
            if(!vis[y-1][z][0])
            dfs(y-1,z,0);
            else
                return;
            }
    }
    else if(c==2)
    {
        if(y+1<h && a[y+1][z]!='*' && !vis[y+1][z][2])
            {
            if(!vis[y+1][z][2])
                 dfs(y+1,z,2);
            else
                return;
        }
        else if(z>0 && a[y][z-1]!='*' && !vis[y][z-1][3])
            {
            if(!vis[y][z-1][3])
                dfs(y,z-1,3);
            else
                return;
        }
        else if(y>0 && a[y-1][z]!='*' && !vis[y-1][z][0])
           {
            if(!vis[y-1][z][0])
            dfs(y-1,z,0);
            else
                return;
            }
        else if(z+1<w && a[y][z+1]!='*' && !vis[y][z+1][1] )
             {
            if(!vis[y][z+1][1])
            dfs(y,z+1,1);
            else
                return;
        }
    }
    else
    {
        if(z>0 && a[y][z-1]!='*' && !vis[y][z-1][3])
            {
            if(!vis[y][z-1][3])
                dfs(y,z-1,3);
            else
                return;
        }
        else if(y>0 && a[y-1][z]!='*' && !vis[y-1][z][0])
            {
            if(!vis[y-1][z][0])
            dfs(y-1,z,0);
            else
                return;
            }
        else if(z+1<w && a[y][z+1]!='*' && !vis[y][z+1][1])
             {
            if(!vis[y][z+1][1])
            dfs(y,z+1,1);
            else
                return;
        }
        else if(y+1<h && a[y+1][z]!='*' && !vis[y+1][z][2])
            {
            if(!vis[y+1][z][2])
                 dfs(y+1,z,2);
            else
                return;
        }
    }
}
int main()
{
    cin>>h>>w;
    for(int i=0;i<h;i++)
    {
        cin>>a[i];
    }
    int pos1,pos2;
    char x;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(a[i][j]!='*' && a[i][j]!='.')
            {
                pos1=i;pos2=j;x=a[i][j];break;
            }
        }
    }
    int k;
    if(x=='U')
        k=0;
    else if(x=='R')
        k=1;
    else if(x=='D')
        k=2;
    else k=3;
    dfs(pos1,pos2,k);
    cout<<cnt;
    return 0;
}
