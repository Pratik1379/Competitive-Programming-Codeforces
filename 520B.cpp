#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    bool vis[10001]={false};
    int level[10001];
    queue<int> Q;
    Q.push(n);
    level[n]=0;
    vis[n]=true;
    while(!Q.empty())
    {
        int p=Q.front();
        Q.pop();
        if((2*p)<=10000 && !vis[2*p])
        {
            Q.push(2*p);
            level[2*p]=level[p]+1;
            vis[2*p]=true;
        }
        if(p>0 && !vis[p-1])
        {
            Q.push(p-1);
            level[p-1]=level[p]+1;
            vis[p-1]=true;
        }
        if(vis[m])
            break;
    }
    cout<<level[m];
    return 0;
}
