#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int r1=s.length();
    int fl=0;
    for(int i=0;i<r1;i++)
    {
        if(s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' )
        {
            if(i==r1-1)
            {
                fl=1;break;
            }
        }
        else if(s[i]!='n')
        {
            if(i==r1-1)
            {
                fl=1;break;
            }
            if(s[i+1]!='a' && s[i+1]!='e' &&s[i+1]!='i' &&s[i+1]!='o' &&s[i+1]!='u' )
            {
                fl=1;break;
            }

        }
    }
    if(fl==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
