#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> g,h;
    long int sum=0;
    int i,j;
    i=1;
    int pos=-1;
    int fl=0;
    if(n>m)
    {
      int tem=n;
      n=m;
      m=tem;
      fl=1;
    }
    while(sum<=n)
    {
      if((sum+2*i+1)>n && (sum+i)<=n)
      {
        pos=n-sum;
        g.push_back(pos);
        j=i;
        break;
      }
      else if((sum+2*i+1)<=n)
        {
          g.push_back(i);
          sum+=i;
          i++;
        }
      else
        break;
    }
    sum=0;
    j=i;
    while(sum<=m)
    {
      if((sum+j)<=m && j!=pos)
        {h.push_back(j);
        sum+=j;
        }
      else if(j!=pos)
        break;
      j++;
    }
    int r1=g.size();
    int r2=h.size();
    if(fl==0)
    {
    cout<<r1<<endl;
    for(int i=0;i<r1;i++)
        cout<<g[i]<<" ";
    cout<<endl;
    cout<<r2<<endl;
    for(int i=0;i<r2;i++)
        cout<<h[i]<<" ";
    }
    else
    {
      cout<<r2<<endl;
    for(int i=0;i<r2;i++)
        cout<<h[i]<<" ";
    cout<<endl;
    cout<<r1<<endl;
    for(int i=0;i<r1;i++)
        cout<<g[i]<<" ";
    }

}
