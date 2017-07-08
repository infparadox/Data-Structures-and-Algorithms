#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define size 100002

bool vis[size];

void print(const vector< list<ll> >&g,ll v)
{
	ll i;
	for(i=0;i<v;i++)
	{
		cout << i  ;
		for(auto it=g[i].begin();it!=g[i].end();it++)
			cout << " --->" << *it ;
		cout << "\n";
	}
}
void dfs(const vector< list<ll> >&g,ll s)
{
	vis[s]=1;
	cout << s << " ";
	for(auto it=g[s].begin();it!=g[s].end();it++)
	{
		if(!vis[*it])
			dfs(g,*it);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	ll i,V,E;
	cin >> V >> E;
	vector< list<ll> >g(V);
	for(i=0;i<V;i++)
	{
		g[i].clear();
		vis[i]=0;
	}
	for(i=0;i<E;i++)
	{
		ll u,v;
		cin >> u >> v;
		g[u].push_back(v); //undirected
		g[v].push_back(u);
	}
	for(i=0;i<V;i++)
	{
		if(!vis[i])
		{
			dfs(g,i);
			cout << "\n";
		}
	}
	return 0;
}
