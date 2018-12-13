#include<bits/stdc++.h>
using namespace std;
vector<int> v[100000];
int main()
{
    int n;
    long int x;
    cin>>n;
    vector<pair<long int,int>> a;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(make_pair(x,i));
    }
    int l=0;
    sort(a.begin(),a.end());
    int b[n+1];
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i].second;
    }
    bool vis[100001]={false};
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            v[l].push_back(i);
            vis[i]=true;
            int j=b[i];
            while(!vis[j])
            {
                vis[j]=true;
                v[l].push_back(j);
                j=b[j];
            }
            l++;
        }
    }
    cout<<l<<endl;
    for(int i=0;i<l;i++)
    {
        int r1=v[i].size();
        cout<<r1<<" ";
        for(int j=0;j<r1;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
