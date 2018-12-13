#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long int x[n],y[n];
    vector<pair<long int,int>> v;
    for(int i=0;i<n;i++)
        {cin>>x[i]>>y[i];
        v.push_back(make_pair(x[i]+y[i],i));
        }
    sort(v.begin(),v.end());
    int j=0;
    int ans=1;
    for(int i=1;i<n;i++)
    {
        if((x[v[i].second]-x[v[j].second])>=(y[v[i].second]+y[v[j].second]))
            {j=i;ans++;}
    }
    cout<<ans;
    return 0;
}
