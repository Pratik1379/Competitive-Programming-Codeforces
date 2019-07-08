#include<bits/stdc++.h>
using namespace std;
int tree[4000005];
int a[1000005],b[1000005];
int n;
void build(int node, int s, int e)
{
    if(s==e)
    {
        tree[node] = 0;
    }
    else
    {
        int mid = (s + e) / 2;
        build(2*node, s, mid);
        build(2*node+1, mid+1, e);
        tree[node] = 0;
    }
}
void update(int node,int s, int e, int ind)
{
    if(s==e && e==ind)
    {
        tree[node]++;return;
    }
    int mid=(s+e)/2;
    if(s<=ind && ind<=mid)
        update(2*node,s,mid,ind);
    else
        update(2*node+1,mid+1,e,ind);
    tree[node]=tree[2*node]+tree[2*node+1];
}
long long int query(int node,int s, int e, int l,int r)
{
    if(s>r or l>e or l>r or l>n or r>n)
        return 0;
    if(l<=s && e<=r)
        return tree[node];
    int mid = (s+e)/2;
    long long int p1 = query(2*node,s,mid,l,r);
    long long int p2 = query(2*node+1,mid+1,e,l,r);
    return p1+p2;
}
int main()
{
    cin>>n;
    int x;
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++)
    {
        cin>>x;v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++)
        b[v[i-1].second]=i;
    long long int ans=0;
    update(1,1,n,b[1]);
    for(int i=2;i<n;i++)
    {
        long long int res = query(1,1,n,b[i]+1,n);
        long long int res2 = (b[i]-1)-(i-res-1);
        ans = ans + res*res2;
        //cout<<res<<" "<<res2<<endl;
        update(1,1,n,b[i]);
    }
    cout<<ans;
}