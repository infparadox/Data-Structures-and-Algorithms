#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

#define INF INT_MAX
#define size 100000

ll dis[size],par[size];
bool fl=0;

void bellman(vector< list< pii > >&G,ll s,ll V)
{
	ll i,j,u,v,w;
	dis[s]=0;
	for(i=0;i<V-1;i++)
	{
		for(u=0;u<V;u++)
		{
			for(auto it=G[u].begin();it!=G[u].end();it++)
			{
				v=(*it).second;
				w=(*it).first;
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
					par[v]=u;
				}
			}

		}
	}
	for(u=0;u<V;u++)
	{
		for(auto it=G[u].begin();it!=G[u].end();it++)
		{
			v=(*it).second;
			w=(*it).first;
			if(dis[u]!=INF && dis[v]>dis[u]+w)
			{
				fl=1;
				break;
			}
		}

	}
}

void path(ll s,ll v)
{
	cout << v;
	ll cur=v;
	while(cur!=s)
	{
		cur=par[cur];
		cout << "--->" << cur ;
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	ll V,E,i;
	cin >> V >> E;
	vector< list< pii > >G(V);
	for(i=0;i<V;i++)
	{
		G[i].clear();
		dis[i]=INF;
	}
	for(i=0;i<E;i++)
	{
		ll m,n,w;
		cin >> m >> n >> w;
		G[m].push_back(make_pair(w,n));
	}
	ll s;
	cin >> s;
	bellman(G,s,V);
	if(fl)
		cout << "Negative Cycle\n";
	else
	{
		for(i=0;i<V;i++)
		{
			if(i==s)
				continue;
			else if(dis[i]>=INF)
				cout << "-1 ";
			else
				cout << dis[i] << " ";
		}
		cout << "\n";
	}
	ll v;
	cin >> v;
	path(s,v);
	return 0;
}
