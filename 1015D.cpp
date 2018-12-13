#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,k,s;
    cin>>n>>k>>s;
    if(k>s || (n-1)*k<s)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
        long long int sum=0;
        long long int l;
        l=s/(n-1);
        sum=s-l*(n-1);
        while(sum<(k-l) && l>=1)
            {l--;
            sum=s-l*(n-1);
            }
        int prev=-1;
        for(long long int i=0;i<l;i++)
        {
            if(i&1)
                {cout<<1<<" ";
                prev=1;
                }
            else
                {cout<<n<<" ";
                prev=n;
                }
        }
        if(prev==-1)
            prev=1;
        long long int last=prev;
        for(long long int i=l;i<k;i++)
        {
            if(i==k-1)
                {
                    if(prev==1)
                    cout<<sum+last<<" ";
                    else
                    cout<<last-sum<<" ";
                }
            else
            {
                if(prev==1)
                {cout<<last+1<<" ";
                last++;
                sum--;
                }
                else
                {
                    cout<<last-1<<" ";
                    last--;
                    sum--;
                }
            }
        }
    }
        return 0;
}
