#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define size 100002

bool vis[size];

void print(const vector< list<ll> >&G,ll v)
{
	ll i;
	for(i=0;i<v;i++)
	{
		cout << i  ;
		for(auto it=G[i].begin();it!=G[i].end();it++)
			cout << " --->" << *it ;
		cout << "\n";
	}
}
void dfs(const vector< list<ll> >&G,ll s)
{
	vis[s]=1;
	cout << s << " ";
	for(auto it=G[s].begin();it!=G[s].end();it++)
	{
		if(!vis[*it])
			dfs(G,*it);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	ll i,V,E;
	cin >> V >> E;
	vector< list<ll> >G(V);
	for(i=0;i<V;i++)
	{
		G[i].clear();
		vis[i]=0;
	}
	for(i=0;i<E;i++)
	{
		ll u,v;
		cin >> u >> v;
		G[u].push_back(v); //undirected
		G[v].push_back(u);
	}
	for(i=0;i<V;i++)
	{
		if(!vis[i])
		{
			dfs(G,i);
			cout << "\n";
		}
	}
	return 0;
}
