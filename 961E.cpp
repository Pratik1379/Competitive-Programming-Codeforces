#include<bits/stdc++.h>
using namespace std;
int bits[200005];
vector<int> v[200005];
long int n;
void update(int x,int delta)
{
    for(; x <= n; x += x&-x)
        bits[x] += delta;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += bits[x];
     return sum;
}
int main()
{
    scanf("%ld",&n);
    long int a[n];int x1;
    for(int i=0;i<n+2;i++)
        bits[i]=0;
    for(int i=0;i<n;i++)
     { scanf("%ld",&a[i]);
        if(a[i]>n)
            a[i]=n;
     }
    long int sum1=0;
    for(int i=0;i<n;i++)
       {
           if(a[i]<=n)
                v[a[i]].push_back(i+1);
            update(a[i],1);
        }
    for(int i=1;i<=n;i++)
    {
            int y=min(n,a[i]);
            sum1+=query(y);
            for(auto x:v[i])
            update(x,-1);
    }
    for(int i=1;i<=n;i++)
    {
        if(i<=a[i-1])
            sum1--;
    }
    sum1=sum1/2;
    cout<<sum1<<endl;
}

