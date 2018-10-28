#include<iostream>
#include<cstdio>
using namespace std;
int hypotenuse[1001][1001];
int right_angle_edge[1001][1001];
int n,m,k;
void init(int nx,int ny,int l)
{
    right_angle_edge[nx][ny]++;
    right_angle_edge[nx+l][ny]--;
    hypotenuse[nx][ny+1]--;
    hypotenuse[nx+l][ny+l+1]++;
}
template<typename T>
inline void getint(T &num){
    char ch;
    while(!isdigit(ch = getchar()));
    num = ch - '0';
    while(isdigit(ch = getchar())) num = (num << 1) + (num << 3) + ch - '0';
}
void gr()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            right_angle_edge[i][j]+=right_angle_edge[i-1][j];
        }
    }
    for (int l=1;l<=n;l++)
        for (int x=l,y=1;x<=n&&y<=m;x++,y++)
        {
            hypotenuse[x][y]+=hypotenuse[x-1][y-1];
        }
    for (int l=2;l<=m;l++)
        for (int x=1,y=l;x<=n&&y<=m;x++,y++)
        {
            hypotenuse[x][y]+=hypotenuse[x-1][y-1];
        }
}
void outp()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            if (j==m) 
        right_angle_edge[i][j]=right_angle_edge[i][j]+right_angle_edge[i][j-1]+hypotenuse[i][j],printf("%d \n",right_angle_edge[i][j]);
            else 
        right_angle_edge[i][j]=right_angle_edge[i][j]+right_angle_edge[i][j-1]+hypotenuse[i][j],printf("%d ",right_angle_edge[i][j]);
    }
}
int main()
{
    cin>>n>>m;
    cin>>k;
    for (int i=1;i<=k;i++)
    {
        int ta,tb,tl;
        getint(ta);
        getint(tb);
        getint(tl);
        init(ta,tb,tl);
    }
    gr();
    outp();
}

