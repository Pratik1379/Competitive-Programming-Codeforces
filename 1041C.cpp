#include<bits/stdc++.h>
using namespace std;
long int a[200001];
bool vis[2000001]={false};
int ceilSearch(int low, int high,long int x)
{
  int mid;
  if(x <= a[low] && !vis[low])
    return low;
  if(x<=a[low])
    return ceilSearch(low+1, high, x);
  if(x > a[high])
    return -1;
  mid = (low + high)/2;
  if(a[mid] == x && !vis[mid])
    return mid;
  else if(a[mid] < x)
  {
    if(mid + 1 <= high && x <= a[mid+1] && !vis[mid+1])
      return mid + 1;
    else
      return ceilSearch(mid+1, high, x);
  }
  else
  {
    if(mid - 1 >= low && x > a[mid-1] && !vis[mid])
      return mid;
    else
      return ceilSearch(low, mid - 1, x);
  }
}
int main()
{
    int n;long int m1,d;
    cin>>n>>m1>>d;
    long int c[n];
    d++;
    int p=0;
    map<long int,int> m;
    for(int i=0;i<n;i++)
        {cin>>a[i];
        c[i]=a[i];
        m.insert(make_pair(a[i],i));
        }
    long int b[n];
    long int l=1;
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            b[i]=l;
            int index=i;
            while(index!=-1 && index+1<n)
            {
                index=ceilSearch(index+1,n-1,a[index]+d);
                if(index==-1)
                    break;
                vis[index]=true;
                b[index]=l;
            }
            l++;
        }
    }
    cout<<l-1<<endl;
    for(int i=0;i<n;i++)
      c[m[a[i]]]=b[i];
    for(int i=0;i<n;i++)
        cout<<c[i]<<" ";
}
