#include<bits/stdc++.h>
using namespace std;
long int a[100001],dif1[100001],dif2[100001];
int main()
{
    int n;long int m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%ld",&a[i]);
    for(int i=0;i<n;i+=2)
    {
        if(i!=0 && i!=n-1)
        dif1[i]=a[i+1]-a[i];

    }
    return 0;
}
