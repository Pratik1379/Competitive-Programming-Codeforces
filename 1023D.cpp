#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    int a[n];
    bool b[200005]={false};
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> h;
    stack<int> y;
    int fl=0;
    int gl=0,cnt=0,last;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=0 && a[i]!=a[i+1])
        {
            h.push_back(a[i]);
        }
        if(a[i]==0)
        {
            cnt++;
            last=i;
        }
        if(a[i]==q)
            gl=1;
    }
    if(a[n-1]!=a[n-2] && a[n-1]!=0)
        h.push_back(a[n-1]);
    int r1=h.size();
    y.push(h[0]);
    for(int i=1;i<r1;i++)
    {
        if(y.empty())
            y.push(h[i]);
        else
        {
        int y1=s.top();
        if(y1<h[i])
           {
               if(b[h[i]])
               {
                   fl=1;break;
               }
               y.push(h[i]);
           }
        else
        {
            while(y1>h[i])
            {
                b[y1]=true;
                h.pop();
                y1=h.top();
            }
        }
        }
    }
    if(fl==1 || (gl==1 && cnt==0))
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        for(int i=0;i<n;i++)
        {
            if(a[i]!=0)
            {
                int j=i-1;
                int x=a[i];
                while(a[j]==0 && j>=0)
                {
                    a[j]=x;
                    j--;
                }
                j=i+1;
                while(a[j]==0 && j<n)
                {
                    a[j]=x;
                    j++;
                }
            }
        }
        if(gl==0)
            a[last]=q;
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
    }
}
