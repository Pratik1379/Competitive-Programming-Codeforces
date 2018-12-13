#include<bits/stdc++.h>
using namespace std;
int n,x,y;
string s;
long int sum;
pair<int,int> p;
bool check(int start,int len)
{
    p.first=0;
    p.second=0;
    for(int j=0;j<n;j++)
    {
        if(j>=start && j<=(start+len-1))
            continue;
        if(s[j]=='R')
            p.first++;
        else if(s[i]=='L')
            p.first--;
        else if(s[i]=='D')
            p.second--;
        else
            p.second++;
    }
    int dif=abs(p.first-x)+abs(p.second-y);
    if(dif<=len && mid%2==dif%2)
        return true;
    return false;
}
int main()
{
    cin>>n>>s>>x>>y;
    sum=abs(x)+abs(y);
    if(sum>n || (n-sum)&1)
    {cout<<-1;
    return 0;
    }
    int l=0,h=n-1;
    int ans=-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        int fl=0;
        for(int j=0;j<n-mid;j++)
        {
            if(check(j,mid))
            {
                fl=1;
                ans=min(ans,mid);
                break;
            }
        }
        if(fl==0)
            l=mid+1;
        else
            h=mid-1;
    }
    return 0;
}
