#include <bits/stdc++.h>
using namespace std; 
float mymin(float d1,float d2,float d3,float d4)
{
	return min(d1,min(d2,min(d3,d4)));
}
int main()
{
	int x1,y1,x2,y2,r;
	cin>>x1>>y1>>x2>>y2>>r;
	float t1=M_PI/2,t2=M_PI/2;
	if(x1!=0)
	{
		t1=atan(y1/x1);
		if(y1==0 && x1<0)
			t1=M_PI;
	}
	else if(y1<0)
		t1=-t1;
	if(x2!=0)
	{
		t2=atan(y2/x2);
		if(y2==0 && x2<0)
			t2=M_PI;
	}
	else if(y2<0)
		t2=-t2;
	float d1 = sqrt(x1*x1+y1*y1);
	float d2 = sqrt(x2*x2+y2*y2);
	float tl1 = acos(r/d1)+t1;
	float tr1 = t1-acos(r/d1);
	float tl2 = acos(r/d2)+t2;
	float tr2 = t2-acos(r/d2);
	float dist1 = sqrt(d1*d1-r*r);
	float dist2 = sqrt(d2*d2-r*r);
	float ang = mymin(abs(tl1-tl2),abs(tl1-tr2),abs(tr1-tl2),abs(tr1-tr2));
	float ans = ang*r+dist1+dist2;
	/*cout<<t1<<" "<<t2<<" "<<tl1<<" "<<tr1<<endl;
	cout<<tl2<<" "<<tr2<<endl;*/
	printf("%0.8f",ans);
	return 0;
}