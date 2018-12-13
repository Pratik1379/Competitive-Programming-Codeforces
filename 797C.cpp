#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int cnt[26]={0};
    int r1=s.length();
    stack<char> y;
    for(int i=0;i<r1;i++)
    {
        cnt[s[i]-97]++;
    }
    string h;
    for(int i=0;i<r1;i++)
    {
        y.push(s[i]);
        int l=s[i]-97;
        int fl=0;
        for(int k=0;k<l;k++)
        {
            if(cnt[k])
            {
                fl=1;break;
            }
        }
        if(fl==0)
        {
            h+=s[i];
            y.pop();
        }
        cnt[s[i]-97]--;
        while(fl==0 && !y.empty())
        {
            char c=y.top();
            l=c-97;
            for(int k=0;k<l;k++)
            {
            if(cnt[k])
            {
                fl=1;break;
            }
            }
            if(fl==0)
            {
            h+=c;
            y.pop();
            cnt[c-97]--;
            }
        }
    }
    while(!y.empty())
    {
        char g=y.top();
        y.pop();
        h+=g;
    }
    cout<<h;
    return 0;
}
