#include<bits/stdc++.h>
using namespace std;
bool vis[1001]={false};
bool cmp(const pair<int,pair<int,int>> &a,  pair<int,pair<int,int>> &b)
{
    if(a.first==b.first)
    {
        return (a.second.first>b.second.first);
    }
    return (a.first<b.first);
}
int main()
{
    int n,x,y,k;
    cin>>n;
    vector<pair<int,pair<int,int>>> v;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,make_pair(y,i)));
    }
    sort(v.begin(),v.end(),cmp);
    cin>>k;
    int sum=0;
    vector<pair<int,int>>h;
    vector<pair<int,int>>a;
    for(int i=0;i<k;i++)
        {cin>>x;
        a.push_back(make_pair(x,i));
        }
    sort(a.begin(),a.end());
    for(int i=0;i<k;i++)
    {
        int maxi=-1,pos=-1;
        for(int j=0;j<n;j++)
        {
            if(v[j].first<=a[i].first && !vis[v[j].second.second])
            {
                if(maxi<v[j].second.first)
                {
                    maxi=v[j].second.first;
                    pos=v[j].second.second;
                }
            }
        }
        if(maxi!=-1)
        {
            sum+=maxi;
            vis[pos]=true;
            h.push_back(make_pair(pos+1,a[i].second+1));
        }
    }
    int r1=h.size();
    cout<<r1<<" "<<sum<<endl;
    for(int i=0;i<r1;i++)
    {
        cout<<h[i].first<<" "<<h[i].second<<endl;
    }
}
