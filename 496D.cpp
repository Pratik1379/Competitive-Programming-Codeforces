#include<bits/stdc++.h>
using namespace std;
int main()
{
 string st;
 cin>> st;
 int r1=st.length();
 int i=0,j;
 int sum=0,sum1=0,sum2=0;
 int temp=0;
while(i<r1)
{
    int r=(st[i]-48);
    int fl=0;
    if(r%3==0)
    {
        fl=1;
        i++;sum++;
    }
    else if(r%3==1)
    {
        int x,y;
        if(i+1<r1)
        {
        x=(st[i+1]-48);
        if(x%3==2)
        {sum++; i+=2;fl=1;}
        else if(x%3==1 && i+2<r1)
        {
            y=(st[i+2]-48);
            if(y%3==1)
            {
                sum++;i+=3;fl=1;
            }
        }
        }
    }
    else
    {
        int x,y;
        if(i+1<r1)
        {
        x=(st[i+1]-48);
        if(x%3==1)
        {sum++; i+=2;fl=1;}
        else if(x%3==2 && i+2<r1)
        {
            y=(st[i+2]-48);
            if(y%3==2)
            {
                sum++;i+=3;fl=1;
            }
        }
        }
    }
    if(fl==0)
        i++;
}
 cout<<sum<<endl;
 return 0;
}
