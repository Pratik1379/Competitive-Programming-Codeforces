#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long int a[n];
    int cn=0,cp=0;
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<0 && n!=1)
          {a[i]=-a[i];cn=1;}
        else if(a[i]>0)
          cp=1;
        sum+=a[i];
    }
    sort(a,a+n);
    if(n==1)
    {
        cout<<a[0];return 0;
    }
    if(cn==1 && cp==1)
    {
      cout<<sum;
    }
    else
    {
      sum=sum-2*a[0];
      cout<<sum;
    }
}
