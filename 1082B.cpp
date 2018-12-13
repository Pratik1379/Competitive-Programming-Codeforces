#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;string s;
    cin>>n>>s;
    if(n==1)
    {
        if(s[0]=='G')
            cout<<1<<endl;
        else
            cout<<0<<endl;
        return 0;
    }
    int cnt=0;
    int ans=0;
    int prev=0;
    if(s[0]=='G' && s[1]=='B')
    {
        h.push_back(1);
    }
    else if(s[1]=='G' && s[0]=='G')
    {
        cnt++;
    }
    for(int i=1;i<n;i++)
    {
        if(i==n-1)
        {
            if(s[i]=='G')
                cnt++;
            h.push_back(cnt);
        }
        else if(s[i]=='G' && s[i+1]=='G')
            cnt++;
        else if(s[i]=='G' && s[i+1]=='B')
        {
            cnt++;
            h.push_back(cnt);
            cnt=0;
        }
    }
    if(h.size()==0)
    {
        cout<<0<<endl;
    }
    else if(h.size()==1)
    {
        cout<<h[0]<<endl;
    }
    else
    {
        int l=0;
        for(int i=0;i<n-2;i++)
        {
            if(s[i]=='G' && s[i+1]=='B' && s[i+2]=='G')
            {
                if(h.size()>2)
                {
                    ans=max(ans,h[l]+h[l+1]+1);
                }
                else
                    ans=max(ans,h[l]+h[l+1]);
            }
            if(s[i]=='G' && s[i+1]='B')
                l++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
