#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int dif[n-1];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        dif[i-1]=a[i]-a[i-1];
    }
    int i=0,j;
    int pre;
    if(dif[i]!=0)
        {pre=dif[i];
        j=1;
        }
    else
    {
        for(int l=1;l<n-1;l++)
        {
        if(dif[l]!=0)
        {
            j=l;break;
        }
        }
        pre=dif[j];
        j++;
    }
    int length=0;
    while(i<n-1 && j<n-1)
    {
        if(dif[j]==pre)
        {
            length=max(length,j-i+1);
            while(pre==dif[i])
                i++;
            i--;
            pre=dif[i];
            j=i+1;
        }
        else
        {
            j++;
        }
    }
    length=max(length,j-i+1);
    cout<<length;
    return 0;
}
