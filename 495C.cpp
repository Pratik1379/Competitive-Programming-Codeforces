#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    bool vis1[100001];
    bool vis2[100001];
    int p[n];
    for(int i=0;i<=100000;i++)
      {
        vis1[i]=false;vis2[i]=false;
      }
    for(int i=0;i<n;i++)
    {
        p[i]=0;
        scanf("%d",&a[i]);
    }

    for(int i=n-2;i>=0;i--)
    {
        if(!vis1[a[i+1]])
        {
            vis1[a[i+1]]=true;
            p[i]=p[i+1]+1;
        }
        else
            p[i]=p[i+1];
    }
    /*for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }*/
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(!vis2[a[i]])
        {
            vis2[a[i]]=true;
            ans+=p[i];
        }
    }
    cout<<ans<<endl;
}
