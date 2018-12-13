#include<bits/stdc++.h>
using namespace std;
int neg[100001]={0};
int pos[100001]={0};
int main()
{
    int n;
    cin>>n;
    long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int sumz=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        sumz++;
    }
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(a[i]>0)
                pos[i]=1;
            else
                pos[i]=0;
        }
        else
        {
                if(a[i]>0)
                    pos[i]=pos[i-1]+1;
                else
                    pos[i]=pos[i-1];
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)
        {
            if(a[i]<0)
                neg[i]=1;
            else
                neg[i]=0;
        }
        else
        {
                if(a[i]<0)
                    neg[i]=neg[i-1]+1;
                else
                    neg[i]=neg[i-1];
        }
    }
    long int ans=1e9+5;
    for(int i=0;i<n-1;i++)
    {
        if(i==0)
        {
            long int maxi=neg[1]+sumz;
            ans=min(ans,maxi)
        }
        else
        {
            long int maxi=neg[i+1]+pos[i-1]+sumz;
            ans=min(ans,maxi);
        }
    }
    cout<<ans;
}
