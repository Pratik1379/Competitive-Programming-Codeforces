#include<bits/stdc++.h>
using namespace std;
map<string,int> a;
int main()
{
    int n,m;
    cin>>n>>m;
    string h;
    for(int i=0;i<n;i++)
    {
        cin>>h;
        a.insert(make_pair(h,1));
    }
    int check=0;
    for(int i=0;i<m;i++)
       {
            cin>>h;
            if(a.count(h))
                check++;
       }
    if(n>m)
        cout<"YES";
    else if(n==m)
    {
        if(check&1)
            cout<<"YES";
        else
            cout<<"NO";
    }
    else
        cout<<"NO";
}
