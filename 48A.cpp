#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    long long int x,y;
    long long int sum=0;
    long long int curr=0;
    long long int pre;
    long long int b[n];
    for(int i=0;i<n;i++)
    {
        cin>>x;
        y=(sum+a[i])/m;
        b[i]=y-sum;
        sum+=b[i];
    }
    for(int i=0;i<n;i++)
        cout<<b[i];
}
