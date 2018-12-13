#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x;
    vector<int> h;
    long int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        sum+=x;
        if(x&1)
        h.push_back(x);
    }
    sort(h.begin(),h.end());
    if(h.size()==0)
    {
        cout<<0;
    }
    else
    {
        if(h.size()&1)
        {
            cout<<sum;
        }
        else
        {
            cout<<sum-h[0];
        }
    }
    return 0;
}
