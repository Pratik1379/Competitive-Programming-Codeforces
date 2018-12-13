#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int a[6]={1,2,3,4,6,12};
    while(t--)
    {
        bool h[6]={false};
        string s;
        cin>>s;
        bool y[12]={false};
        for(int i=0;i<12;i++)
        {
            if(s[i]=='X')
               {
                   y[i]=true;
                   h[0]=true;
               }
        }
        for(int i=1;i<6;i++)
        {
            int l=12/a[i];
            for(int k=0;k<l;k++)
            {
            bool x=y[k];
            pt=k;
            for(int j=1;j<=a[i];j++)
            {
                x=x&y[pt];
                pt+=l;
            }
            if(x==true)
            {
                h[i]=true;
                break;
            }
            }
        }
        int s1=0;
        for(int i=0;i<6;i++)
        {
            if(h[i])
                s1++;
        }
        cout<<s1<<endl;
        int r1;
        for(int i=0;i<6;i++)
        {
            if(h[i])
            {
                r1=12/a[i];
                cout<<a[i]<<" "<<r1<<endl;
            }
        }
    }
}
