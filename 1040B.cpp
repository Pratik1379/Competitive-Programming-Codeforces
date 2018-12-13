#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    if(k==0)
    {
        cout<<n<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<i<<" ";
        }
        return 0;
    }
    int rem=n%(2*k);
    int ans=ceil((n*1.0)/(2.0*k));
    int start=rem/2;
    int minsteps=100000;
    for(int i=1;i<=k+1;i++)
    {
        int j=(n-i)/(2*k+1);
        int last=i+j*(2*k+1);
        if(n<=last+k)
        {
            if(minsteps>j)
            {
                minsteps=j;
                start=i;
            }
        }
    }
    cout<<minsteps<<endl;
    for(int i=0;i<ans && start<=n;i++)
    {
        cout<<start<<" ";
        start=start+(2*k+1);
    }
    return 0;
}
