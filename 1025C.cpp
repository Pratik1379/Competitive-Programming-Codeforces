#include<bits/stdc++.h>
using namespace std;
vector<long int > h;
void primeFactors(long int n)
{
    int fl=0;
    while (n%2 == 0)
    {
        fl=1;
        n = n/2;
    }
    if(fl==1)
    h.push_back(2);
    for (long int i = 3; i <= sqrt(n); i = i+2)
    {
        fl=0;
        while (n%i == 0)
        {
            fl=1;
            n = n/i;
        }
        if(fl==1)
            h.push_back(i);
    }
    if (n > 2)
        h.push_back(n);
}
int main()
{
    int n;
    cin>>n;
    vector<pair<long int,long int>> v;
    long int x,y;
    for(int i=0;i<n;i++)
    {
        scanf("%ld%ld",&x,&y);
        v.push_back(make_pair(x,y));
    }
    primeFactors(v[0].first);
    int fl=0;
    int r1=h.size();
    for(int j=0;j<r1;j++)
    {
        int fl=0;
        for(int i=1;i<n;i++)
        {
        if((v[i].first%h[j])!=0 && (v[i].second%h[j])!=0 )
        {
            fl=1;break;
        }
        }
        if(fl==0)
        {
            cout<<h[j];return 0;
        }
    }
    h.clear();
    primeFactors(v[0].second);
    int fl=0;
    int r1=h.size();
    for(int j=0;j<r1;j++)
    {
        int fl=0;
        for(int i=1;i<n;i++)
        {
        if((v[i].first%h[j])!=0 && (v[i].second%h[j])!=0 )
        {
            fl=1;break;
        }
        }
        if(fl==0)
        {
            cout<<h[j];return 0;
        }
    }
    cout<<-1;
    return 0;
}

