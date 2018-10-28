#include<bits/stdc++.h>
using namespace std;

#define MAXN 10000005 
#define LL long long 
int a[MAXN],b[MAXN];
int q,n,m;

int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	
	for(int i = 2; i <= MAXN-4; i ++)
	{
		if(!b[i])
		{
			m ++;
			a[m] = i;
		}
		for(int j = 1; j <= m; j ++)
		{
			if((LL)i*(LL)a[j] > (LL)MAXN) break;
			b[i*a[j]] = i;
			if(i%a[j] == 0)
				break;
		}
	}
	for(int i = 1; i <= MAXN-4; i ++)
	{
		a[i] = a[i-1];
		if((b[i] == 0 || b[b[i]] == 0) && i != 1)
			a[i] ++;
	} 
	cin >> q;
	for(int i = 1; i <= q; i ++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",a[r] - a[l-1]);
	}
	return 0;
} 
