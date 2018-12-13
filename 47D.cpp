#include<bits/stdc++.h>
using namespace std;
int phi( int n)
{
    int result = 1;
    for (int i = 2; i < n; i++)
        if (__gcd(i, n) == 1)
            result++;
    return result;
}
int main()
{
int n,m;
cin>>n>>m;
int sum=0;
int fl=0;
for(int i=2;i<=n;i++)
{
    sum+=phi(i);
    if(sum>=m)
    {
        fl=1;break;
    }
}
if(fl==1 && m>=n-1)
{
   cout<<"Possible"<<endl;
   int l=0;
   for(int i=2;i<=n;i++)
   {
       cout<<1<<" "<<i<<endl;
       l++;
   }
   if(l>=m)
        return 0;
   for(int i=2;i<n;i++)
   {
       for(int j=i+1;j<=n;j++)
       {
        if(__gcd(i,j)==1)
        {

            cout<<i<<" "<<j<<endl;
            l++;
        if(l>=m)
            return 0;
        }
       }
   }
}
else
{
    cout<<"Impossible"<<endl;
}
return 0;
}
