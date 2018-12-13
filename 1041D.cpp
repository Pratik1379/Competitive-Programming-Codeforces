#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;long int h;
    cin>>n>>h;
    vector<pair<long int,long int>> v;
    long int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    long int dif=0;
    long int ans=0;
    int pos;
    for(int i=1;i<n;i++)
    {
        if(dif+(v[i].first-v[i-1].second)<h)
        {
            dif+=v[i].first-v[i-1].second;
        }
        else if(dif+(v[i].first-v[i-1].second)==h)
        {
            dif=h;
            pos=i;
            ans=(v[i].second-v[0].first);
            break;
        }
        else
        {
            pos=i-1;
            ans=(v[i-1].second-v[0].first)+h-dif;
            break;
        }
    }
    for(int i=1;i<n;i++)
    {
        dif=dif-(v[i].first-v[i-1].second);
        while(dif+(v[pos+1].first-v[pos].second)<=h && pos<n)
        {
            pos++;
            dif+=v[pos+1].first-v[pos].second;
        }
        ans=max(ans,v[pos].second-v[i].first+h-dif);
    }
    cout<<ans;
    return 0;
}

