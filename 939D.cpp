#include<bits/stdc++.h>
using namespace std;
vector<int> a[26];
int fl=0;
bool vis[26]={false};
vector<pair<int,int>> h;
void dfs(int s)
{
    vis[s]=true;
    for(unsigned int i=0;i<a[s].size();i++)
    {
        if(!vis(a[s][i])
           {h.push_back(make_pair(s,a[s][i]);dfs(a[s][i]);}
    }
}
int main()
{
    int n;
    string s,r;
    cin>>n;
    cin>>s>>r;
    for(int i=0;i<n;i++)
    {
        int p1=s[i]-97;
        int p2=r[i]-97;
        if(p1!=p2)
        {
            a[p1].push_back(p2);
            a[p2].push_back(p1);
        }
    }
    for(int i=0;i<26;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    int s1=h.size();
    cout<<s1<<endl;
    for(int i=0;i<s1;i++)
    {
        cout<<h[i].first<<" "<<h[i].second<<endl;
    }
}
