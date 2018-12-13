#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,m,a,b;
        long long int x[4],y[4];
        cin>>n>>m;
        for(int i=0;i<4;i++)
            cin>>x[i]>>y[i];
        long long int g=(y[1]-y[0]+1)*(x[1]-x[0]+1);
        long long int h=(y[3]-y[2]+1)*(x[3]-x[2]+1);
        if((x[0]+y[0])%2==0)
          a=g/2;
        else
          a=ceil((g*1.0)/2.0);
        if((x[2]+y[2])%2==0)
          b=ceil(h*1.0/2.0);
        else
          b=h/2;
        long long int r[2],s[2];
        r[0]=max(x[0],x[2]);
        r[1]=min(x[1],x[3]);
        s[0]=max(y[0],y[2]);
        s[1]=min(y[1],y[3]);
        long long int c=0,l=0;
        if(r[0]<=r[1] && s[0]<=s[1])
        {
            l=(r[1]-r[0]+1)*(s[1]-s[0]+1);
            if((r[0]+s[0])%2==0)
            c=ceil((l*1.0)/2.0);
            else
            c=l/2;//white
            //c=l-c;
        }
        cout<<l<<" "<<c<<" "<<a<<" "<<b<<endl;
        long long int bl=(n*m)/2;
        long long int wh=(n*m)-bl;
        bl=bl-(a-b-c);
        wh+=(a-b-c);
        cout<<wh<<" "<<bl<<endl;
    }
    return 0;
}
