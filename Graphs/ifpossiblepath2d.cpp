#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define size 100
bool vis[size][size];
ll a[size][size];

bool dfs(ll x,ll y,ll n,ll m,ll dx,ll dy)
{
	if(x==(dx) && y==(dy))
		return 1;
	if(x<0 || y<0)
		return 0;
	if(x>=n || y>=m)
		return 0;
	if(vis[x][y])
		return 0;
	if(a[x][y]==0)
		return 0;
	vis[x][y]=1;
	if(dfs(x-1,y,n,m,dx,dy))
		return 1;
	if(dfs(x+1,y,n,m,dx,dy))
		return 1;
	if(dfs(x,y-1,n,m,dx,dy))
		return 1;
	if(dfs(x,y+1,n,m,dx,dy))
		return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	ll n,m,i,j;
	cin >> n >> m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin >> a[i][j];
			vis[i][j]=0;
		}
	}
	if(dfs(0,0,n,m,n-1,m-1))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
