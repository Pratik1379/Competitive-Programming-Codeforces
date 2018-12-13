#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,a,b,ans;
    cin>>n>>m;
    if(m==1)
    {
        cout<<n*n;
        return 0;
    }
    a=n/m;
    b=n%m;
    ans=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=i;j<=m;j++)
        {
            if((i*i+j*j)%m==0)
            {
                if(i==j)
                {
                    if(i<=b)
                        ans+=(a+1);
                    else
                        ans+=(a);
                }
                else
                {
                    if(i<=b && j<=b)
                    {
                        ans+=2*(a+1);
                    }
                    else if(i<=b || j<=b)
                    {
                        ans+=2*a+1;
                    }
                    else
                        ans+=2*a;
                }
            }
        }
    }
    cout<<ans<<endl;
}
