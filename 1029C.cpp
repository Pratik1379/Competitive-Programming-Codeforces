#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long int x,y;
    vector<pair<long int,int>> v,f;
    vector<pair<long int,long int> h;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        h.push_back(make_pair(x,y));
        v.push_back(make_pair(x,i));
        f.push_back(make_pair(y,i));
    }
    sort(v.begin(),v.end());
    sort(f.begin(),f.end());
    long int ans=0,maxi=0;
    for(int i=0;i<n;i++)
    {
        int p1=v[n-1].second;
        if(p1==i)
            p1=v[n-2].second;
        int p2=f[0].second;
        if(p2==i)
            p2=f[1].second;
        if(h[p1].first<=h[p2].second)
        {
            maxi=h[p2].second-h[p1].first+1;
            ans=max(ans,maxi);
        }
    }
    cout<<ans<<endl;
    return 0;
}
