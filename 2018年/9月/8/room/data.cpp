#include<bits/stdc++.h>
using namespace std;

int n = 5000,m = 4999;

int main()
{
	srand(time(0));
	freopen("room.in","w",stdout);
	cout<<n<<" "<<m<<" "<<10<<"\n";
	for(int i = 1; i <= n; i ++)
	{		
		for(int j = 1; j <= 10; j ++)
		{
			int u = rand()%5;
			if(u) cout<<1<<" ";
			else cout<<0<<" "; 
		} 
	}
	for(int i = 1; i <= m; i ++)
	{
		if(i < n)
			cout<<i<<" "<<i+1<<" "; 
		else
			cout<<rand()%n+1<<" "<<rand()%n+1<<" "; 
		for(int j = 1; j <= 10; j ++)
		{
			int u = rand()%5;
			if(u) cout<<0<<" ";
			else cout<<1<<" "; 
		} 
	
		cout<<"\n";
	}
	return 0;
}
