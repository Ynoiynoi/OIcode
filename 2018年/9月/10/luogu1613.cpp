#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define INF (LL)0x3f3f3f3f*(LL)0x3f3f3f3f
#define MAXN 55 
LL f[MAXN][MAXN][MAXN];
LL a[MAXN][MAXN]; 
LL n,m;

void jianbiao()
{
	for(int i = 1; i <= 30; i ++)
	{
		for(int j = 1; j <= n; j ++)
			for(int k = 1; k <= n; k ++)
				for(int l = 1; l <= n; l ++)
				if(f[i-1][j][l] && f[i-1][l][k])
				f[i][j][k] = 1;
	}
} 

void rd()
{
	scanf("%lld%lld",&n,&m);
	for(int i = 1; i <= m; i ++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		f[0][x][y] = 1;
	}
}

int main()
{
	rd();
	jianbiao();
	memset(a,0x3f,sizeof(a));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
		{
			for(int k = 0; k <= 30; k ++)
			if(f[k][i][j])
				a[i][j] = 1;
			//cout<<i<<" "<<j<<" "<<a[i][j]<<"\n";
		}
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
			a[i][j] = min(a[i][j],a[i][k] + a[k][j]);
		cout<<a[1][n];
	return 0;
} 
/*
4 3
1 3
3 2 
2 4

6 7
1 2
2 3
1 4
3 4

4 5
5 6
3 6

*/
