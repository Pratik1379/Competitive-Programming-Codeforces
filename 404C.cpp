#include<bits/stdc++.h>
using namespace std;
int deg[100001]={0};
vector<int> a[100001];
int main()
{
    int n,k,x;
    cin>>n>>k;
    vector<pair<int,int>> v,h;
    int maxi=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        maxi=max(maxi,x);
        a[x].push_back(i);
    }
    if(a[0].size()!=1)
    {
        cout<<-1;return 0;
    }
    if(((int)a[1].size())>k)
    {
        cout<<-1;return 0;
    }
    for(int i=2;i<=maxi;i++)
    {
        long int prev=a[i-1].size()*(k-1);
        long int curr=a[i].size();
        if(curr>prev)
        {
            cout<<-1;return 0;
        }
    }
    int siz=0;
    for(int j=0;j<=maxi;j++)
    {
    int l=0;
    for(unsigned int i=0;i<a[j+1].size();i++)
    {
        h.push_back(make_pair(a[j][l],a[j+1][i]));
        siz++;
        deg[a[j][l]]++;
        if(deg[a[j][l]]>=k)
            l++;
        deg[a[j+1][i]]++;
    }
    }
    cout<<siz<<endl;
    for(int i=0;i<siz;i++)
    {
        printf("%d %d\n",h[i].first,h[i].second);
    }
}
