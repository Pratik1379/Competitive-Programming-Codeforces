#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> s,d;
    string t;
    int n;
    cin>>n>>t;
    int freq[26]={0};
    for(int i=0;i<n;i++)
    {
        freq[t[i]-97]++;
    }
    for(int i=0;i<26;i++)
    {
        if(freq[i]>0)
        {
            if(freq[i]&1)
            {
                char y=i+97;
                s.push_back(y);
            }
            else
            {
                char y=i+97;
                d.push_back(y);
            }
        }
    }
    int r1=d.size();
    int r2=s.size();
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<(freq[d[i]-97]/2);j++)
        {
            cout<<d[i];
        }
    }
    if(r2>0)
    {
        for(int j=0;j<freq[s[0]-97];j++)
        {
            cout<<s[0];
        }
    }
    for(int i=r1-1;i>=0;i--)
    {
        for(int j=0;j<(freq[d[i]-97]/2);j++)
        {
            cout<<d[i];
        }
    }
    for(int i=1;i<r2;i++)
    {
        for(int j=0;j<freq[s[i]-97];j++)
        {
            cout<<s[i];
        }
    }
}
