#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int tree[1000001];
int n;
void build(int node, int s, int e,int l)
{
    if(s==e)
    {
        tree[node] = a[s];
    }
    else
    {
        int mid = (s + e) / 2;
        build(2*node, s, mid,l+1);
        build(2*node+1, mid+1, e,l+1);
        if((l+n)&1)
        tree[node] = tree[2*node]|tree[2*node+1]);
        else
        tree[node] = tree[2*node]^tree[2*node+1]);
    }
}
void update(int node, int start, int en, int idx, int val,int l)
{
    if(start == en && en==idx)
    {
        a[idx]=val;
        tree[node]=val;
    }
    else
    {
        int mid = (start + en) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, en, idx, val);
        }
        if((l+n)&1)
        tree[node] = tree[2*node]|tree[2*node+1]);
        else
        tree[node] = tree[2*node]^tree[2*node+1]);
    }
}
int main()
{
    int n,q,x,y;
    cin>>n>>q;
    for(int i=1;i<=pow(2,n);i++)
        cin>>a[i];
    build(1,1,n,1);
    while(q--)
    {
            cin>>x>>y;
            update(1,1,n,x,y,1);
            cout<<tree[1]<<endl;
    }
}
