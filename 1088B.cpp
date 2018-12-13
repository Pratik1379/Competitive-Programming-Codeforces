#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int a=-1,b=-1;
    for(int i=1;i<=x;i++)
    {
        for(int j=i;j<=x;j++)
        {
            if(j%i==0)
            {
                if(((j/i)<x)&&(i*j)>x)
                {
                    a=j;b=i;break;
                }
            }
        }
        if(a!=-1)
            break;
    }
    if(a==-1)
        cout<<-1;
    else
        cout<<a<<" "<<b;
    return 0;
}

