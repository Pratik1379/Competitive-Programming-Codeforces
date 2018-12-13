#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,x;
    cin>>n>>k;
    int a[n];
    int maxi[100001];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        maxi[i]=-1;
    }
    maxi[k]=-1;
    multiset<int> cnt;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(maxi[a[i]]==-1)
        {
            maxi[a[i]]=x;
        }
        else
            maxi[a[i]]=max(maxi[a[i]],x);
        cnt.insert(x);
    }
    int l=0;
    long int ans=0;
    for(int i=1;i<=k;i++)
    {
        if(maxi[i]!=-1)
            {
                cnt.erase(maxi[i]);
                l++;
            }
    }
    for(int i=l;i<=k;i++)
    {
        int y=*cnt.begin();
        cnt.erase(cnt.begin());
        ans+=y;
    }
    cout<<ans<<endl;
    return 0;
}
