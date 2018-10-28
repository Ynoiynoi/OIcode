#include<bits/stdc++.h>
using namespace std;
int n,a[25];
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n; i++)
		scanf("%d",&a[i]);
    for(int i = 1;i <= n; i ++)
    {
        if(a[i] == 0)
		{
            if((i&1) == 0)
            {
				cout<<"YES";
				return 0;
			}
            break;
        }
	}
    for(int i = n;i >= 1; i --)
    {
        if(a[i] == 0)
		{
            if(((n-i+1)&1) ==0)
			{
				cout<<"YES";
				return 0;
			}
            break;
        }
	}
    cout<<"NO";
    return 0;
}
/*
4
2 5 3 0

*/
