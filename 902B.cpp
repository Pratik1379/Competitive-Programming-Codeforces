#include<bits/stdc++.h>
using namespace std;
vector<int> a[10001];
int val[10001];
int cnt=1;
bool vis[10001]={false};
void dfs(int s,int col)
{
    vis[s]=true;
    for(unsigned int i=0;i<a[s].size();i++)
    {
        if(!vis[a[s][i]])
        {
            if(col!=val[a[s][i]])
                cnt++;
            dfs(a[s][i],val[a[s][i]]);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int x;
    for(int i=1;i<n;i++)
    {
        cin>>x;
        a[i].push_back(x);
    }
    for(int i=1;i<=n;i++)
        cin>>val[i];
    dfs(1,val[1]);
    cout<<cnt;
}
