#include<bits/stdc++.h>
using namespace std;
int lcs(int x,int y)
{
    int r=__gcd(x,y);
    int u=(x*y)/r;
    return u;
}
int a[101];bool vis[101]={false};
int fl=0;
int start;
int des;
int cnt=0;
int maxi=0;
void dfs(int s)
{
    vis[s]=true;
    if(s==start)
        {
            des=s;return;
        }
    cnt++;
    des=s;
    if(!vis[a[s]])
    dfs(a[s]);
    else if(a[s]==start)
    dfs(a[s]);
}
int main()
{
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            start=i;
            cnt=1;
            dfs(a[i]);
            if(des!=start)
            {
                fl=1;break;
            }
            if(cnt&1)
            maxi=lcs(cnt,maxi);
            else
            maxi=lcs(cnt/2,maxi);
        }
    }
    if(fl==1)
        cout<<-1;
    else
    {
            cout<<maxi;
    }
}
