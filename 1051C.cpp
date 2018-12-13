#include<bits/stdc++.h>
using namespace std;
int cnt[101]={0};
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    int sing=0,dou=0;
    int check=-1;
    for(int i=1;i<=100;i++)
    {
        if(cnt[i]>1)
        {
            dou++;
        }
        else if(cnt[i]==1)
        {
            sing++;
        }
        if(cnt[i]>2)
        {
            check=i;
        }
    }
    if((sing%2)==0 && sing!=0)
    {
        cout<<"YES\n";
        int l=sing/2;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(cnt[a[i]]>1)
            {
                cout<<"A";
            }
            else if(c>=l)
            {
                cout<<"B";
                c++;
            }
            else
            {
                cout<<"A";
                c++;
            }
        }
    }
    else if(sing==0)
    {
            cout<<"YES\n";
            int y=a[0];
            cout<<"A";
            for(int i=1;i<n;i++)
            {
                    cout<<"A";
            }
    }
    else if(check>0)
    {
        int c=0;
        int l=sing/2;
        int myl=0;
        cout<<"YES\n";
        for(int i=0;i<n;i++)
        {
            if(myl==0 && a[i]==check)
            {
                cout<<"A";
                myl=1;
            }
            else if(cnt[a[i]]>1)
            {
                cout<<"B";
            }
            else if(c<l)
            {
                cout<<"A";
                c++;
            }
            else
            {
                cout<<"B";
            }
        }
    }
    else
        cout<<"NO\n";
}
