#include<bits/stdc++.h>
using namespace std;
int tree[4000005];
int n;
void build(int node, int s, int e)
{
    if(s==e)
    {
        tree[node] = 1;
    }
    else
    {
        int mid = (s + e) / 2;
        build(2*node, s, mid);
        build(2*node+1, mid+1, e);
        tree[node] = tree[2*node]+tree[2*node+1];
    }
}
int query(int node, int start, int en, int k)
{
    if(start<1 or en>n or tree[node]<k)
    {
        return -1;
    }
    if(start==en and k==1)
    {
        return start;
    }
    int mid = (start + en) / 2;
    int p1 = tree[2*node];
    if(p1>=k)
      return query(2*node, start, mid, k);
    return query(2*node+1, mid+1, en, k-p1);
}
void update(int node, int s, int e,int ind)
{
    if(s<1 or e>n)
    {
        return;
    }
    if(s==e && e==ind)
    {
        tree[node] = 0;
    }
    else if(s<e)
    {
        int mid = (s + e) / 2;
        if(ind>=s && ind<=mid)
            update(2*node, s, mid,ind);
        else
            update(2*node+1, mid+1, e,ind);
        tree[node] = tree[2*node]+tree[2*node+1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int m;
  cin>>n;
  build(1,1,n);
  cin>>m;
  int x,y;
  while(m--)
  {
    cin>>x>>y;
    if(x==0)
    {
      update(1,1,n,y);
    }
    else
    {
      int res=query(1,1,n,y);
      cout<<res<<endl;
    }
  }
  return 0;
}