#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long int l[n],w[n];
    for(int i=0;i<n;i++)
        cin>>l[i]>>w[i];
    long int x=max(l[0],w[0]);
    int fl=0;
    for(int i=1;i<n;i++)
    {
        long int r1=max(l[i],w[i]);
        long int r2=min(l[i],w[i]);
        if(x>r2)
        {
            fl=1;break;
        }
        else if(x>=r1)
            x=r1;
        else
            x=r2;
    }
    if(fl==1)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
