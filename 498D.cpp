#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s,t;
    cin>>n>>s>>t;
    int check[n];
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
            check[i]=1;
        else
            check[i]=0;
    }
    for(int i=0;i<n/2;i++)
    {
        if(check[i])
        {
            if(s[i]==t[n-1-i] && t[i]==s[n-1-i])
            {
                check[i]=0;check[n-1-i]=0;
            }
            else if(s[i]==s[n-1-i] && t[i]==t[n-1-i])
            {
                check[i]=0;check[n-1-i]=0;
            }
            else if(t[i]==t[n-1-i] && check[n-1-i])
            {
                check[i]=0;
            }
            else if(s[i]==t[n-i-1] && check[n-1-i])
            {
                check[i]=0;
            }
            else if(check[n-1-i] && s[n-1-i]==t[i])
            {
                check[n-1-i]=0;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(check[i])
        {
            ans++;
        }

    }
    cout<<ans<<endl;
    return 0;
}
