#include<bits/stdc++.h>
using namespace std;
int a[1000001]={0};
int tree[1000001];
void build(int node, int s, int e)
{
    if(s==e)
    {
        tree[node] =-1;
    }
    else
    {
        int mid = (s + e) / 2;
        build(2*node, s, mid);
        build(2*node+1, mid+1, e);
        tree[node] = -1;
    }
}
void update(int node, int start, int en, int l, int r,int x)
{
        if(start==en)
        {
            if(tree[node]==-1 && l<=en && en<=r && x!=en)
                tree[node]=x;
            return;
        }
        int mid = (start + en) / 2;
        if(l <= start and en <= r)
        {
            if(tree[node]==-1 && (x<start || x>en))
            {    tree[node]=x;
            if(l==start && en==r)
              return;
            }
        }
        if(tree[2*node]==-1)
        update(2*node,start,mid,l,r,x);
        if(tree[2*node+1]==-1)
        update(2*node+1,mid+1,en,l,r,x);
}
void print(int node, int start, int en)
{
  if(start!=en)
    {
    int mid = (start + en) / 2;
    print(2*node, start, mid);
    print(2*node+1, mid+1, en);
    }
    if(tree[node]!=-1)
    {
        for(int i=start;i<=en;i++)
        {
          if(a[i]==0 && i!=tree[node])
            a[i]=tree[node];
        }
    }
}
int main()
{
    int n,q,l,r,x;
    cin>>n>>q;
    build(1,1,n);
    while(q--)
    {
        cin>>l>>r>>x;
        update(1,1,n,l,r,x);
        //for(int i=1;i<=7;i++)
          //cout<<tree[i]<<" ";
        //cout<<endl;
    }
    print(1,1,n);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
}

