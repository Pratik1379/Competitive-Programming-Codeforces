#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1001];
int check[10001];
pair<int,int> a[1001];
int ans=0;
int minSwap(int i)
{
    int temp=a[arr[i]].first;
    if(temp==i)
        temp=a[arr[i]].second;
    while(temp>i+1)
    {
        ans++;
        int r=a[arr[temp-1]].first;
        if(r==temp-1)
            a[arr[temp-1]].first=temp;
        else
            a[arr[temp-1]].second=temp;
        swap(arr[temp],arr[temp-1]);
        temp--;
    }
}
int main()
{
    scanf("%d",&n);
    n=2*n;
    for(int i=1;i<=1000;i++)
        check[i]=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        if(check[arr[i]]==-1)
            check[arr[i]]=i;
        else
        {
            a[arr[i]].first=check[arr[i]];
            a[arr[i]].second=i;
        }
    }
    for(int i=1;i<n;i+=2)
    {
        if(arr[i]!=arr[i+1])
        {
            minSwap(i);
        }
    }
    cout<<ans;
    return 0;
}
