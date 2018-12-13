#include<bits/stdc++.h>
using namespace std;
bool cmp(long long int a,long long int b)
{
  return b<a;
}
int main()
{
    int n,m;
    cin>>n>>m;
    set<unsigned int> s;
    vector<long long int> a[m+1];
    for(int i=0;i<n;i++)
    {
        unsigned int x;long long int r;
        cin>>x>>r;
        a[x].push_back(r);
    }
    for(unsigned int i=1;i<=m;i++)
    {
        if(a[i].size()>0)
          {
              s.insert(i);
              sort(a[i].begin(),a[i].end(),cmp);
          }
    }
    for(int i=1;i<=m;i++)
    {
        int r1=a[i].size();
        for(int j=1;j<r1;j++)
        {
            a[i][j]=a[i][j]+a[i][j-1];
        }
    }
    int l=0;
    long long int ans=0,sum=0;
    set<unsigned int>::iterator it;
    while(!s.empty())
    {
        for(it=s.begin();it!=s.end();++it)
        {
           if(a[*it].size()==l)
           {
               sum-=a[*it][l-1];
               s.erase(it);
           }
           else
           {
               if(l>0)
               sum-=a[*it][l-1];
               sum+=a[*it][l];
           }
        }
        ans=max(ans,sum);
        l++;
    }
    cout<<ans<<endl;
}
