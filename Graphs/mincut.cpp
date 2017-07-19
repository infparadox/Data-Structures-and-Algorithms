// Complexity - O(VE^2)
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define si 100000
bool vis[si];
void print(vector< map<ll,ll> >&G,ll V)
{
	ll i;
	for(i=0;i<V;i++)
	{
		cout << "i:" << i << "\n";
		for(auto it=G[i].begin();it!=G[i].end();it++)
			cout << (*it).first << " " << (*it).second << "\n";
	}
}

ll bfs(vector< map<ll,ll> >&G,ll s,ll t,ll par[],ll V)
{
	ll i;
	for(i=0;i<V;i++)
		vis[i]=0;
	deque<ll>q;
	q.push_back(s);
	vis[s]=1;
	par[s]=-1;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop_front();
		for(auto it=G[u].begin();it!=G[u].end();it++)
		{
			ll v=(*it).first;
			if(!vis[v] && G[u][v]>0)  // EDGE WEIGHT>0 (FOR AUGMENTED PATH)
			{
				q.push_back(v);
				par[v]=u;
				vis[v]=1;
			}
		}
	}
	if(vis[t])
		return 1;
	else
		return 0;
}

void dfs(vector< map<ll,ll> >&G,ll s)
{
	vis[s]=1;
	for(auto it=G[s].begin();it!=G[s].end();it++)
	{
		ll v=(*it).first;
		ll w=(*it).second;
		if(!vis[v] && w>0)
			dfs(G,v);
	}
}

ll maxflow(vector< map<ll,ll> >&G, ll s, ll t, ll V)
{
	ll par[V],max_flow=0,u,v;
	vector< map<ll,ll> >rG=G; // RESIDUAL GRAPH
	while(bfs(rG,s,t,par,V))  // IF THERE IS AN AUGMENTED PATH B/W S AND T
	{
		ll path_flow=INT_MAX;
		for(v=t;v!=s;v=par[v])
		{
			u=par[v];
			path_flow=min(path_flow,rG[u][v]);
		}
		for(v=t;v!=s;v=par[v])
		{
			u=par[v];
			rG[u][v]-=path_flow;  // UPDATE RESIDUAL GRAPH
			rG[v][u]+=path_flow;  
		}
		max_flow+=path_flow;
	}
	for(ll i=0;i<V;i++)
		vis[i]=0;
	dfs(rG,s);
	cout << "Min cut Edges:\n";
	for(ll i=0;i<V;i++)
	{
		if(vis[i])
		{
			for(auto it=G[i].begin();it!=G[i].end();it++)
			{
				v=(*it).first;
				if(!vis[v])
				{
					cout << i << "-->" << v << "\n";
				}
			}
		}
	}
	return max_flow;
}

int main()
{
	ios::sync_with_stdio(false);
	ll V,E;
	cin >> V >> E;
	vector< map<ll,ll> >G(V);
	ll i,j;
	for(i=0;i<E;i++)
	{
		ll u,v,w;
		cin >> u >> v >> w;
		G[u][v]=w;
	}
//	print(G,V);
	ll s,t;
	cin >> s >> t;
	ll ans=maxflow(G,s,t,V);
	cout << "MAX FLOW:";
	cout << ans << "\n";
	return 0;
}
