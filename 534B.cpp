#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v1,v2,t,d;
    cin>>v1>>v2>>t>>d;
    long int sum=0;
    int lt;
    int curr=v1,next;
    for(int i=1;i<=t;i++)
    {
        lt=t-i;
        sum+=curr;
        int y=abs(curr+d-v2);
        if(y<=lt*d)
            {next=curr+d;
            }
        else
        {
            next=v2+lt*d;
        }
        curr=next;
    }
    cout<<sum<<endl;
    return 0;
}
