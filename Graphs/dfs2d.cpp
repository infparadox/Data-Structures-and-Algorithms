#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define size 1000
bool vis[size][size];

void dfs(ll x,ll y,ll n,ll m)
{
	if(x<0 || y<0)
		return;
	if(x>=n || y>=m)
		return ;
	if(vis[x][y])
		return;
	vis[x][y]=1;
	dfs(x-1,y,n,m);
	dfs(x+1,y,n,m);
	dfs(x,y-1,n,m);
	dfs(x,y+1,n,m);
}

int main()
{
	ios::sync_with_stdio(false);
	ll n,m,i,j;
	cin >> n >> m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			vis[i][j]=0;
	}
	dfs(0,0,n,m);
	return 0;
}
