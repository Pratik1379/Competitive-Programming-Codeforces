#include<bits/stdc++.h>
using namespace std;
bool prime[1000001]={false};
void sieve()
{
    for (int p=2; p*p<=1000000; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=1000000; i += p)
                prime[i] = false;
        }
    }
}
int main()
{
    sieve();
    int n,m;
    cin>>n>>m;
    int ans;
    for(int i=n;i<1e6;i++)
    {
        if(prime[i])
        {
            ans=i;break;
        }
    }
    int y=ans-n+1;
    cout<<ans<<" "<<ans<<endl;
    for(int i=1;i<n-1;i++)
    {
        cout<<i<<" "<<i+1<<" "<<1<<endl;
    }
    cout<<n-1<<" "<<n<<" "<<y<<endl;
    int check=n-1;
    while(1)
    {
        if(check==m)
            break;
        for(int i=1;i<n;i++)
        {
            for(int j=i+2;j<=n && check<m;j++)
            {
                cout<<i<<" "<<j<<" "<<ans<<endl;
            }
            if(check==m)
                break;
        }
        if(check==m)
            break;
    }
}
