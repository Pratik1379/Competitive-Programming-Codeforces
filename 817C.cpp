#include<bits/stdc++.h>
using namespace std;
long long int n,s;
int main()
{

    cin>>n>>s;
    long long int high,low,mid,ans;
    if(s>n || (s==1 && n==1))
    {
        cout<<0;return 0;
    }
    high=1e18;
    low=1;
    while(high>low && low>0)
    {
        mid=(high+low)/2;
        if(check(mid) && check(mid-1))
        {
            high=mid-1;
        }
        else if(check(mid))
        {
            ans=mid;break;
        }
        else
            low=mid+1;
    }
    cout<<n-ans+1;
}
