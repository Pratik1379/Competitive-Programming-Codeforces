#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long int k;
    cin>>n>>k;
    int a[n];
    int mini=1e9+7;
    long int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mini=min(mini,a[i]);
    }
    while(k>=mini)
    {
        long long int sum=0;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if((sum+a[i])<=k)
               {
                   sum=sum+a[i];
                   c++;
               }
        }
        ans=ans+(k/sum)*c;
        k=k%sum;
    }
    cout<<ans<<endl;
    return 0;
}
