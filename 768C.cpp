#include<bits/stdc++.h>
using namespace std;
int cnt[1024]={0};
int temp[1024]={0};
int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    int a;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        cnt[a]++;
    }
    for(int j=1;j<=k;j++)
    {
        int start=0;
        for(int i=0;i<1024;i++)
        {
            temp[i]=cnt[i];
            if(cnt[i]>0)
            {
                if(start&1)
                {
                    start+=cnt[i];
                    int z=cnt[i]/2;
                    int y=i^x;
                    temp[i]=cnt[i]-z;
                    temp[y]=cnt[y]+z;
                }
                else
                {
                    start+=cnt[i];
                    int z=ceil(cnt[i]*1.0/2.0);
                    int y=i^x;
                    temp[i]=cnt[i]-z;
                    temp[y]=cnt[y]+z;
                }
            }
        }
        for(int i=0;i<1024;i++)
        {
            cnt[i]=temp[i];
        }
    }
    int mini,maxi;
    for(int i=0;i<1024;i++)
    {
        if(cnt[i]>0)
        {
            mini=i;break;
        }
    }
    for(int i=1023;i>=0;i--)
    {
        if(cnt[i]>0)
        {
            maxi=i;break;
        }
    }
    cout<<maxi<<" "<<mini;
    return 0;
}
