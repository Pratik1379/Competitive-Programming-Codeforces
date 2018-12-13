#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int r1=s.length();
    if(r1<7)
        {cout<<0;return 0;}
    vector<string> v;
    string h;
    bool dp[r1][2];
    for(int i=0;i<r1;i++)
    {
        dp[i][0]=false;dp[i][1]=false;
    }
    dp[r1-1][0]=true;dp[r1-1][1]=true;
    if(s[r1-1]!=s[r1-3] || s[r1-2]!=s[r1-4])
        dp[r1-3][0]=true;
    dp[r1-3][1]=true;
    for(int i=r1-4;i>=6;i--)
    {
        dp[i][0]=dp[i+3][1];
        bool h=(dp[i+2][0]&(s[i-1]!=s[i+1]|s[i]!=s[i+2]));
        dp[i][0]=dp[i][0]|h;
        dp[i][1]=dp[i+2][0];
        h=(dp[i+3][1]&(s[i-2]!=s[i+1]|s[i-1]!=s[i+2]|s[i]!=s[i+3]));
        dp[i][1]=dp[i][1]|h;
    }
    for(int i=r1-1;i>6;i--)
    {
        if(i!=r1-2)
        {
            if(dp[i][0])
            {
              h=s.substr(i-1,2);
              v.push_back(h);
            }
            if(dp[i][1])
            {
              h=s.substr(i-2,3);
              v.push_back(h);
            }
        }
    }
    if(dp[6][0])
    {
    h=s.substr(5,2);
    v.push_back(h);
    }
    sort(v.begin(),v.end());
    vector<string>::iterator it;
    it = unique (v.begin(), v.end());
    v.resize(distance(v.begin(),it));
    int r3=v.size();
    cout<<r3<<endl;
    for(int i=0;i<r3;i++)
        cout<<v[i]<<endl;
    return 0;
}
