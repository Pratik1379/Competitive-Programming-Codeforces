#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long int a[n];
    vector<pair<long int,int>>v;
    bool b[n];
    for(int i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
        b[i]=false;
        v.push_back(make_pair(a[i],i));
    }
    sort(v.begin(),v.end());
    int i=0,j=0;
    int ans=0;
    while(j<n)
    {
        while(b[v[i].second] && i<n)
            i++;
        while(v[j].first<=v[i].first && j<n)
            j++;
        if(i<n && j<n)
        {
            //cout<<i<<" "<<j<<endl;
            b[v[i].second]=true;
            ans++;
        }
        i++;
        j++;
    }
    cout<<ans;
    return 0;
}
