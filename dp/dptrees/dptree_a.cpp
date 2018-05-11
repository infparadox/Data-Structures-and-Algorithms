#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define si 100001
ll val[si],dp[si];
bool vis[si];

void print(vector< list<ll> >&G,ll V)
{
	for(ll i=1;i<=V;i++)
	{
		cout << i << ": ";
		for(auto it=G[i].begin();it!=G[i].end();it++)
			cout << *it << " ";
		cout << "\n";
	}
}

void dfs(vector< list<ll> >&G,ll s)
{
	vis[s]=1;
	dp[s]=val[s];
	ll ma=0;
	for(auto it=G[s].begin();it!=G[s].end();it++)
	{
		if(!vis[*it])
		{
			dfs(G,*it);
			ma=max(ma,dp[*it]);
		}
	}
	dp[s]+=ma;
}

int main()
{
	ios::sync_with_stdio(false);
	ll V,E;
	cin >> V ;
	vector< list<ll> >G(V+1);
	ll i,j;
	E=V-1;
	for(i=1;i<=E;i++)
	{
		ll u,v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(i=1;i<=V;i++)
		cin >> val[i];
	dfs(G,1);
	print(G,V);
	for(i=1;i<=V;i++)
		cout << dp[i] << " ";
	cout << "\n";
	return 0;
}