#include<bits/stdc++.h>
using namespace std;
string a;int n;
string b;
long long int tree[400005][26],lazy[400005][26];
long long int maxi=1e9+7;
void build(int node, int s, int e)
{
    if(s==e)
    {
        tree[node][a[s-1]-'a']=1;
    }
    else
    {
        int mid = (s + e) / 2;
        build(2*node, s, mid);
        build(2*node+1, mid+1, e);
        for(int i=0;i<26;i++)
            tree[node][i] = tree[2*node][i]+tree[2*node+1][i];
    }
    for(int i=0;i<26;i++)
        lazy[node][i]=-1;
}
int query(int node, int start, int en, int l, int r,int ind)
{
    if(lazy[node][ind] != -1) 
    { 
        tree[node][ind] = lazy[node][ind]*(en-start+1);
        if(start != en) {
            lazy[node*2][ind] = lazy[node][ind]; 
            lazy[node*2+1][ind] = lazy[node][ind]; 
        }
 
        lazy[node][ind] = -1; 
    }
    if(r < start or en < l)
    {
        return 0;
    }
    if(l <= start and en <= r)
    {
        return tree[node][ind];
    }
    int p1,p2;
    int mid = (start + en) / 2;
    p1 = query(2*node, start, mid, l, r, ind);
    p2 = query(2*node+1, mid+1, en, l, r, ind);
    return p1+p2;
}
void update(int node, int start, int en, int l,int r,int val,int ind)
{
    if(lazy[node][ind] != -1) 
    {
        tree[node][ind] = lazy[node][ind]*(en-start+1);
        if(start != en) 
        {
            lazy[node*2][ind] = lazy[node][ind];
            lazy[node*2+1][ind] = lazy[node][ind];     
        }
        lazy[node][ind] = -1;
    }
    if(r < start or en < l)
        return;
    if(l<=start && en<=r) 
    {
        tree[node][ind]=val*(en-start+1);
        if(start!=en)
        {
            lazy[node*2][ind] = val;lazy[node*2+1][ind] = val;
        }
        return;
    }
    int mid=(start+en)/2;
    update(2*node,start,mid,l,r,val,ind);
    update(2*node+1,mid+1,en,l,r,val,ind);
    tree[node][ind] = tree[2*node][ind]+tree[2*node+1][ind];
}
int main()
{
    int m,l,r,y;
    cin>>n>>m;
    cin>>a;
    build(1,1,n);
    while(m--)
    {
        cin>>l>>r>>y;
        int cnt[26]={0};
        for(int i=0;i<26;i++)
        {
            cnt[i]=query(1,1,n,l,r,i);
            update(1,1,n,l,r,0,i);
        }
        int indx;
        if(y==1)
        {    
            indx=l;
            for(int i=0;i<26;i++)
            {
                update(1,1,n,indx,indx+cnt[i]-1,1,i);
                indx=indx+cnt[i];
            }
        }
        else
        {
            indx=r;
            for(int i=0;i<26;i++)
            {
                update(1,1,n,indx-cnt[i]+1,indx,1,i);
                indx=indx-cnt[i];
            }
        }
    }
    b="";
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++)
        {
            int y1=query(1,1,n,i,i,j);
            //cout<<y1<<"##";
            if(y1==1)
            {
                b=b+(char)('a'+j);break;
               // cout<<i<<"**";
            }
        }
    }
    cout<<b;
    return 0;
}