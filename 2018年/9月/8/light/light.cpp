#include<bits/stdc++.h>
using namespace std;

#define MAXN 400005
int n,i,q,wxw;
int h[MAXN],fa[MAXN],f[MAXN][22];
int t[MAXN];
struct bian
{
	int x,y,ls;
}b[MAXN];

void jb(int x,int y)
{
	i ++;
	b[i].x = x;
	b[i].y = y;
	b[i].ls = t[x];
	t[x] = i;
}

void rd()
{
	scanf("%d%d%d",&n,&q,&wxw);
	for(int i = 1; i <= n-1; i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		jb(x,y);
		jb(y,x);
		//cout<<i<<" "<<x<<" "<<y<<"\n";
	}
}

void dfs(int x)
{
	h[x] = h[fa[x]]+1;
	for(int i = t[x]; i != 0; i = b[i].ls)
	{
		int y = b[i].y;
		if(y != fa[x])
		{
			fa[y] = x;
			dfs(y);
		}
	}
}

void jianbiao()
{
	for(int i = 1; i <= n; i ++)
	{
		f[i][0] = fa[i];
	}
	for(int i = 1; i <= 20; i ++)
		for(int j = 1; j <= n; j ++)
		{
			f[j][i] = f[f[j][i-1]][i-1];
			
		}
}

int tiao(int x,int y)
{
	for(int i = 20; i >= 0; i --)
	if((1<<i) <= y)
	{
		y -= (1<<i);
		x = f[x][i];
	}
	return x;
}

int lca(int x,int y)
{
	if(h[x] > h[y]) x = tiao(x,h[x]-h[y]);
	if(h[x] < h[y]) y = tiao(y,h[y]-h[x]);
	//cout<<x<<" "<<y<<"\n";
	if(x == y) return x;
	for(int i = 20; i >= 0; i --)
	{
		if(f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		//	cout<<x<<" "<<y<<"\n";
		}
	}
	return f[x][0];
}

int main()
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	
	rd();
	dfs(1);
	jianbiao();
	/*for(int i = 1; i <= n; i ++)
	{
		for(int j = 0; j <= 3; j ++)
			cout<<f[i][j]<<" ";
		cout<<"\n";
	} */
	for(int i = 1; i <= q; i ++)
	{
		int x,y,z,xy,xz,yz,xyz;
		scanf("%d%d%d",&x,&y,&z);
		xy = lca(x,y);
		xz = lca(x,z);
		yz = lca(y,z);
		xyz = lca(xy,z);
		//cout<<xy<<" "<<xz<<" "<<yz<<" "<<xyz<<"\n";
		if(h[xyz] == h[xy])
		{
			if(h[xz] > h[xy]) printf("%d\n",h[xz] + h[y] - (h[xy]<<1) +1);
			else printf("%d\n",h[y] - h[yz] + 1);
		}
		else
		{
			printf("%d\n",h[y] - h[xy] + 1);
		} 
	}
	return 0;
} 
/*
8 100 1
1 2
1 6
6 7
4 5
2 4
3 2
8 4
3 5 8
3 7 5
1 2 3
*/

