#include<bits/stdc++.h>
using namespace std;
bool comp(const pair<int,pair<int,int>> &a,const pair<int,pair<int,int>> &b)
{
    if(a.first == b.first)
        return (a.second.first < b.second.first);
    return (a.first > b.first);
}
int main()
{
    int n;long int t;
    int x,y;
    cin>>n>>t;
    vector<pair<int,int>> v;
    vector<pair<int,pair<int,int>>> h;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
        h.push_back(make_pair(x,make_pair(y,i)));
    }
    sort(h.begin(),h.end(),comp);
    set<int> f;
    multiset<pair<int,int> , greater<pair<int,int>>> p;
    int i=0;
    long int tim=0;
    int ans=-1;
    for(int k=n;k>=0;k--)
    {
        while(h[i].first>=k && i<n)
        {
            f.insert(h[i].second.second);
            p.insert(make_pair(h[i].second.first,h[i].second.second));
            tim+=h[i].second.first;
            i++;
        }
        while((tim>t || f.size()>k) && !f.empty() && !p.empty())
        {
            pair<int,int> ju=*p.begin();
            f.erase(ju.second);
            tim-=ju.first;
            p.erase(p.begin());
        }
        if(f.size()==k && tim<=t)
        {
            ans=k;break;
        }
    }
    if(ans==-1)
    {
        cout<<0<<endl<<0;
        return 0;
    }
    cout<<ans<<endl;
    cout<<f.size()<<endl;
    set <int> :: iterator itr;
    for (itr = f.begin(); itr != f.end(); ++itr)
    {
        cout << *itr+1<<" ";
    }
}
