#include<bits/stdc++.h>
using namespace std;

#define MAXN 105
#define db double

struct dian
{
	db x,y;
}f[MAXN*30];
struct bian
{
	int x,y,ls;
	db l;
	void qk()
	{
		x = 0;
		y = 0;
		l = 0;
	}
} b[MAXN*MAXN*30];
int cnt,t[MAXN*30];
db tt;
int A,B;
int n,nn;

void jb(int x,int y,db l) {
	cnt ++;
	b[cnt].x = x;
	b[cnt].y = y;
	b[cnt].l = l;
	b[cnt].ls = t[x];
	t[x] = cnt;
}

db ju(dian a,dian b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
} 

void jn(int x,int y,db l){
	jb(x,y,l);
	jb(y,x,l);
}

struct aa
{
	dian a,b,c,d;
	db t;
	
	void qk()
	{
		a.x = 0;
		a.y = 0;
		b.x = 0;
		b.y = 0;
		c.x = 0;
		c.y = 0;
		d.x = 0;
		d.y = 0;
		t = 0;
	}
	
	void qd()
	{
		if(ju(a,b) > ju(a,c) && ju(a,b) > ju(b,c))
		{
			d.x = a.x + b.x - c.x;
			d.y = a.y + b.y - c.y;
		}
		if(ju(a,c) > ju(b,c) && ju(a,c) > ju(b,a))
		{
			d.x = a.x + c.x - b.x;
			d.y = a.y + c.y - b.y;
		}
		if(ju(b,c) > ju(a,c) && ju(b,c) > ju(b,a))
		{
			d.x = b.x + c.x - a.x;
			d.y = b.y + c.y - a.y;
		}
	}
	
	void jt()
	{
		n ++; f[n] = a;
		n ++; f[n] = b;
		n ++; f[n] = c;
		n ++; f[n] = d;
		jn(n-3,n-2,ju(a,b)*t);
		jn(n-3,n-1,ju(a,c)*t);
		jn(n-3,n,ju(a,d)*t);
		jn(n-2,n-1,ju(b,c)*t);
		jn(n-2,n,ju(b,d)*t);
		jn(n-1,n,ju(c,d)*t);
		for(int i = 1; i <= n-4; i ++)
			for(int j = 3; j >= 0; j --)
			jn(i,n-j,ju(f[i],f[n-j])*tt); 
	}
}a[MAXN];

void rd() {
	n = 0;
	tt = 0;
	nn = 0;
	A = 0;B = 0;
	cnt = 0;
	for(int i = 0; i < MAXN; i ++)
	{
		a[i].qk();
	}
	for(int i = 0; i < MAXN*MAXN*30; i ++)
		b[i].qk();
		for(int i = 0; i < MAXN*10; i ++)
		{
			f[i].x = 0;
			f[i].y = 0;
		}
	memset(t,0,sizeof(t));
	scanf("%d",&nn);
	cin >> tt >> A >> B; 
	for(int i = 1; i <= nn; i ++) {
		cin >> a[i].a.x >> a[i].a.y >> a[i].b.x >> a[i].b.y >> a[i].c.x >> a[i].c.y >> a[i].t;
		a[i].qd();
//		cout<<a[i].d.x<<" "<<a[i].d.y<<"\n";
		a[i].jt();
	} 
}

queue<int>q;
db dis[MAXN*10];
bool inq[MAXN];

void spfa(int s) {
	for(int i = 1; i <= n; i ++)
		dis[i] = 1000000000;
	dis[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int x = q.front();
	//	cout<<x<<" "<<dis[x]<<"?\n";
		inq[x] = 0;
		q.pop();
		for(int i = t[x]; i != 0; i = b[i].ls) {
			int y = b[i].y;
			if(dis[y] > dis[x] + b[i].l) {
				dis[y] = dis[x] + b[i].l;
				if(!inq[y]) {
					inq[y] = 1;
					q.push(y);
				}
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while(T --) {
		rd();
		db ans = 1000000000;
	/*	for(int i = 1; i <= n; i ++)
		{
			cout<<i<<":"<<f[i].x<<" "<<f[i].y<<"\n";
			for(int j = t[i]; j != 0; j = b[j].ls)
				cout<<b[j].y<<" "<<b[j].l<<"|";
			cout<<"\n"; 
		}*/
		for(int i = 1; i <= 4; i ++) {
			spfa(A*4-4+i);
			for(int j = 1; j <= 4; j ++) 
			{ 
				ans = min(ans,dis[B*4-4+j]); 
			//	cout<<A*4+i<<" "<<B*4+j<<" "<<dis[B*4+j]<<"\n"; 
			} 
		}
		//cout<<"0.0\n"; 
		printf("%.1f\n",ans); 
	} 
	return 0;
}
/*
3
3 10 1 3
1 1 1 3 3 1 30
2 5 7 4 5 2 1
8 6 8 8 11 6 3
3 10 1 3
1 1 1 3 3 1 30
2 5 7 4 5 2 1
8 6 8 8 11 6 3
3 10 1 3
1 1 1 3 3 1 30
2 5 7 4 5 2 1
8 6 8 8 11 6 3


*/
