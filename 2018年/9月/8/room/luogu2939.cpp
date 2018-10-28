#include<bits/stdc++.h>
using namespace std;

#define LL long long 
#define INF (LL)0x3f3f3f3f*(LL)0x3f3f3f3f
#define MAXN 6000005
#define mk make_pair
int n,m,s,k,nn;
priority_queue< pair<LL,int> >q;
struct bian
{
	int x,y;
	int l;
	int ls;
}b[MAXN];
int t[MAXN]; 
LL dis[MAXN];
bool z[MAXN];
LL cnt;

void jb(LL x,LL y,LL l)
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
	scanf("%lld%lld%lld",&n,&m,&k); 
	s = 1;
	for(LL i = 1; i <= m; i ++)
	{
		LL x,y,l;
		scanf("%lld%lld%lld",&x,&y,&l);
		for(LL i = 0; i <= k; i ++)
		{
			jb(x+n*i,y+n*i,l);
			jb(y+n*i,x+n*i,l);
			
			if(i != k) 
			{
				jb(x+n*i,y+n*(i+1),0); 
				jb(y+n*i,x+n*(i+1),0); 
			}
		}
	} 
	nn = n;
	n += n*k;
}

int main()
{
	rd();
	memset(dis,0x3f,sizeof(dis)); 
	dis[s] = 0;
	q.push(mk(0,s)); 
	for(LL i = 1; i <= n; i ++)
	{
		LL u;
			if(q.empty()) break;
		do
		{ 
			if(q.empty()) break;
			u = q.top().second;
			q.pop();
		}while(z[u] == 1); 
		z[u] = 1;
		for(LL j = t[u]; j != 0; j = b[j].ls)
		{
			if(dis[u] + b[j].l < dis[b[j].y])
			{
			//cout<<b[j].y<<"#2333\n";
				dis[b[j].y] = dis[u] + b[j].l;
				q.push(mk(-dis[b[j].y],b[j].y)); 
			}
		}
		//cout<<u<<"\n";
	} 
	LL ans = INF;
	for(int i = 0; i <= k; i ++)
	{
		ans = min(ans,dis[nn+i*nn]);
	}
	cout<<ans; 
	return 0;
} 
/*
6 7 1
1 2 2
1 3 3
2 3 2
2 5 8
3 4 3
4 5 3
5 6 3 

*/
