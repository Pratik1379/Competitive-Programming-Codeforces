#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++)
        {cin>>a[i];
        sum+=a[i];
        }
    if(n==1 || (n==2 && a[0]==a[1]))
        cout<<-1;
    else if(n==2)
    {
        cout<<1<<endl;
        cout<<1;
    }
    else
    {
        int mini=1e6+7;
        int pos;
        for(int i=0;i<n;i++)
        {
            if(mini>a[i])
            {
                mini=a[i];
                pos=i;
            }
        }
        cout<<1<<endl;
        cout<<pos+1;
    }
    return 0;
}
