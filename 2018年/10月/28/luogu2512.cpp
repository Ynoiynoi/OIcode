#include<bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1000005
LL n,a[MAXN],b,s[MAXN];
int main()
{
    scanf("%lld",&n);
    for(int i = 1;i <= n; i ++)
	{
		scanf("%lld",&a[i]);
		b += a[i];
	}
	b /= n;
    for(int i = 1;i <= n;i ++)
	{
		s[i] = s[i-1]+a[i]-b;
		a[i] -= b;
	}
	sort(s+1,s+n+1);
    int ans = 0;
    for(int i = 1; i <= n; i ++)
		ans += abs(s[(n>>1)+1]-s[i]);
    printf("%d",ans);
    
    return 0;
}
