#include<bits/stdc++.h>
using namespace std;

int n = 80000,m = n-1;

int main()
{
	freopen("light.in","w",stdout);
	srand(time(0));
	cout<<n<<" "<<m<<" "<<1<<"\n";
	for(int i = 1; i < n; i ++)
	{
		cout<<i<<" "<<i+1<<"\n";
	}
	for(int i = 1; i <= m; i++)
		cout<<(rand()*rand())%n+1<<" "<<(rand()*rand())%n+1<<" "<<(rand()*rand())%n+1<<"\n";
	return 0;
} 
