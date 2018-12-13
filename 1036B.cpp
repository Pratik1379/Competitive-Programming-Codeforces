#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long int n,m,k;
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        long long int mini=min(m,n);
        long long int maxi=max(m,n);
        if(k>m+n || k<maxi)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n",n+m-1);
        }
    }
}
