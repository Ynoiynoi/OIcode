#include<bits/stdc++.h>
using namespace std;

#define MAXN 300005
struct aa
{
	int l,r,v,rr;
}a[MAXN<<1];
int n,m,q;

void rd()
{
	scanf("%d%d",&n,&q);
	a[1].l = 1;a[1].r = n;a[1].v = 2; 
	m = 1;
}

void wt()
{
    for(int i = 1; i != 0; i = a[i].rr)
    {
        cout<<a[i].l<<" "<<a[i].r<<" "<<a[i].v<<"\n";
    }
    cout<<"---------------\n";
}


void he()
{
	for(int i = 1; i != 0; i = a[i].rr)
	{
		while(a[i].v == a[a[i].rr].v && a[i].rr != 0)
		{
			a[i].r = a[a[i].rr].r;
			a[i].rr = a[a[i].rr].rr;
		}
	}
}

void fen(int i,int x)
{
	m ++;
	a[m].rr = a[i].rr;
	a[i].rr = m;
	a[m].r = a[i].r;
	a[m].l = x+1;
	a[i].r = x;
	a[m].v = a[i].v;
}

void duan(int x,int y)
{
	for(int i = 1; i != 0; i = a[i].rr)
	{
		if(a[i].l <= x && a[i].r >= x)
			fen(i,x);
		else
		if(a[i].l <= y && a[i].r >= y)
			fen(i,y);
//		cout<<i<<"\n";	
	}
}

void tian(int x,int y,int v)
{
	duan(x-1,y);
	for(int i = 1; i != 0; i = a[i].rr)
	{
		if(a[i].l >= x && a[i].r <= y)
			a[i].v = v;
		//cout<<a[i].l<<" "<<a[i].r<<" "<<a[i].v<<"\n";
	}
	he();
}

int qiu()
{	
	int ans = 0;
	for(int i = 1; i != 0; i = a[i].rr)
	{
		if(a[i].v == 2)
			ans += a[i].r - a[i].l + 1;
	}
	return ans;
}

int main()
{
	rd();
	for(int i = 1; i <= q; i ++)
	{
		int x,y,l;
		scanf("%d%d%d",&x,&y,&l);
		tian(x,y,l);
		printf("%d\n",qiu());
		//wt();
	}
	return 0;
} 
/*
10 100
1 5 1
*/ 
