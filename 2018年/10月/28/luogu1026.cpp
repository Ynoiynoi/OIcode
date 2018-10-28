#include<bits/stdc++.h>
using namespace std;
#define MAXN 205
int p,n,m,k;
int f[MAXN][MAXN],ss[MAXN][MAXN];
string s,a[MAXN];

bool cc(int l,int r)
{
    string x = s.substr(l,r-l+1);
    for(int i = 1;i <= n; i ++)
	if(x.find(a[i]) == 0)
		return 1;
    return 0;
}
void csh()
{
    string sb;
    s += ' ';
    cin >> p >> k;
    for(int i = 1; i <= p; i++)
	{
        cin >> sb;
        s += sb;
    }
    cin >> n; 
	m=s.length()-1;
    for(int i = 1;i <= n; i ++)
		cin >> a[i];
    for(int i = m;i >= 1; i --)
    for(int j = i;j >= 1; j --)
	{
        ss[j][i] = ss[j+1][i];
        if(cc(j,i))
			ss[j][i]++;
    }
}
void suan()
{
    for(int i = 1;i <= m; i ++)
		f[i][1] = ss[1][i];
    for(int i = 1;i <= k; i ++)
		f[i][i] = f[i-1][i-1]+ss[i][i];
    for(int i = 1;i <= m; i ++)
	    for(int j = 1;j <= k && j < i; j ++)
		    for(int l = j;l < i;l ++)
		    f[i][j] = max(f[l][j-1]+ss[l+1][i],f[i][j]);
}
int main(){
    csh();
    suan();
    printf("%d\n",f[m][k]);
    return 0;
}
