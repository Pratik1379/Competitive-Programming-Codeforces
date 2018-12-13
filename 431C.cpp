#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,d;
    cin>>n>>k>>d;
    long int mod=1e9+7;
    long long int arr[10001][2];
    for(int i=0;i<=10000;i++)
      {arr[i][0]=0;
      arr[i][1]=0;
      }
    arr[0][0]=1;
    if(d==1)
        arr[1][1]=1;
    else
        arr[1][0]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j>=d)
            {
                arr[i][1]+=arr[i-j][1]+arr[i-j][0];
            }
            else
            {
                arr[i][1]+=arr[i-j][1];
                arr[i][0]+=arr[i-j][0];
            }
            arr[i][1]%=mod;
            arr[i][0]%=mod;
        }
    }
    cout<<arr[n][1];
    return 0;
}

