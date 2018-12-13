#include<bits/stdc++.h>
using namespace std;
string str;
struct note{
int a,b,c;
};
note tree[3000001];
void build(int node, int s, int e)
{
    if(s==e)
    {
        tree[node].a=0;
        if(str[s]==')')
        {
            tree[node].b=0;
            tree[node].c=1;
        }
        else
        {
            tree[node].b=1;
            tree[node].c=0;
        }
    }
    else
    {
        int mid = (s + e) / 2;
        build(2*node+1, s, mid);
        build(2*node+2, mid+1, e);
        int t=min(tree[2*node+1].b,tree[2*node+2].c);
        tree[node].a = tree[2*node+1].a+tree[2*node+2].a+t;
        tree[node].b = tree[2*node+1].b+tree[2*node+2].b-t;
        tree[node].c = tree[2*node+1].c+tree[2*node+2].c-t;
    }
}
note(int node,int start,int end,int l,int r)
{
    note ret;
    ret.a=0;
    ret.b=0;
    ret.c=0;
    if(r < start or en < l)
    {
        return ret;
    }
    if(l <= start and en <= r)
    {
        ret.a=tree[node].a;
        ret.b=tree[node].b;
        ret.c=tree[node].c;
        return ret;
    }
    int mid = (start + en) / 2;
    note p1 = query(2*node+1, start, mid, l, r);
    note p2 = query(2*node+2, mid+1, en, l, r);
    int t1=min(p1.b,p2.c);
    ret.a=p1.a+p2.a+t1;
    ret.b=p1.b+p2.b-t1;
    ret.c=p1.c+p2.c-t1;
    return ret;
}
int main()
{
    cin>>s;
    int r1=s.length();
    build(0,0,r1-1);
    int m,x,y;
    cin>>m;
    while(m--)
    {
        cin>>x>>y;
        x--;y--;
        note ans=query(0,0,r1-1,x,y);
        cout<<ans.a<<endl;
    }
    return 0;
}
