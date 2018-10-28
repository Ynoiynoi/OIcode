#include<bits/stdc++.h>
using namespace std;

#define MAXN 50005
int n;
int a[MAXN],c[MAXN];
int l[MAXN],r[MAXN];
bool b[MAXN];

void rd()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d",&l[i],&r[i]);
	}
}

int main() {
	rd();	
	int x = 1;
	for(int i = 1; i <= n; i ++) {
		a[i] = x;
		b[x] = 1;
	//	cout<<i<<" "<<x
		if(i == n) break;
		if(!b[r[x]]) x = r[x];
		else
		if(!b[l[x]]) x = l[x];
		else {
			cout<<-1;
			return 0;
		}
	}
	for(int i = 1; i <= n; i ++)
		c[(a[i]-i+n)%n] ++;
	int ans = 0;
//	for(int i = 1; i <= n; i ++)
//		cout<<ans <<"\n";
	for(int i = 0;i < n; i ++)
		ans = max(ans,c[i]);
	for(int i = 1;i <= (n>>1); i ++)
		swap(a[n-i+1],a[i]);
	memset(c,0,sizeof(c));
	for(int i = 1; i < n; i ++)
		c[(a[i]-i+n)%n] ++;
	for(int i = 0;i < n; i ++)
		ans = max(ans,c[i]);
	cout<<n-ans; 
	return 0;
}
/*
6
6 2
1 3
4 2
3 5
6 4
1 5
*/
