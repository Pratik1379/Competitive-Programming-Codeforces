#include<bits/stdc++.h>
using namespace std;
int cnt[500005]={0};
vector<pair<int,int>> fre[500005];
int start;
int end;
int main()
{
    int n,c;
    cin>>n>>c;
    int a[n];
    int ori=0;
    int ct=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==c)
        {
            ct++;
        }
    }
    if(n==1)
    {
        cout<<1;return 0;
    }
    int u=0;
    for(int i=0;i<n;i++)
    {
        if(i==n-1)
        {
                u++;
                fre[a[i]].push_back(make_pair(u,i));
        }
        else if(a[i]==a[i+1])
        {
            u++;
        }
        else
        {
            u++;
            fre[a[i]].push_back(make_pair(u,i));
            u=0;
        }
    }
    ans=max(ct,ans);
    if(a[0]==c)
        cnt[0]=1;
    for(int i=1;i<n;i++)
    {
        cnt[i]=cnt[i-1];
        if(a[i]==c)
            cnt[i]=cnt[i]+1;
    }
    for(int i=1;i<=500005;i++)
    {
        int r=fre[i].size();
        if(r>0 && i!=c)
        {
            int sum=fre[i][0].first;
            int si=fre[i][0].second;
            int ei=si;
            int start=si,end=ei,maxi=sum;
            for(int j=1;j<r;j++)
            {
                int y=cnt[fre[i][j-1].second]-cnt[fre[i][j].second];
                if((y+sum)>0)
                {
                    sum=sum+y+fre[i][j].first;
                    ei=fre[i][j].first;
                }
                else
                {
                    sum=fre[i][j].first;
                    si=fre[i][0].second;
                    ei=si;
                }
                if(sum>maxi)
                {
                    maxi=sum;
                    end=ei;
                    start=si;
                }
            }
        }
        int compute=maxi+cnt[n]-cnt[end]+cnt[start];
        ans=max(ans,compute);
    }
    cout<<ans<<endl;
    return 0;
}
