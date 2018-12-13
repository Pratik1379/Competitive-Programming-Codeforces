#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        int fl=0;
        for(int i=0;i<n/2;i++)
        {
            int y=(int)(s[i]-97);
            int z=(int)(s[n-1-i]-97);
            if(abs(y-z)!=2 && abs(y-z)!=0)
            {
                fl=1;break;
            }
        }
        if(fl==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
