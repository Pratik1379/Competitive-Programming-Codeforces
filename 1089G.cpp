#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int d;
        cin>>d;
        int a[14];
        int s=0;
        for(int i=0;i<7;i++)
        {
            cin>>a[i];
            a[i+7]=a[i];
        }
        int total=s;
        long long int ans=-1;
        long long int h=(d/s);
        long long int r=d%s;
        vector<int> h;
        int l=18;
        for(int i=0;i<14;i++)
        {
            if(a[i]==1)
            {
                h.push_back(i);
            }
        }
        for(int i=0;i<=(h.size()-r);i++)
        {
            l=min(l,h[i+r-1]-h[i]);
        }
        if(l==18)
            l=0;
        ans=l+7*h;
        cout<<ans<<endl;
    }
    return 0;
}
