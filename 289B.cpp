#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,d;
    cin>>n>>m>>d;
    int siz=n*m;
    int a[siz];
    map<int,int> m;
    vector<int> v;
    for(int i=0;i<siz;i++)
    {
        cin>>a[i];
        if(m.count(a[i])==0)
            {m.insert(a[i],1);
            v.push_back(a[i]);
            }
        else
            m[a[i]]++;
    }
    sort(v.begin(),v.end());
    int r1=v.size();
    int fl=0;
    int check=a[0]%d;
    if(d!=1)
    {
    for(int i=1;i<r1;i++)
    {
        if(v[i]%d!=check)
        {
            fl=1;break;
        }
    }
    }
    if(fl==1)
    {
        cout<<-1;return 0;
    }
    int mid=r1/2;
    int ans=1e6,mini1=1e6,mini2=1e6;
    int c=0;
    for(int i=0;i<r1;i++)
    {
        int h=abs(v[mid]-v[i]);
        c+=(h/d)*m[v[i]];
    }
    mini1=c;mini2=c;
    for(int j=mid-1;j>=0;j--)
    {
        c=0;
        for(int i=0;i<r1;i++)
        {
        int h=abs(v[j]-v[i]);
        c+=(h/d)*m[v[i]];
        }
        if(c>=mini1)
            break;
        else
            mini1=c;
    }
    for(int j=mid+1;j<r1;j++)
    {
        c=0;
        for(int i=0;i<r1;i++)
        {
        int h=abs(v[j]-v[i]);
        c+=(h/d)*m[v[i]];
        }
        if(c>=mini2)
            break;
        else
            mini2=c;
    }
    ans=min(min1,mini2);
    cout<<ans;

}
