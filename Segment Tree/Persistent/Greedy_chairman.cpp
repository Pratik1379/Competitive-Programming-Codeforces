#include<bits/stdc++.h>
using namespace std;
#define MAXN 200000
int n;
long long int mod=1e9+7;
long long int fact[MAXN+5],ifact[MAXN+5];
int a[MAXN+5],b[MAXN+5];
vector<int> tree[4*MAXN+5];
struct myn{
  int count;
  myn *left;myn *right;
  myn(int v,myn* l, myn* r) 
    { 
        left = l; 
        right = r; 
        count = v; 
    } 
  myn* insert(int l, int r, int w);
};
myn* root[MAXN];
myn* null = new myn(0,NULL,NULL);
myn * myn::insert(int l, int r, int w)
{
  if(l <= w && w <= r)
  {
    if(l == r)
    {
      return new myn(this->count+1, null, null);
    }
    int m = (l+r)>>1;
    return new myn(this->count+1, this->left->insert(l, m, w), this->right->insert(m+1, r, w));
  }
  return this;
}
int query(myn *a, myn *b, int l, int r, int k)
{
  if(l==r)
  {
    return l;
  }
  int m = (l+r)>>1;
  int count = a->left->count - b->left->count;
  if(count >= k)
    return query(a->left, b->left, l, m, k);
  return query(a->right, b->right, m+1, r, k-count);
}
void build(int node, int s, int e)
{
    if(s==e)
    {
        tree[node].push_back(a[s]);
    }
    else
    {
        int mid = (s + e) / 2;
        build(2*node, s, mid);
        build(2*node+1, mid+1, e);
        int r1=tree[2*node].size();
        int r2=tree[2*node+1].size();
        int i=0,j=0;
        while(i<r1 && j<r2)
        {
            if(tree[2*node][i]==tree[2*node+1][j])
            {
              tree[node].push_back(tree[2*node][i]);
              tree[node].push_back(tree[2*node][i]);
              i++;j++;
            }
            else if(tree[2*node][i]<tree[2*node+1][j])
            {
              tree[node].push_back(tree[2*node][i]);i++;
            }
            else
            {
              tree[node].push_back(tree[2*node+1][j]);j++;
            }
        }
        while(i<r1)
        {
            tree[node].push_back(tree[2*node][i]);i++;
        }
        while(j<r2)
        {
            tree[node].push_back(tree[2*node+1][j]);j++;
        }
    }
}
int query2(int node, int start,int en,int l, int r, int k)
{
    if(l<1 or r>n or r<start or l>en)
    {
        return 0;
    }
    if(l<=start && en<=r)
    {
        return lower_bound(tree[node].begin(),tree[node].end(),k)-tree[node].begin();
    }
    int mid=(start+en)/2;
    return query2(2*node, start,mid,l, r, k)+query2(2*node+1, mid+1,en,l, r, k);
}
long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y); 
long long modInverse(long long int a, long long int m) 
{ 
  long long int x, y; 
  long long int g = gcdExtended(a, m, &x, &y); 
  long long int res = (x%m + m) % m; 
  return res; 
} 
long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y) 
{ 
  if (a == 0) 
  { 
    *x = 0, *y = 1; 
    return b; 
  } 
  long long int x1, y1;
  long long int gcd = gcdExtended(b%a, a, &x1, &y1); 
  *x = y1 - (b/a) * x1; 
  *y = x1; 

  return gcd; 
} 
void pre()
{
  fact[0]=1;
  for(long long int i=1;i<=MAXN;i++)
    fact[i]=(fact[i-1]*i)%mod;
  ifact[MAXN]=modInverse(fact[MAXN],mod);
  for(long long int i=MAXN-1;i>=0;i--)
    ifact[i]=((i+1)*ifact[i+1])%mod;
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  pre();
  int m;
  cin>>n>>m;
  vector<pair<int,int>> v;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];v.push_back({a[i],i});
  }
  sort(v.begin(),v.end());
  for(int i=0;i<n;i++)
  {
    b[v[i].second]=i+1;
  }
  null->left=null;null->right=null;
  for(int i=1;i<=n;i++)
    root[i] = (i == 1 ? null : root[i-1])->insert( 1, n, b[i]);
  build(1,1,n);
  int lx,rx,kx;
  while(m--)
  {
    cin>>lx>>rx>>kx;
    int ans = query(root[rx], (lx==1?null:root[lx-1]), 1, n, kx);
    int c1 = v[ans-1].first;
    int c2 = query2(1,1,n,lx,rx,c1+1);
    int c3 = query2(1,1,n,lx,rx,c1);
    //cout<<kx<<" "<<c2<<"**"<<c3<<endl;
    long long int ans2=(fact[c2-c3]*ifact[kx-c3])%mod;
    ans2=(ans2*ifact[c2-kx])%mod;
    cout<<ans2<<endl;
  }
  return 0;
}