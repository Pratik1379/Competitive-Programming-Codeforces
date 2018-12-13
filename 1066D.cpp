#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;long int k;
    cin>>n>>m>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int i;
    int box=1,sum=0;
    for(i=n-1;i>=0;i--)
    {
        if((sum+a[i])<=k)
            sum+=a[i];
        else
        {
            box++;
            if(box>m)
                break;
            sum=a[i];
            if(sum>k)
                break;
        }
    }
    int ans=n-i-1;
    cout<<ans<<endl;
    return 0;
}
