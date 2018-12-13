#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> a[26];
    vector<string> b[6];
    int n,q;
    cin>>n>>q;
    string s1,t1;
    for(int i=0;i<q;i++)
    {
        string h;char l;
        cin>>h>>l;
        a[l-97].push_back(h);
    }
    b[0].push_back("a");
    int fl=0;
    for(int i=1;i<n;i++)
    {
        int r1=b[i-1].size();
        if(r1==0)
        {
            fl=1;break;
        }
        for(int k=0;k<b[i-1].size();k++)
        {
            string h=b[i-1][k];
            char x=b[i-1][k][0];
            int y1=a[x-97].size();
            for(int u=0;u<y1;u++)
            {
                s1=a[x-97][u];
                t1=h.substr(1,i-1);
                s1+=t1;
                b[i].push_back(s1);
            }
        }
    }
    if(fl==1)
    {
        cout<<0;return 0;
    }
    vector<string>::iterator ip;
    ip = unique(b[n-1].begin(), b[n-1].end());
    b[n-1].resize(distance(b[n-1].begin(), ip));
    int r2=b[n-1].size();
    cout<<r2<<endl;
}
