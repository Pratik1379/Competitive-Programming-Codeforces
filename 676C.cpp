#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;string s;
    cin>>n>>k;
    cin>>s;
    vector<int> par;
    map<int,int> m,a,b;
    par.push_back(0);
    int parent[n];
    int siz=1,p=0;
    parent[0]=0;
    int cnta[n],cntb[n];
    if(s[0]=='a')
    {cnta[0]=1;cntb[0]=0;}
    else
    {
        cnta[0]=0;cntb[0]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            if(i>0)
            {cnta[i]=cnta[i-1]+1;
            cntb[i]=cntb[i-1];}
            a.insert(make_pair(cnta[i],i));}
        else
           {
            if(i>0)
              {cnta[i]=cnta[i-1];cntb[i]=cntb[i-1]+1;}
               b.insert(make_pair(cntb[i],i));
           }
    }
    for(int i=1;i<n;i++)
    {
        if(s[i]!=s[i-1])
        {
            par.push_back(i);
            m.insert(make_pair(p,siz));
            siz=1;
            p=i;
            parent[i]=p;
        }
        else
        {
            parent[i]=p;
            siz++;
        }
        if(i==n-1)
        {
            m.insert(make_pair(p,siz));
        }
    }
    int r1=par.size();
    if(r1==1)
    {
        cout<<n;
        return 0;
    }
    int ans=0;
    for(int i=1;i<r1;i++)
    {
        int y=par[i]+k-1;
        int siz2=m.at(par[i-1]);
        if(y>=n)
        {
            int u1=n-par[i-1];
            ans=max(ans,u1);
            break;
        }
        else if(s[par[i]]=='b')
        {
            int u1=cntb(par[i]);
            int u2;
            if(b.count(u1+k-1)==0)
            {
                ans=max(ans,n-par[i-1]);
            }
            else
            {
                u2=b.at(u1+k-1);
                if(s[u2+1]=='a' && u2+1<n)
                    ans=max(ans,u2-par[i-1]+1+m.at(par[u2+1]));
                else
                    ans=max(ans,u2-par[i-1]+1);
            }
        }
        else
        {
            int u1=cnta(par[i]);
            int u2;
            if(a.count(u1+k-1)==0)
            {
                ans=max(ans,n-par[i-1]);
            }
            else
            {
                u2=a.at(u1+k-1);
                if(s[u2+1]=='b' && u2+1<n)
                    ans=max(ans,u2-par[i-1]+1+m.at(par[u2+1]));
                else
                    ans=max(ans,u2-par[i-1]+1);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
