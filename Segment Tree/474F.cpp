#include<bits/stdc++.h>
using namespace std;
struct myn
{
    int mini;int cnt;
};
myn tree[400005];
int a[100005];
int n;
void build(int node, int s, int e)
{
    if(s==e)
    {
        tree[node].mini = a[s];tree[node].cnt=1;
    }
    else
    {
        int mid = (s + e) / 2;
        build(2*node, s, mid);
        build(2*node+1, mid+1, e);
        if(tree[2*node].mini!=-1 && tree[2*node+1].mini!=-1)
        {
            if ((tree[2*node+1].mini==tree[2*node].mini))
            {
                tree[node].mini=tree[2*node+1].mini;tree[node].cnt=tree[2*node].cnt+tree[2*node+1].cnt;
            }
            else if((tree[2*node+1].mini%tree[2*node].mini)==0)
            {
                tree[node].mini=tree[2*node].mini;tree[node].cnt=tree[2*node].cnt;
            }
            else if((tree[2*node].mini%tree[2*node+1].mini)==0)
            {
                tree[node].mini=tree[2*node+1].mini;tree[node].cnt=tree[2*node+1].cnt;
            }
            else
            {
                tree[node].mini = -1;tree[node].cnt=0;
            }
        }
        else
        {
            tree[node].mini = -1;tree[node].cnt=0;
        }
    }
}
myn query(int node, int start, int en, int l,int r)
{
    if(l<1 or r>n or r<start or l>en)
    {
        myn p1;p1.mini=0;p1.cnt=0;return p1;
    }
    if(l<=start && en<=r)
    {
        return tree[node];
    }
    int mid = (start + en) / 2;
    myn p1 = query(2*node, start, mid, l, r);
    myn p2 = query(2*node+1, mid+1, en, l, r);
    myn p3;
    if(p1.mini==0)
        return p2;
    if(p2.mini==0)
        return p1;
    if(p1.mini==-1 || p2.mini==-1)
    {
        p3.mini==-1;p3.cnt=0;return p3;
    }
    if (p1.mini==p2.mini)
    {
        p3.mini=p1.mini;p3.cnt=p1.cnt+p2.cnt;
    }
    else if((p2.mini%p1.mini)==0)
    {
        p3.mini=p1.mini;p3.cnt=p1.cnt;
    }
    else if((p1.mini%p2.mini)==0)
    {
        p3.mini=p2.mini;p3.cnt=p2.cnt;
    }
    else
    {
        p3.mini = -1;p3.cnt=0;
    }
    return p3;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    int m;cin>>m;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        myn ans1=query(1,1,n,l,r);
        int ans2=(r-l+1)-ans1.cnt;
        cout<<ans2<<endl;
    }
    return 0;
}