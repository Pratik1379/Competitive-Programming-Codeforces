#include<bits/stdc++.h>
using namespace std;
int check[6]={0};
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        check[a[i]]++;
        sum+=a[i];
    }
    int req=ceil(4.5*n);
    if(req<=sum)
        cout<<0;
    else
    {
        int dif=req-sum;
        int ans=0;
        int s1=ceil((dif*1.0)/3.0);
        if(s1<=check[2])
            {ans+=s1;
            dif=0;
            }
        else
        {
            ans+=check[2];
            dif-=check[2]*3;
        }
        if(dif>0)
        {
            s1=ceil((dif*1.0)/2.0);
            if(s1<=check[3])
            {ans+=s1;
            dif=0;
            }
            else
            {
            ans+=check[3];
            dif-=check[3]*2;
            }
        }
        if(dif>0)
        {
            s1=dif;
            if(s1<=check[4])
            {ans+=s1;
            dif=0;
            }
            else
            {
            ans+=check[4];
            dif-=check[4];
            }
        }
        cout<<ans;
    }
    return 0;
}
