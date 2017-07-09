#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

#define size 100000
#define INF INT_MAX

ll dis[size];
bool vis[size];

void prims(vector< list< pii > >&G,ll s)
{
	priority_queue< pii, vector<pii> , greater<pii> > Q; //Min Heap
	Q.push(make_pair(0,s));
	dis[s]=0;
	while(!Q.empty())
	{
		ll u,v,w;
		u=Q.top().second;
		Q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(auto it=G[u].begin();it!=G[u].end();it++)
		{
			v=(*it).second;
			w=(*it).first;
			if(!vis[v] && dis[v]>w)
			{
				dis[v]=w;
				Q.push(make_pair(dis[v],v));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	ll i,V,E;
	cin >> V >> E;
	vector< list< pii > >G(V);
	for(i=0;i<V;i++)
	{
		G[i].clear();
		vis[i]=0;
		dis[i]=INF;
	}
	for(i=0;i<E;i++)
	{
		ll m,n,w;
		cin >> m >> n >> w;
		G[m].push_back(make_pair(w,n));
		G[n].push_back(make_pair(w,m));
	}
	ll s;
	cin >> s;
	prims(G,s);
	for(i=0;i<V;i++)
	{
		if(dis[i]>=INF)
			cout << "-1 ";
		else if(i==s)
			continue;
		else
			printf("dis[%lld]:%lld " ,i,dis[i]);
	}
	return 0;
}
