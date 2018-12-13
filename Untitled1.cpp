#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[2][9];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<9;j++)
            a[i][j]=0;
    }
    string st;
    for(int i=0;i<n;i++)
    {
        cin>>st;
        if(st=="S")
            a[0][0]++;
        else if(st=="M")
            a[0][1]++;
        else if(st=="L")
            a[0][2]++;
        else if(st=="XS")
            a[0][3]++;
        else if(st=="XL")
            a[0][4]++;
        else if(st=="XXS")
            a[0][5]++;
        else if(st=="XXL")
            a[0][6]++;
        else if(st=="XXXS")
            a[0][7]++;
        else if(st=="XXXL")
            a[0][8]++;
    }
    for(int i=0;i<n;i++)
    {
        cin>>st;
        if(st=="S")
            a[1][0]++;
        else if(st=="M")
            a[1][1]++;
        else if(st=="L")
            a[1][2]++;
        else if(st=="XS")
            a[1][3]++;
        else if(st=="XL")
            a[1][4]++;
        else if(st=="XXS")
            a[1][5]++;
        else if(st=="XXL")
            a[1][6]++;
        else if(st=="XXXS")
            a[1][7]++;
        else if(st=="XXXL")
            a[1][8]++;
    }
    int dif1=abs(a[1][0]-a[0][0]);
    int dif2=abs(a[1][1]-a[0][1]);
    int dif3=abs(a[1][2]-a[0][2]);
    int ans=max(dif1,max(dif2,dif3));
    dif1=abs(a[1][3]-a[0][3]);
    dif2=abs(a[1][4]-a[0][4]);
    ans+=(max(dif1,dif2));
    dif1=abs(a[1][5]-a[0][5]);
    dif2=abs(a[1][6]-a[0][6]);
    ans+=(max(dif1,dif2));
    dif1=abs(a[1][7]-a[0][7]);
    dif2=abs(a[1][8]-a[0][8]);
    ans+=(max(dif1,dif2));
    cout<<ans;
    return 0;
}
