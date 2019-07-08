#include<bits/stdc++.h>
using namespace std;
int tree[400005],a[100005];
int n;
void build(int node, int s, int e)
{
    if(s==e)
    {
        tree[node] = a[s];
    }
    else
    {
        int mid = (s + e) / 2;
        build(2*node, s, mid);
        build(2*node+1, mid+1, e);
        if(a[mid]==1 && a[mid+1]==1)
            tree[node] = tree[2*node]+tree[2*node+1]-1;
        else
            tree[node] = tree[2*node]+tree[2*node+1];
    }
}
int query(int node, int start, int en, int l,int r)
{
    if(l<1 or r>n or r<start or l>en)
    {
        return 0;
    }
    if(l<=start && en<=r)
    {
        return tree[node];
    }
    int mid = (start + en) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, en, l, r);
    if(a[mid]==1 && a[mid+1]==1 && mid>=l && mid+1<=r)
        return (p1+p2-1);
    return p1+p2;
}
void update(int node, int s, int e,int ind)
{
    if(s<1 or e>n)
    {
        return;
    }
    if(s==e && e==ind)
    {
        if(tree[node]==0)
            tree[node] = 1;
        else 
            tree[node]=0;
    }
    else if(s<e)
    {
        int mid = (s + e) / 2;
        if(ind>=s && ind<=mid)
            update(2*node, s, mid,ind);
        else
            update(2*node+1, mid+1, e,ind);
        if(a[mid]==1 && a[mid+1]==1)
            tree[node] = tree[2*node]+tree[2*node+1]-1;
        else
            tree[node] = tree[2*node]+tree[2*node+1];
    }
}
int main()
{
    int m,x,y,z;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    /*for(int i=1;i<=n;i++)
        cout<<query(1,1,n,i,i)<<"**";
    cout<<endl;*/
    while(m--)
    {
        cin>>x;
        if(x==1)
        {
            cin>>y;
            if(a[y]==1)
                a[y]=0;
            else
                a[y]=1;
            update(1,1,n,y);
            /*for(int i=1;i<=n;i++)
                cout<<query(1,1,n,i,i)<<"**";
            cout<<endl;*/
        }
        else
        {
            cin>>y>>z;
            int res=query(1,1,n,y,z);
            cout<<res<<endl;
        }
    }
}