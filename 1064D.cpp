#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,r,c,x,y;
    cin>>n>>m>>r>>c>>x>>y;

    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int left[n][m],right[n][m];
    bool vis[2001][2001]={false};
    queue<pair<int,int>> Q;
    r--;c--;
    left[r][c]=0;
    right[r][c]=0;
    int ans=1;
    if(s[r+1][c]=='.' && r+1<n)
    {Q.push(make_pair(r+1,c));
    left[r+1][c]=0;
    right[r+1][c]=0;
    vis[r+1][c]=true;
    ans++;
    }
    if(s[r-1][c]=='.' && r>0)
        {
            Q.push(make_pair(r-1,c));
            left[r-1][c]=0;
            right[r-1][c]=0;
            vis[r-1][c]=true;
            ans++;
        }
    if(x>0 && s[r][c-1]=='.' && c>0)
        {Q.push(make_pair(r,c-1));
        left[r][c-1]=1;
        right[r][c-1]=0;
        vis[r][c-1]=true;
        ans++;
        }
    if(y>0 && s[r][c+1]=='.' && c+1<m)
    {
        Q.push(make_pair(r,c+1));
        left[r][c+1]=0;
        right[r][c+1]=1;
        vis[r][c+1]=true;
        ans++;
    }
    while(!Q.empty())
    {
        pair<int,int> p=Q.front();
        Q.pop();
        int mx=p.first,my=p.second;
        if(mx+1<n && s[mx+1][my]=='.' &&(!vis[mx+1][my] || (left[mx+1][my]>left[mx][my])|| (right[mx+1][my]>right[mx][my])))
        {
            Q.push(make_pair(mx+1,my));
            left[mx+1][my]=left[mx][my];
            right[mx+1][my]=right[mx][my];
            if(!vis[mx+1][my])
            {vis[mx+1][my]=true;
            ans++;
            }
        }
        if(mx>0 && s[mx-1][my]=='.' &&(!vis[mx-1][my] || (left[mx-1][my]>left[mx][my])|| (right[mx-1][my]>right[mx][my])))
        {
            Q.push(make_pair(mx-1,my));
            left[mx-1][my]=left[mx][my];
            right[mx-1][my]=right[mx][my];
            if(!vis[mx-1][my])
            {vis[mx-1][my]=true;
            ans++;
            }
        }
        if(my+1<m && s[mx][my+1]=='.')
        {
            if(!vis[mx][my+1] && right[mx][my]+1<y)
            {
                    Q.push(make_pair(mx,my+1));
                    left[mx][my+1]=left[mx][my];
                    right[mx][my+1]=right[mx][my]+1;
                    vis[mx][my+1]=true;
                    ans++;
            }
            else if((right[mx][my+1]>(right[mx][my]+1)) || left[mx][my+1]>left[mx][my])
            {
                    Q.push(make_pair(mx,my+1));
                    left[mx][my+1]=left[mx][my];
                    right[mx][my+1]=right[mx][my]+1;
            }
        }
        if(my>0 && s[mx][my-1]=='.')
        {
                if(!vis[mx][my-1] && left[mx][my]+1<x)
                {
                    Q.push(make_pair(mx,my-1));
                    left[mx][my-1]=left[mx][my]+1;
                    right[mx][my-1]=right[mx][my];
                    vis[mx][my-1]=true;
                    ans++;
                }
            else if((right[mx][my-1]>right[mx][my]) || left[mx][my-1]>(left[mx][my]+1))
            {
                    Q.push(make_pair(mx,my-1));
                    left[mx][my-1]=left[mx][my]+1;
                    right[mx][my-1]=right[mx][my];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
