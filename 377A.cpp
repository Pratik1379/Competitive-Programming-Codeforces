#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> p;
int n,m,k,fl;
string arr[501];
string br[501];
bool vis[501][501]={false};
int y;
int s=0;
void dfs(int i,int j)
{
    vis[i][j]=true;
    if(i+1<n && arr[i+1][j]=='.' && !vis[i+1][j])
    {
        p.push_back(make_pair(i+1,j));
        dfs(i+1,j);
        s++;
        if(s==y)
            return ;
    }
    if(j+1<m && arr[i][j+1]=='.' && !vis[i][j+1])
    {
        p.push_back(make_pair(i,j+1));
        dfs(i,j+1);
        s++;
        if(s==y)
            return ;
    }
    if(i>0 && arr[i-1][j]=='.' && !vis[i-1][j])
    {
        p.push_back(make_pair(i-1,j));
        dfs(i-1,j);
        s++;
        if(s==y)
            return ;
    }
    if(j>0 && arr[i][j-1]=='.' && !vis[i][j-1])
    {
        p.push_back(make_pair(i,j-1));
        dfs(i,j-1);
        s++;
        if(s==y)
            return ;
    }
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int check=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='#')
                br[i][j]='#';
            else
            {
                br[i][j]='X';
                check++;
            }
        }
    }
    y=check-k;
    fl=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='.')
            {
                s=0;
                p.push_back(make_pair(i,j));
                s++;
                if(s==y)
                {
                    fl=1;break;
                }
                dfs(i,j);
                if(s==y)
                {
                    fl=1;break;
                }
            }
        }
        if(fl)
            break;
    }
    for(int i=0;i<y;i++)
    {
        br[p[i].first][p[i].second]='.';
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cout<<br[i][j];
        cout<<endl;
    }
    return 0;
}
