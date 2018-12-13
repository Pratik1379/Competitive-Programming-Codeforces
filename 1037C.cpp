#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;string a,b;
    cin>>n>>a>>b;
    long int c1=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=b[i] && a[i-1]!=b[i-1] && a[i]!=a[i-1])
        {
            c1++;
            char temp=a[i];
            a[i]=a[i-1];
            a[i-1]=temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
            c1++;
    }
    cout<<c1;
}
