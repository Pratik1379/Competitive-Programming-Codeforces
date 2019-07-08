#include<bits/stdc++.h>
using namespace std;
int a[100005];
int tree[400005],lazy[400005];
int maxi=1e9+7;
void build(int node, int s, int e)
{
    if(s==e)
    {
        tree[node]=a[s];
    }
    else
    {
        int mid = (s + e) / 2;
        build(2*node, s, mid);
        build(2*node+1, mid+1, e);
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}
int query(int node, int start, int en, int l, int r)
{
    if(r < start or en < l)
    {
        return maxi;
    }
    if(lazy[node] != 0) 
    { 
        tree[node] += lazy[node];
        if(start != en) {
            lazy[node*2] += lazy[node]; 
            lazy[node*2+1] += lazy[node]; 
        }
 
        lazy[node] = 0; 
    }
 
    if(l <= start and en <= r)
    {
        return tree[node];
    }
    int p1,p2;
    int mid = (start + en) / 2;
    p1 = query(2*node, start, mid, l, r);
    p2 = query(2*node+1, mid+1, en, l, r);
    return min(p1,p2);
}
void update(int node, int start, int en, int val)
{
    if(lazy[node] != 0) 
    {
        tree[node] += lazy[node];
        if(start != en) 
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];     
        }
        lazy[node] = 0;
    }
    if(tree[node] > val) 
    {
        tree[node]--;
        if(start != en) 
        {
                lazy[node*2]--;
                lazy[node*2+1]--;
        }
      return;
    }
    if(start == en) 
        return;
    int mid=(start+en)/2;
    update(2*node,start,mid,val);
    update(2*node+1,mid+1,en,val);
    tree[node]=min(tree[2*node],tree[2*node+1]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,q,x;
    cin>>n;
    int y;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(lazy,0,sizeof(lazy));
    cin>>q;
    build(1,1,n);
    while(q--)
    {
        cin>>x;
        update(1,1,n,x);
    }
    for(int i=1;i<=n;i++)
    {
        y=query(1,1,n,i,i);
        cout<<y<<" ";
    }
    return 0;
}
