#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int l,r;
    while(n--)
    {
        cin>>l>>r;
        long long int ans=l;
        bitset<64> a;
        long long int p=1;
        for(int i=0;i<64;i++)
        {
            if(a[i]==0)
            {
                if((ans+p)>r)
                    break;
                else
                    ans=ans+p;
            }
            p=p*2;
        }
    }
}
