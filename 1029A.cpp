#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;string s;
    cin>>n>>k;
    cin>>s;
    if(k==1)
    cout<<s<<endl;
    else
    {
    int pos=-1;
    int fl=0;
    for(int i=0;i<=n/2;i++)
    {
        string r=s.substr(0,i+1);
        fl=0;
        int l=i;
        int m=n/(i+1);
        for(int j=1;j<m;j++)
        {
            int pos=j*(i+1);
            string h=s.substr(pos,i+1);
            if(h!=r)
            {
                fl=1;break;
            }
        }
        if(fl==0 && ((i+1)*m)==n)
        {
            pos=i+1;break;
        }
        if(fl==0)
        {
            int y1=0,y2=(i+1)*m;
            while(y2<n)
            {
                if(s[y1]==s[y2])
                {
                    y1++;y2++;
                }
                else
                {
                    fl=1;break;
                }
            }
            if(fl==0)
            {
                pos=i+1;break;
            }
        }
    }
    if(pos==-1)
    {
        for(int i=0;i<k;i++)
            cout<<s;
    }
    else
    {
        string r=s.substr(0,pos);
        int m=n/pos;
        if(n==(pos*m))
        {
            cout<<s;
            for(int i=m;i<k;i++)
            {
                cout<<r;
            }
        }
        else
        {
            cout<<s;
            int l1=n%pos;
            string u=s.substr(l1,pos);
            for(int i=m;i<k;i++)
            {
                cout<<u;
            }
        }
    }
    }
    return 0;
}
