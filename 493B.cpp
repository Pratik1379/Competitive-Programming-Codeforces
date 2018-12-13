#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,b;
    cin>>n>>b;
    int a[n];
    vector<int> v;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int odd=0;
    int even=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]&1)
            odd++;
        else
            even++;
        if(odd==even)
            v.push_back(abs(a[i+1]-a[i]));
    }
    sort(v.begin(),v.end());
    int l=0;
    int m=0;
    for(unsigned int i=0;i<v.size();i++)
    {
        if((l+v[i])<b)
        {
            l+=v[i];
            m++;
        }
    }
    cout<<m<<endl;
    return 0;
}

