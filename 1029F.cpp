#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,x,y,z;
    cin>>a>>b;
    x=sqrt(a);
    y=sqrt(a+b);
    z=sqrt(b);
    vector<long long int> v,h,g;
    v.push_back(1);h.push_back(1);g.push_back(1);
    for(long long int i=2;i<=x+1;i++)
        {
            if(a%i==0)
            {
                v.push_back(i);
            }
        }
    for(long long int i=2;i<=z+1;i++)
        {
            if(b%i==0)
            {
                g.push_back(i);
            }
        }
    for(long long int i=2;i<=y+1;i++)
        {
            if((a+b)%i==0)
            {
                h.push_back(i);
            }
        }
    int r1=v.size();
    int r2=h.size();
    int r3=g.size();
    long long int ans=1e17;
    for(long int i=0;i<r2;i++)
    {
        for(int j=r1-1;j>=0;j--)
        {
            if(((a+b)/h[i])>=(a/v[j]))
            {
                ans=min(ans,2*(h[i]+((a+b)/h[i])));
                break;
            }
        }
    }
    for(long int i=0;i<r2;i++)
    {
        for(int j=r3-1;j>=0;j--)
        {
            if(((a+b)/h[i])>=(b/g[j]))
            {
                ans=min(ans,2*(h[i]+((a+b)/h[i])));
                break;
            }
        }
    }
    cout<<ans;
}
