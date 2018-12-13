#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    map<long int,int> m;
    long int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
        if(m.count(a[i])==0)
        m.insert(make_pair(a[i],1));
        else
        m[a[i]]++;
    }
    int fl=0;
    for(int i=0;i<n;i++)
    {
        long long int p=1;
        while(p<=a[i])
            p=p*2;
        int found=0;
        while(p<=(2e9+5))
        {
            long int r=p-a[i];
            if(r==a[i] && m.at(r)>1)
            {
                found=1;break;
            }
            else if(m.count(r) && r!=a[i])
            {
                found=1;break;
            }
            p=p*2;
        }
        if(found==0)
        {
            fl++;
            m[a[i]]--;
        }
    }
    cout<<fl<<endl;
}
