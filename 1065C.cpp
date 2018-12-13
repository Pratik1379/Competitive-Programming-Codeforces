#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long int k;
    cin>>n>>k;
    int a[n];
    int maxi=0,mini=1e6+7;
    int fre[200001]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        fre[a[i]]++;
        maxi=max(maxi,a[i]);
        mini=min(mini,a[i]);
    }
    if(maxi==mini)
    {
      cout<<0;return 0;
    }
    long int cnt=fre[maxi];
    long int sum=0,ans=1;
    for(int i=maxi-1;i>=mini;i--)
    {
        if((sum+cnt)<=k)
        {
            sum+=cnt;
        }
        else
        {
            sum=cnt;
            ans++;
        }
        cnt+=fre[i];
    }
    cout<<ans<<endl;
    return 0;
}
