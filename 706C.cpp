#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long int a[n];
    string s[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int fl=0;
    for(int i=0;i<n-1;i++)
    {
        int r1=s[i].length();
        int r2=s[i+1].length();
        if(r1>r2)
        {
            fl=1;break;
        }
        string h1=s[i];
        string k1=s[i+1];
        string h2=h1,k2=k1;
        reverse(h2.begin(),h2.end());
        reverse(k2.begin(),k2.end());
        if(h1>k1 && h2>k1 && h1>k2 && h2>k2)
        {
            fl=1;break;
        }
    }
    if(fl==1)
    {
        cout<<-1;
    }
    long long int dp[n][2];
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1e14+7;
        dp[i][1]=1e14+7;
    }
    dp[0][0]=0;dp[0][1]=a[0];
    for(int i=1;i<n;i++)
    {
        string h=s[i-1];
        string k=s[i];
        reverse(h.begin(),h.end());
        reverse(k.begin(),k.end());
        if(s[i-1]<s[i])
        {
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
        }
        if(h<s[i])
        {
            dp[i][0]=min(dp[i][0],dp[i-1][1]);
        }
        if(h<k)
        {
            dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
        }
        if(s[i-1]<k)
        {
            dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
        }
    }
    cout<<min(dp[n-1][0],dp[n-1][1]);
    return 0;
}
