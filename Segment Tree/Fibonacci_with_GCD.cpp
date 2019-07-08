#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int tree[100005];
int mod=1e9+7;
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
        tree[node] = __gcd(tree[2*node],tree[2*node+1]);
    }
}
int query(int node, int start, int en, int l, int r)
{
    if(r < start or en < l)
    {
        return 1e9;
    }
    if(l <= start and en <= r)
    {
        return tree[node];
    }
    int mid = (start + en) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, en, l, r);
    return __gcd(p1,p2);
}
int fib(int n) 
{ 
  int F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
    return 0; 
  power(F, n-1); 
  return F[0][0]; 
} 
  
/* Optimized version of power() in method 4 */
void power(int F[2][2], int n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  int M[2][2] = {{1,1},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 
  
void multiply(int F[2][2], int M[2][2]) 
{ 
  int x =  ((F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod)%mod; 
  int y =  ((F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod)%mod; 
  int z =  ((F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod)%mod; 
  int w =  ((F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod)%mod; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 
int main()
{
    int n,q,x,y;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        a[i]=fib(b[i]);
    build(1,1,n);
    while(q--)
    {
        cin>>x>>y;
        cout<<query(1,1,n,x,y)<<endl;
    }
}
