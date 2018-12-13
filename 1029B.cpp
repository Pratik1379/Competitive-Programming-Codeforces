#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int maxi=0;
    int ans=0;
    int i=0;
    while(i<n-1)
    {
        int j=i;
        maxi=1;
        while(a[j]<=2*a[j+1] && j<n-1)
        {
            maxi++;
            j++;
        }
        ans=max(maxi,ans);
        i=j+1;
    }
    cout<<ans<<endl;
}
