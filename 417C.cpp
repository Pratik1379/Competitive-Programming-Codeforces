#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    if(n<(2*k+1))
        {cout<<-1;return 0;}
    int cnt[1001]={0};
    cout<<(n*k)<<endl;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(cnt[i]<k)
            {
                printf("%d %d\n",i,j);
                cnt[i]++;
            }
            else if(cnt[j]<k)
            {
                printf("%d %d\n",j,i);
                cnt[j]++;
            }
            else
                break;
        }
    }
    return 0;
}
