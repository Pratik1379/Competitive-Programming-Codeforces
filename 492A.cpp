#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n;
    scanf("%ld",&n);
    long int ans=0;
    long int r1=n/100;
    ans+=r1;
    n=n-r1*100;
    r1=n/20;
    ans+=r1;
    n=n-r1*20;
    r1=n/10;
    ans+=r1;
    n=n-r1*10;
    r1=n/5;
    ans+=r1;
    n=n-r1*5;
    ans+=n;
    cout<<ans;
}
