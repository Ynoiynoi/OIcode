#include<bits/stdc++.h>
using namespace std;

#define MAXN 15

string s[MAXN][MAXN];
string a[MAXN],b[MAXN];
int n,m;
int c[MAXN];
int p[233]; 

int main() {	
	cin >> n;
	n --;
	string sb;
	cin >> sb; 
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 0; i <= 232; i ++)
		p[i] = rand()*rand();
	for(int i = 1; i <= n; i ++){
		cin >> b[i];
		for(int j = 1; j <= n; j ++){
			cin >> s[i][j];
			if(s[i][j].size() == 2){
				c[i] ++;	
			}
			if(s[i][j].size() > 2){
				cout<<"ERROR!";
				return 0;
			}
		}
		p[b[i][0]] = c[i];
		//cout<<i<<" "<<c[i]<<"\n";
	} 
	//cout<<p['L']<<"\n";
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
		{
			int u = p[b[i][0]] + p[a[j][0]];
			//cout<<i<<" "<<j<<" "<<u<<"\n";
			if(s[i][j].size() == 1 && u >= n)
			{
				cout<<"ERROR!";
				return 0;
			}
			if(s[i][j].size() == 2 && u < n){
				cout<<"ERROR!";
				return 0;
			}else{
			//	cout<<s[i][j][0]<<"£¿£¿£¿\n"; 
				if(s[i][j].size() == 2)
				{
					if(p[s[i][j][1]] != u%n){
					//	cout<<"?!"<<" "<<p[s[i][j][0]]<<" "<<u%n<<"\n";
						cout<<"ERROR!";
						return 0;
					}
					else {
						if(p[s[i][j][0]] != u/n)
						{
					//		cout<<"??\n";
							cout<<"ERROR!";
							return 0;
						}	
					} 
				}
				else{
					if(p[s[i][j][0]] != u%n){
					//	cout<<"?!"<<" "<<p[s[i][j][0]]<<" "<<u%n<<"\n";
						cout<<"ERROR!";
						return 0;
					}
				}
			}	
		}
	for(int i = 1; i <= n; i ++)
		cout<<a[i]<<"="<<p[a[i][0]]<<" ";
	cout<<"\n"<<n<<"\n";
	return 0;
}
/*
5
+ L K V E
L L K V E
K K V E KL
V V E KL KK
E E KL KK KE

*/
