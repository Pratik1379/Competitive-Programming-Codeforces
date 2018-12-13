#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long int x[n][4],y[n][4];
    long int a[n][4];
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
    }
    int fl=n,gl=-1;
    x[0][0]=a[0][0];x[0][2]=a[0][2];x[0][1]=a[0][1];x[0][3]=a[0][3];
    int temp1,temp2,temp3,temp4;
    for(int i=1;i<n;i++)
    {
        temp1=max(x[i-1][0],a[i][0]);
        temp2=min(x[i-1][2],a[i][2]);
        temp3=max(x[i-1][1],a[i][1]);
        temp4=min(x[i-1][3],a[i][3]);
        if(temp1>temp2 || temp3>temp4)
        {
            fl=i;break;
        }
        else
        {
            x[i][0]=temp1;
            x[i][2]=temp2;
            x[i][1]=temp3;
            x[i][3]=temp4;
        }
    }
    y[n-1][0]=a[n-1][0];y[n-1][2]=a[n-1][2];y[n-1][1]=a[n-1][1];y[n-1][3]=a[n-1][3];
    for(int j=n-2;j>=0;j--)
    {
        temp1=max(y[i+1][0],a[i][0]);
        temp2=min(y[i+1][2],a[i][2]);
        temp3=max(y[i+1][1],a[i][1]);
        temp4=min(y[i+1][3],a[i][3]);
        if(temp1>temp2 || temp3>temp4)
        {
            gl=j;break;
        }
        else
        {
            y[i][0]=temp1;
            y[i][2]=temp2;
            y[i][1]=temp3;
            y[i][3]=temp4;
        }
    }
    for(int i=1;i<n-1;i++)
    {
        if(i>fl)
            break;
        if(gl>i)
            continue;
        else
        {
            temp1=max(y[i+1][0],x[i-1][0]);
            temp2=min(y[i+1][2],x[i-1][2]);
            temp3=max(y[i+1][1],x[i-1][1]);
            temp4=min(y[i+1][3],x[i-1][3]);
            if(temp1<=temp2 && temp3<=temp4)
            {
                cout<<temp1<<" "<<temp3<<endl;
                return 0;
            }
        }
    }
    return 0;
}

