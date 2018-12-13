#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    string s,r;
    cin>>s>>r;
    bool pre[1001]={false};
    int sum[1001]={0};
    if(n>=m)
    {
    for(int i=0;i<n-m+1;i++)
    {
        int l=i;
        int fl=0;
        for(int j=0;j<m;j++)
        {
            if(s[l]==r[j])
                l++;
            else
                {
                    fl=1;break;
                }
        }
        if(fl==0)
            pre[i+1]=true;
    }
    for(int i=1;i<=n-m+1;i++)
    {
        if(pre[i])
        {
            sum[i]=sum[i-1]+1;
        }
        else
            sum[i]=sum[i-1];
    }
    for(int i=n-m+2;i<=n;i++)
    {
        sum[i]=sum[i-1];
    }
    }
    int x,y;
    while(q--)
    {
    cin>>x>>y;
    if(y-m+1>0)
        y=y-m+1;
    else
        y=0;
    if(x-m>0)
        x=x-m;
    else
        x=0;
    cout<<sum[y]-sum[x]<<endl;
    }
}
