#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    int a[35]={0};
    long int x,r;
    for(int i=0;i<n;i++)
    {scanf("%ld",&x);
    r=log2(x);
    a[r]++;
    }
    for(int i=0;i<q;i++)
    {
        scanf("%ld",&x);
        int y=log2(x);
        long int sum=x;
        int ans=0;
        for(int j=y;j>=0;j--)
        {
            if(sum==0)
                break;
            long int z=pow(2,j);
            long int f=sum/z;
            if(f<=a[j])
            {
                sum=sum-f*z;
                ans+=f;
            }
            else
            {
                sum=sum-a[j]*z;
                ans+=a[j];
            }
        }
        if(sum!=0)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
