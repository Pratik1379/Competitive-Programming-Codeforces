#include<bits/stdc++.h>
using namespace std;
int tree[8000005],a[2000005];
int n;
void build(int node, int s, int e)
{
    if(s==e)
    {
        if(a[s]&1)
          tree[node] = 1;
        else
          tree[node] = 0;
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
void update(int node, int s, int e,int ind,int ad)
{
    if(s<1 or e>n)
    {
        return;
    }
    if(s==e && e==ind)
    {
        tree[node] = tree[node] + ad;
    }
    else if(s<e)
    {
        int mid = (s + e) / 2;
        if(ind>=s && ind<=mid)
            update(2*node, s, mid,ind,ad);
        else
            update(2*node+1, mid+1, e,ind,ad);
        tree[node] = tree[2*node]+tree[2*node+1];
    }
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    a[i]=(a[i]%2);
  }
  build(1,1,n);
  int x,y;
  while(m--)
  {
    cin>>x>>y;
    if(x==1)
    {
      if(a[y]&1)
      {  
        update(1,1,n,y,-1);
      }
      else
         update(1,1,n,y,1);
       a[y]++;
    }
    else
    {
      int res=query(1,1,n,y);
      cout<<res<<endl;
    }
  }
  return 0;
}