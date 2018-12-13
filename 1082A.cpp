#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int ans=1e17+7;
        long long int n,x,y,d;
        cin>>n>>x>>y>>d;
        if(y>=x && (y-x)%d==0)
        {
            ans=(y-x)/d;
        }
        else if(x<y && (x-y)%d==0)
        {
            ans=(x-y)/d;
        }
        else if(y==n)
        {
            ans=(n-x+d-1)/d;
        }
        else if(y==1)
        {
            ans=(x-1+d-1)/d;
        }
        else
        {
            if((n-y)%d==0)
            {
            long long int h=(n-x+d-1)/d+(n-y)/d;
            ans=min(ans,h);
            }
            if((y-1)%d==0)
            {
            long long int h=(x-1+d-1)/d + (y-1)/d;
            ans=min(ans,h);
            }
        if(ans==1e17+7)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
}
