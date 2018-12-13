#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    vector<int> h;
    h.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])
        {
            h.push_back(a[i]-a[i-1]);
        }
    }
    int r1=h.size();
    if(k<=r1)
    {
        for(int i=0;i<k;i++)
            cout<<h[i]<<endl;
    }
    else
    {
        int i=0;
        while(i<r1)
        {
            cout<<h[i]<<endl;
            i++;
        }
        while(i<k)
        {
            cout<<0<<endl;
            i++;
        }
    }
    return 0;
}
