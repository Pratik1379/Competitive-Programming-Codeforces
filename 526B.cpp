#include<bits/stdc++.h>
using namespace std;
int a[10001];
int b[10001];
int main()
{
    int n;
    cin>>n;
    int r1=pow(2,n+1)-1;
    int r2=pow(2,n);
    for(int i=2;i<=r1;i++)
        cin>>a[i];
    for(int i=r2;i<=r1;i++)
        b[i]=0;
    for(int i=r2-1;i>0;i--)
    {
        b[i]=max(b[2*i]+a[2*i],b[2*i+1]+a[2*i+1]);
    }
    long int sum=0;
    for(int i=1;i<r2;i++)
    {
        sum+=(b[i]-b[2*i]-a[2*i]);
        sum+=(b[i]-b[2*i+1]-a[2*i+1]);
    }
    cout<<sum;
}
