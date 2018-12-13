#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n-1],b[n-1];
    bool vis[1001]={false};
    int cnt[1001]={0};
    int fl=0;
    for(int i=0;i<n-1;i++)
    {
        cin>>a[i]>>b[i];
        cnt[a[i]]++;
        if(b[i]!=n)
            fl=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]>i)
        {
            fl=1;break;
        }
    }
    if(fl==1)
    {cout<<"NO";return 0;}
    cout<<"YES\n";
    sort(a,a+n);
    vector<int> h;
    h.push_back(a[0]);
    vis[a[0]]=true;
    for(int i=1;i<n-1;i++)
    {
        if(a[i]>a[i-1])
           { h.push_back(a[i]);
           vis[a[i]]=true;
           }
        else
        {
            for(int j=1;j<a[i];j++)
            {
                if(!vis[j])
                {
                    h.push_back(j);
                    vis[j]=true;
                    break;
                }
            }
        }
    }
    h.push_back(n);
    for(int i=1;i<n;i++)
    {
      cout<<h[i-1]<<" "<<h[i]<<endl;
    }
    return 0;
}
