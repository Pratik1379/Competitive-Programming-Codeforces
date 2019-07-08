    #include<bits/stdc++.h>
    using namespace std;
    int a[100005];
    int b[1000005];
    int tree[400005][200];
    struct st{
      int pass[200];  
    };
    void build(int node, int s, int e)
    {
        if(s==e)
        {
            tree[node][b[a[s]]]=1;
        }
        else
        {
            int mid = (s + e) / 2;
            build(2*node, s, mid);
            build(2*node+1, mid+1, e);
            for(int i=1;i<200;i++)
                tree[node][i] = tree[2*node][i]+tree[2*node+1][i];
        }
    }
    st query(int node, int start, int en, int l, int r)
    {
        if(r < start or en < l)
        {
            st p3;
            memset(p3.pass,0,sizeof(p3.pass));
            return p3;
        }
        if(l <= start and en <= r)
        { 
            st p3;
            for(int i=1;i<200;i++)
                p3.pass[i]=tree[node][i];
            return p3;
        }
        int mid = (start + en) / 2;
        st temp1 = query(2*node, start, mid, l, r);
        st temp2 = query(2*node+1, mid+1, en, l, r);
        st p3;
        for(int i=1;i<200;i++)
            p3.pass[i]=temp1.pass[i]+temp2.pass[i];
        return p3;
    }
    void sieve()
    {
        b[1]=1;
        for(int i=2;i<=1000000;i++)
            b[i]=2;
        for(int i=2;i*i<=1000000;i++)
        {
            for(int j=2*i;j<=1000000;j+=i)
            {
                b[j]++;
            }
        }
    }
    int main()
    {
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
        sieve();
        int n,q,l,r;
        cin>>n;
        int y;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cin>>q;
        cout<<endl;
        build(1,1,n);
        while(q--)
        {
            cin>>l>>r;
            st rez;
            rez = query(1,1,n,l,r);
            long long int ans=0;
            for(int i=1;i<200;i++)
            {
                if(rez.pass[i]>1)
                {
                    ans=ans+(rez.pass[i]*(rez.pass[i]-1)*1LL)/2;
                }
            }
            cout<<ans<<endl;
        }
        return 0;
    }