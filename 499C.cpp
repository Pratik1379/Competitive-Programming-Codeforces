#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;long double m;
    cin>>n>>m;
    long double a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    long double l=0,r=1e9;
    long double mid;
    long double ans=-1;
    while((r-l)>0.0000001){
        mid=(l+r)/2;
        long double h=m+mid;
        h=h-(h/a[0]);
        for(int i=1;i<n;i++)
        {
            h=h-(h/b[i]);
            h=h-(h/a[i]);
            if(h<0)
                break;
        }
        h=h-(h/b[0]);
        if(h>=m)
        {
            ans=mid;
            r=mid-0.0000001;
        }
        else
        {
            l=mid+0.0000001;
        }
    }
    cout<<ans;
    return 0;
}
