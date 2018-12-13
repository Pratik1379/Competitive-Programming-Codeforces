#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    long long int mod=1e9+7;
    long long int sum=0,so=0;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            a[i]=1;
        }
        else
            a[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            a[i]=(a[i]+so)%mod;
            sum=(sum+a[i])%mod;
            if(i+1<n && s[i+1]=='b')
            {
                so=a[i];
            }
        }
    }
    sum=(sum)%mod;
    cout<<sum;
}
