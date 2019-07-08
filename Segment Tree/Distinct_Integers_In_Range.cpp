#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
bitset<5001> tree1[400005],tree2[400005];
void build(int node, int s, int e)
{
    if(s==e)
    {
        tree1[node].set(a[s]);
        tree2[node].set(b[s]);
    }
    else
    {
        int mid = (s + e) / 2;
        build(2*node, s, mid);
        build(2*node+1, mid+1, e);
        tree1[node] = tree1[2*node] | tree1[2*node+1];
        tree2[node] = tree2[2*node] | tree2[2*node+1];
    }
}
bitset<5001> query(int node, int start, int en, int l, int r)
{
    if(r < start or en < l)
    {
        return 0;
    }
    if(l <= start and en <= r)
    {
        return tree1[node];
    }
    bitset<5001> p1,p2;
    int mid = (start + en) / 2;
    p1 = query(2*node, start, mid, l, r);
    p2 = query(2*node+1, mid+1, en, l, r);
    return (p1|p2);
}
bitset<5001> query2(int node, int start, int en, int l, int r)
{
    if(r < start or en < l)
    {
        return 0;
    }
    if(l <= start and en <= r)
    {
        return tree2[node];
    }
    bitset<5001> p1,p2;
    int mid = (start + en) / 2;
    p1 = query2(2*node, start, mid, l, r);
    p2 = query2(2*node+1, mid+1, en, l, r);
    return (p1|p2);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,q,x,y,w,z;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    cin>>q;
    build(1,1,n);
    while(q--)
    {
        cin>>x>>y>>z>>w;
        bitset<5001> res = query(1, 1, n, x, y)|query2(1, 1, n, z, w);
        cout<<res.count()<<endl;
    }
    return 0;
}
