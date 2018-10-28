#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	n = 500,m = 500;
	cout<<n+500<<" "<<m+500<<"\n";
	int q = 100000;
	for(int i = 1; i <= q; i ++)
	{
		int x = rand()%n+1,y = rand()%n+1,len = rand()%500+1;
		cout<<x<<" "<<y<<" "<<len<<"\n";
	}
	return 0;
}
