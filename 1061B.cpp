#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1)
    {cout<<0<<endl;
    return 0;
    }
    sort(a,a+n);
    int last;
    long int ans=0;
    if(a[0]==a[1])
    {last=1;
    ans+=a[0]-1;
    }
    else
    {
        last=a[0];
    }
    for(int j=1;j<n-1;j++)
    {
        if(a[j]==a[j+1])
        {
            if(last<a[j])
                last++;
            ans+=a[j]-1;
        }
        else
        {
            ans+=last;
            last=a[j];
        }
    }
    if(last==a[n-1])
        ans+=last-1;
    else
        ans+=last;
    cout<<ans;
    return 0;
}
