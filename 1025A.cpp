#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;string s;
    cin>>n>>s;
    int a[26]={0};
    for(int i=0;i<n;i++)
    {
        a[s[i]-97]++;
    }
    int fl=0;
    for(int i=0;i<26;i++)
    {
        if(a[i]>=2)
        {
            fl=1;break;
        }
    }
    if(fl==0)
        cout<<"NO\n";
    else
        cout<<"YES\n";
    return 0;
}
