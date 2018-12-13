#include<bits/stdc++.h>
using namespace std;
bool perf[100]={false};
bool vis[100]={false};
vector<int> a[100];
vector<pair<pair<int,int>,int>> v;
vector<int> l;
int h[3];
int cnt=0;
int fl=0;
void dfs(int s)
{
    h[cnt]=s;
    cnt++;
    if(cnt>2)
    {
        fl=1;return;
    }
    for(unsigned int i=0;i<a[s].size();i++)
    {
        if(!vis[a[s][i]])
            dfs(a[s][i]);
        if(fl==1)
            return;
    }
}
int main()
{
    int n,m,u,vl;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        a[u].push_back(vl);
        a[vl].push_back(u);
        perf[u]=true;perf[vl]=true;
    }
    for(int i=1;i<=n;i++)
    {
        if(!perf[i])
        {
            l.push_back(i);
        }
    }
    int r1=l.size();
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cnt=0;
            dfs(i);
            if(fl==1)
                break;
            if(cnt==1)
            {
                if(r1>=k+2)
                {
                pair<pair<int,int>,int> kli;
                kli.first.first=h[0];
                kli.first.second=l[k];
                kli.second=l[k+1];
                vis[l[k]]=true;
                vis[l[k+1]]=true;
                k=k+2;
                v.push_back(kli);
                }
                else
                {
                    fl=1;break;
                }
            }
            else if(cnt==2)
            {
                if(r1>=k+1)
                {
                pair<pair<int,int>,int> kli;
                kli.first.first=h[0];
                kli.first.second=h[1];
                kli.second=l[k];
                vis[l[k]]=true;
                k=k+1;
                v.push_back(kli);
                }
                else
                {
                    fl=1;break;
                }
            }
            else
            {
                pair<pair<int,int>,int> kli;
                kli.first.first=h[0];
                kli.first.second=h[1];
                kli.second=h[2];
                v.push_back(kli);
            }
        }
    }
    if(fl==1)
        cout<<-1;
    else
    {
        int r3=v.size();
        cout<<r3<<endl;
        for(int i=0;i<r3;i++)
        {
            cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second<<endl;
        }
    }
}
