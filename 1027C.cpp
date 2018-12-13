#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,q,x,y;
    cin>>n>>q;
    while(q--)
    {
        scanf("%lld%lld",&x,&y);
        if((x+y)&1)
        {
            long long int g=ceil((n*n*1.0)/2.0);
            long long int y1=ceil(((n*(x-1)+y)*1.0)/2.0)+g;
            cout<<y1<<endl;
        }
        else
        {
            long long  int h=ceil(((n*(x-1)+y)*1.0)/2.0);
            cout<<h<<endl;
        }
    }
}

