#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define size 100000
#define INF INT_MAX

bool vis[size];
ll disc[size],par[size],low[size],chd[size];

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
ll bridges=0,tim=0;
void dfs(const vector< list<ll> >&G,ll s)
{
	vis[s]=1;
	disc[s]=low[s]=tim++;
	ll child=0;
	for(auto it=G[s].begin();it!=G[s].end();it++)
	{
		if(!vis[*it])
		{
			chd[s]=chd[s]+1;
			par[*it]=s;
			dfs(G,*it);
			low[s]=min(low[s],low[*it]);
			if(low[*it]>disc[s])
			{
				cout << *it << "-->" << s << "\n";
				bridges++;
			}
		}
		else if(par[s]!=*it)   // Back Edge
			low[s]=min(low[s],disc[*it]);
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
		vis[i]=0;   // visited
		low[i]=INF; // low time
		par[i]=-1;  // parent
		disc[i]=0;  // visited time
		chd[i]=0;   // No. of children
	}
	for(i=0;i<E;i++)
	{
		ll u,v;
		cin >> u >> v;
		G[u].push_back(v); 
		G[v].push_back(u); //undirected
	}
	print(G,V);
	dfs(G,0);
	cout << "Bridges:";
	cout << bridges << "\n";
	return 0;
}
