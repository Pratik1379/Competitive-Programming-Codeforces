#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char a[n],b[n];
    int s1=m,s2=m;
    if(m==0 && n==1)
    {
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    if(m==0 || m > 9*n)
        cout<<-1<<" "<<-1<<endl;
    else
    {
        for(int i=0;i<n;i++)
        {
                if(s1>=9)
                {
                    s1-=9;a[i]='9';
                }
                else if(s1==0)
                {
                    a[i]='0';
                }
                else
                {
                    a[i]=s1+48;
                    s1=0;
                }
        }
        int fl=0;
        if(s2<=(9*(n-1)))
        {
            s2--;
            b[0]='1';
        }
        else
        {
            b[0]=s2-9*(n-1)+48;
            fl=1;
        }
        for(int i=1;i<n;i++)
        {
            if(fl==1)
                b[i]='9';
            else
            {
                if(s2<=(9*(n-i-1)))
                {
                    b[i]='0';
                }
                else
                {
                    b[i]=s2-9*(n-i-1)+48;
                    fl=1;
                }
            }
        }
        for(int i=0;i<n;i++)
            cout<<b[i];
        cout<<" ";
        for(int i=0;i<n;i++)
            cout<<a[i];
    }
    return 0;
}
