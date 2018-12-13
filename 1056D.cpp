#include<bits/stdc++.h>
using namespace std;
bool leaf[100001]={false};
int a[100001]={0};
vector<int> v[100001];
int main()
{
    int n,x;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        v[x].push_back(i);
        leaf[i]=true;
    }
    for(int i=1;i<=n;i++)
    {
        if(!leaf[i])
            a[i]=1;
    }
    for(int i=n-1;i>=1;i--)
    {
        if(leaf[i])
        {
            int h=v[i].size();
            for(int j=0;j<h;j++)
            {
                a[i]+=a[v[i][j]];
            }
        }
    }
    vector<int> m;
    for(int i=1;i<=n;i++)
    {
        m.push_back(a[i]);
    }
    sort(m.begin(),m.end());
    for(int i=0;i<n;i++)
        cout<<m[i]<<" ";
    return 0;
}
