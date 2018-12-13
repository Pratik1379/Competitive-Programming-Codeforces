#include<bits/stdc++.h>
using namespace std;
int cnt[1000001]={0};
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    long int a[n];
    int s=0,e=1;
    int l=1;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    cnt[a[0]]++;
    int maxi=0;
    for(int i=1;i<n;i++)
    {
        if(cnt[a[i]]>0)
            e++;
        else if(l<k)
        {
            cnt[a[i]]++;
            l++;
        }
        else
        {
            while(s<=e)
            {
                cnt[a[s]]--;
                if(cnt[a[s]]==0)
                {
                    s++;l--;break;
                }
                s++;
            }
            cnt[a[i]]++;
            l++;
        }
        e=i;
        maxi=max(maxi,e-s+1);
    }
    return 0;
}
