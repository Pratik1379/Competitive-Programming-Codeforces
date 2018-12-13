#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,x,y;
    cin>>n>>x>>y;
    char a[300005];
    scanf("%s",a);
    int i=0;
    long long int pl=0;
    while(i<n-1)
    {
        if(a[i]=='0' && a[i+1]=='1')
        {
            pl++;
        }
        i++;
    }
    if(a[n-1]=='0')
        pl++;
    if(pl==0)
    {cout<<0;
    return 0;
    }
    long long int cost=pl*y;
    long long int c1=(pl/3)*2*x+(pl/3)*y+(pl%3)*y;
    cost=min(cost,c1);
    if(pl%3==2)
    c1=(pl/3)*2*x+(pl/3)*y+x+y;
    cost=min(cost,c1);
    c1=(pl/2)*x+(pl/2)*y+(pl%2)*y;
    cost=min(cost,c1);
    cout<<cost;
    return 0;
}
