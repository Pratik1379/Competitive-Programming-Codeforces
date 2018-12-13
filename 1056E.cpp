#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int a=s.length();
    int b=t.length();
    int z=0,o=0;
    int ans=0;
    for(int i=0;i<a;i++)
    {
        if(s[i]=='0')
            z++;
        else
            o++;
    }
    if(z==0)
    {
        for(int i=1;i<=b;i++)
        {
            int fl=0;
            int cou=b/i;
            if((b%i)==0 && cou==o)
            {
                for(int j=i;j<b;j++)
                {
                   if(s[j]!=s[j%i])
                   {
                       fl=1;break;
                   }
                }
            }
            if(fl==0)
                ans++;
        }
    }
    else if(o==0)
    {
        for(int i=1;i<=b;i++)
        {
            int fl=0;
            int cou=b/i;
            if((b%i)==0 && cou==z)
            {
                for(int j=i;j<b;j++)
                {
                   if(s[j]!=s[j%i])
                   {
                       fl=1;break;
                   }
                }
            }
            if(fl==0)
                ans++;
        }
    }
    else
    {
        for(int j=1;j<(b/z);j++)
        {
            int y=j*z;
            int u=(b-y)/o;
            int zero=0,one=0;
            int s1,s2,s3;
            int fl=0;
            if(u*o==(b-y) && u>0)
            {
                int k=0;
                for(int i=0;i<a;i++)
                {
                    if(s[i]=='0' && zero==0)
                    {
                        s1=k
                        k+=j;
                        zero=1;
                    }
                    else if(s[i]=='0')
                    {
                        for(s3=k;s3<(k+j);s3++)
                        {
                            if(t[s3]!=t[s1+s3-k])
                            {
                                fl=1;break;
                            }
                        }
                        k+=j;
                    }
                    else if(s[i]=='1' && one==0)
                    {
                        s2=k;
                        k+=u;
                        one=1;
                    }
                    else
                    {
                        for(s3=k;s3<(k+u);s3++)
                        {
                            if(t[s3]!=t[s2+s3-k])
                            {
                                fl=1;break;
                            }
                        }
                        k+=u;
                    }
                }
            }
            if(fl==0 && s1!=s2)
             {   ans++;
             }
        }
    }
    cout<<ans;
    return 0;
}
