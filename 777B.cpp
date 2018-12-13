#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s,m;
    vector<int> a;
    cin>>s>>m;
    int cnt[10]={0};
    int cnt2[10]={0};
    for(int i=0;i<n;i++)
    {
    int x=s[i]-48;
    int y=s[i]-48;
    a.push_back(x);
    cnt[y]++;cnt2[y]++;
    }
    sort(a.begin(),a.end());
    int l=-1,s=-1;
    for(int i=0;i<9;i++)
    {
        if(cnt[i]>0)
        {
            s=i;break;
        }
    }
    for(int i=9;i>=0;i--)
    {
        if(cnt[i]>0)
        {
            l=i;break;
        }
    }
    int s1=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]<=l)
        {
            cnt[l]--;
            if(cnt[l]==0)
            {
                l=-1;
                for(int i=9;i>=0;i--)
                {
                if(cnt[i]>0)
                {
                    l=i;break;
                }
                }
            }
        }
        else
        {
            s1++;
            cnt[s]--;
            if(cnt[s]==0)
            {
                s=-1;
                for(int i=0;i<9;i++)
                {
                    if(cnt[i]>0)
                        {
                        s=i;break;
                        }
                }
            }
        }
    }
    for(int i=0;i<9;i++)
                {
                    if(cnt2[i]>0)
                        {
                        s=i;break;
                        }
                }
    int s2=0;
    for(int i=0;i<n;i++)
    {
        int fl=-1;
        for(int j=a[i]+1;j<10;j++)
        {
            if(cnt2[j]>0)
            {
                fl=j;break;
            }
        }
        if(fl==-1)
        {
            cnt2[s]--;
            s2++;
            if(cnt2[s]==0)
            {
                for(int i=0;i<9;i++)
                {
                    if(cnt2[i]>0)
                        {
                        s=i;break;
                        }
                }
            }
        }
        else
            cnt2[fl]--;
    }
    cout<<s1<<endl<<s2;
    return 0;
}
