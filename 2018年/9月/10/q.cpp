#include<bits/stdc++.h>
using namespace std;

#define MAXN 2005
int n,m,q;
int c[MAXN][MAXN],d[MAXN][MAXN],a[MAXN][MAXN],b[MAXN][MAXN],e[MAXN][MAXN];

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1; i <= q; i ++)
	{
		int x,y,r;
		scanf("%d%d%d",&x,&y,&r);
		r --;
		x += r;
		c[x+1][y] --;
		c[x-r][y] ++;
		d[x-r][y+1] --;
		d[x+1][y+r+2] ++;
	}
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		b[i][j] = b[i-1][j] + c[i][j];
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		e[i][j] += e[i-1][j-1] + d[i][j];
	
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			a[i][j] = a[i][j-1] + b[i][j]+e[i][j];
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
} 
/*
5 5
2
1 2 3
2 3 3
*/
