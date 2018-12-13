#include<bits/stdc++.h>
using namespace std;
long long int n;
bool check(long long int k)
{
    long long int cur=n;
    long long int sum=0;
    while(cur>0)
    {
        long long int l=min(cur,k);
        sum+=l;
        cur=cur-l;
        cur=cur-cur/10;
    }
    return sum*2>=n;
}
int main()
{
    scanf("%lld",&n);
    long long int low=1,high=n;
    long long int ans;
    while(low<=high)
    {
        long long int mid=(low+high)/2;
        if(check(mid))
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    cout<<ans;
    return 0;
}
