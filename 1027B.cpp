#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int cnt[10001]={0};
        int fl=0;
        vector<int> h;
        int n,x;
        scanf("%d",&n);
        int myx,myy;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            cnt[x]++;
            if(cnt[x]==2)
            {
                h.push_back(x);
            }
            else if(cnt[x]==4)
            {
                fl=1;
                myx=x;myy=x;
            }
        }
        if(fl==1)
        {
            printf("%d %d %d %d\n",myx,myx,myy,myy);
            continue;
        }
        int r1=h.size();
        sort(h.begin(),h.end());
        double check=1e9;
        for(int i=0;i<r1-1;i++)
        {
            double j1=double((h[i]+h[i+1])*(h[i]+h[i+1]));
            double j2=double(h[i]*h[i+1]);
            double j=j1/j2;
            if(j<check)
            {
                check=j;
                myx=h[i];myy=h[i+1];
            }
        }
        printf("%d %d %d %d\n",myx,myx,myy,myy);
    }
}

