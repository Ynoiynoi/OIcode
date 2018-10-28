#include<bits/stdc++.h>
using namespace std;

#define MAXN 6005
int n,m,k;
struct bian
{
	int x,y,l,ls;
}b[MAXN];
int t[MAXN],cnt;
int a[MAXN];
int z[MAXN][2050];
struct aa
{
	int x,y;
};
queue<aa>q;

inline aa rr(int x,int y)
{
	aa a;
	a.x = x;
	a.y = y;
	return a;
}

void jb(int x,int y,int l)
{
	cnt ++;
	b[cnt].x = x;
	b[cnt].y = y;
	b[cnt].l = l;
	b[cnt].ls = t[x];
	t[x] = cnt;
}

void rd()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= k; j ++)
		{
			int u;
			scanf("%d",&u);
			a[i] |= (u<<(j-1));
			//cout<<j<<" "<<(u<<(j-1))
		}
		//cout<<i<<" "<<a[i]<<"\n";
	}
	for(int i = 1; i <= m; i ++)
	{
		int x,y,l = 0;
		scanf("%d%d",&x,&y);
		for(int j = 1; j <= k; j ++)
		{
			int u;
			scanf("%d",&u);
			l |= (u<<(j-1));
		}
		jb(x,y,l);
	}
}

bool guo(int x,int y)
{
	while(x != 0 || y != 0)
	{
		if((y&1) && ((x&1) == 0)) return 0;
		x >>= 1;y >>= 1;
	}
	return 1;
}

int main()
{
	freopen("room.in","r",stdin);
	freopen("room.out","w",stdout);
	
	rd();
	q.push(rr(1,a[1]));
	z[1][a[1]] = 1;
	while(!q.empty())
	{
		int ox = q.front().x,oy = q.front().y;
	//	if(ox > 0)
	//	cout<<ox<<" "<<oy<<"\n";
		q.pop();
		for(int i = t[ox]; i != 0 ; i = b[i].ls)
		{
			int y = b[i].y;
			if(guo(oy,b[i].l))
			{
				if(!z[y][oy|a[y]])
				{
					z[y][oy|a[y]] = z[ox][oy] + 1;
					q.push(rr(y,oy|a[y]));
					if(y == n)
					{
						cout<<z[y][oy|a[y]]-1;
						return 0;
					}
				}
			}
		}
	}
	cout<<"No Solution"; 
	return 0;
} 
/*
3 3 2  
1 0  
0 1 
0 0  
1 3 1 1  
1 2 1 0  
2 3 1 1
*/
