#include<bits/stdc++.h>
using namespace std;
bool vis[1000001]={false};
int main()
{
    int val[10];
    int n;
    cin>>n;
    int mini=1e6+7;
    int j=-1;
    for(int i=1;i<=9;i++)
       {
          cin>>val[i];
            if(mini>val[i])
            {
                mini=val[i];
                j=i;
            }
            else if(mini==val[i])
            {
                j=i;
            }
       }
    if(mini>n)
    {
        cout<<-1;return 0;
    }
    int s[n+1][10];
    vis[mini]=true;
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<10;j++)
            s[i][j]=0;
    }
    s[mini][j]++;
    for(int i=mini+1;i<=n;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(vis[i-val[j]] && i>=val[j])
            {
                if(vis[i])
                {
                    int h[10];
                    for(int k=1;k<=9;k++)
                        h[k]=s[i-val[j]][k];
                    h[j]++;
                    int s1=0,s2=0;
                    for(int k=1;k<=9;k++)
                    {
                        s1+=h[k];
                        s2+=s[i][k];
                    }
                    if(s1>s2)
                    {
                        for(int k=1;k<=9;k++)
                            s[i][k]=h[k];
                    }
                    else if(s1==s2)
                    {
                        int fl=0;
                        for(int k=9;k>=1;k--)
                        {
                            if(s[i][k]<h[k])
                            {
                                fl=1;break;
                            }
                            else if(s[i][k]>h[k])
                            {
                                fl=-1;break;
                            }
                        }
                        if(fl==1)
                        {
                           for(int k=1;k<=9;k++)
                            s[i][k]=h[k];
                        }
                    }
                }
                else
                {
                    for(int k=1;k<=9;k++)
                        s[i][k]=s[i-val[j]][k];
                    s[i][j]++;
                }
                vis[i]=true;
            }
        }
    }
    for(int j=9;j>=1;j--)
        {
            int r1=s[n][j];
            while(r1>0)
            {
                cout<<j;
                r1--;
            }
        }
}
