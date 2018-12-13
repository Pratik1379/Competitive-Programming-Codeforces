#include<bits/stdc++.h>
using namespace std;
int a[100001]={0};
int b[100001]={0};
int main()
{
    string s;
    cin>>s;
    int r1=s.length();
    a[0]=1;
    b[r1-1]=1;
    int i;
    for(i=1;i<r1;i++)
    {
        if(s[i]!=s[i-1])
        {
            a[i]=a[i-1]+1;
        }
        else
            break;
    }
    for(int j=i;j<r1;j++)
        a[j]=a[j-1];
    for(i=r1-2;i>=0;i--)
    {
        if(s[i]!=s[i+1])
        {
            b[i]=b[i+1]+1;
        }
        else
            break;
    }
    for(int j=i;j>=0;j--)
    {
        b[i]=b[i+1];
    }
    if(s[0]==s[r1-1])
    {
        int maxi=1;
        int ans=1;
        for(i=1;i<r1;i++)
        {
            if(s[i]!=s[i-1])
                ans++;
            else
            {
                maxi=max(ans,maxi);
                ans=1;
            }
        }
        if(s[r1-1]!=s[r1-2])
        {
            maxi=max(maxi,ans);
        }
        cout<<maxi;return 0;
    }
    int maxi=1;
    int ans=1;
        for(i=1;i<r1;i++)
        {
            if(s[i]!=s[i-1])
                maxi++;
            else
            {
                ans=max(ans,maxi);
                ans=1;
            }
        }
        if(s[r1-1]!=s[r1-2])
        {
            ans=max(maxi,ans);
        }
    for(i=1;i<r1;i++)
    {
        int y1=a[i-1];
        int y2=b[i];
        ans=max(ans,y1+y2);
    }
    cout<<ans<<endl;
    return 0;
}

