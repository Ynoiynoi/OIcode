#include<bits/stdc++.h>
using namespace std;

#define db double
#define MAXN 15

int n,m;
db dx,c,dc,p,x;	
struct aa
{
	db d,p;
}a[MAXN]; 
db u;

bool cmp(aa a,aa b){
	return a.d < b.d;
} 

void rd() {
	scanf("%lf%lf%lf%lf%d",&dx,&c,&dc,&p,&n);
	a[1].p = p;
	for(int i = 1; i <= n; i ++)
		scanf("%lf%lf",&a[i+1].d,&a[i+1].p);
	a[n+2].d = dx;
	sort(a+1,a+n+1,cmp);
}


int main() {
	rd();
	db ans  = 0;
	for(int i = 1; i <= n+1;) {
		if(a[i+1].d-a[i].d > c*dc) {
			cout<<"No Solution\n"; 
			return 0;
		}
		int o = 0;
		for(int j = i+1; j <= n+2; j ++) {
			if(a[j].p < a[i].p && a[j].d - a[i].d <= x*dc)
			{
				o = j;
				break;
			}	
		} 
		 if(o == 0) {
		 	for(int j = i+1; j <= n+2; j ++) {
			 	if(a[j].p < a[i].p && a[j].d - a[i].d <= c*dc) {
			 		o = j;
			 		break;
			 	} 
			 }
			 if(o != 0)
			 { 
			 	ans += ((a[o].d-a[i].d)/dc - x)*a[i].p;
			 	i = o; 
			 	x = 0;
			 }else {
			 	ans += (c - x)*a[i].p; 
			 	x = c - (a[i+1].d-a[i].d)/dc;
			 	i ++;
			 } 
		 }else {
		 	x -= (a[o].d-a[i].d)/dc; 
		 	i = o;
		 }
		 
	}
	printf("%.2lf",ans);
	return 0;
} 
/*

*/
