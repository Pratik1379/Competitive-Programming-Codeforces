#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int a[101]={0};
    while(t--)
    {
        int n,x;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            a[x]++;
        }
    }
    for(int i=1;i<=100;i++)
    {
        if(a[i]==t)
            cout<<i<<" ";
    }
}
