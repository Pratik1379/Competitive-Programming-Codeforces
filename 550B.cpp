#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;long int l,r,x;
    cin>>n>>l>>r>>x;
    long int maxi=0;
    long int mini=0;
    int y=pow(2,n);
    long int a[n];
    int fl=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=3;i<y;i++)
    {
        bitset<16> b;
        b=i;
        if(b.count()>=2)
        {
            maxi=0;mini=1e9+9;
            long int sum=0;
            fl=0;
            for(int j=0;j<n;j++)
            {
                if(b[j]==1)
                {
                    sum+=a[j];
                        if(maxi==0)
                        {
                          maxi=max(maxi,a[j]);
                        mini=min(mini,a[j]);
                        }
                        else
                        {
                            maxi=max(maxi,a[j]);
                            mini=min(mini,a[j]);
                            if((maxi-mini)<x)
                            {
                            fl=1;break;
                            }
                        }
                    }
                }
            if(fl==0 && sum>=l && sum<=r)
                {
                ans++;}
        }
    }
    cout<<ans;
}
