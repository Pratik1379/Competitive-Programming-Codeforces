#include<bits/stdc++.h>
using namespace std;
int a[200005];int n;
long long int tree[800005],lazy[800005];
long long int maxi=1e9+7;
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
long long int query(int node, int start, int en, int l, int r)
{
    if(lazy[node] != 0) 
    { 
        tree[node] += lazy[node];
        if(start != en) {
            lazy[node*2] += lazy[node]; 
            lazy[node*2+1] += lazy[node]; 
        }
 
        lazy[node] = 0; 
    }
    if(r < start or en < l)
    {
        return maxi;
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
void update(int node, int start, int en, int l,int r,int val)
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
    if(r < start or en < l)
        return;
    if(l<=start && en<=r) 
    {
        tree[node]+=val;
        if(start!=en)
        {
            lazy[node*2] += val;lazy[node*2+1] += val;
        }
        return;
    }
    int mid=(start+en)/2;
    update(2*node,start,mid,l,r,val);
    update(2*node+1,mid+1,en,l,r,val);
    tree[node]=min(tree[2*node],tree[2*node+1]);
}
int main()
{
    scanf("%d" , &n) ; 
    for (int i =1 ; i<=n ;++i) {
        scanf("%d" ,&a[i]) ;
    }
    build(1 , 1 , n) ; 
    int q ; 
    scanf("%d" , &q) ; 
    string s ; 
    getline(cin , s) ; 
    while (q--) {
        getline(cin , s) ; 
        int sp = 0 , l = 0 , r = 0  ;
        long long int v = 1e9 ; 
        bool yes = 0 ; 
        for (int i =0; i<s.size() ; ++i) {
            if (s[i] == ' '){
                sp++ ; 
                if (sp == 2)v = 0 ; 
            continue ; 
            }
            if (sp == 0){
                    l *= 10 ;
                    l += s[i]-'0' ; 
            }else if (sp == 1){
                    r *= 10 ; 
                    r += s[i]-'0' ; 
            }else {
                if (s[i] == '-'){
                    yes = 1 ; 
                    continue ; 
                }
                    v *= 10 ; 
                    v += s[i]-'0' ; 
            }
        }
        if ( v != 1e9){
            if (yes)v*=-1 ; 
            if (r < l){
                update(1 , 1 , n , l+1 , n , v) ; 
                update(1 , 1 , n , 1 , r+1 , v) ;       
            }else 
                update(1 , 1 , n , l+1 , r+1 , v) ; 
        }else{ 
            if (r < l)
                cout<<min(query(1, 1 , n , l+1 , n) , query(1, 1 , n , 1 , r+1))<<endl ; 
            else 
               cout<<query(1, 1 , n , l+1 , r+1)<<endl ;
            
        }
    }
    return 0;
}