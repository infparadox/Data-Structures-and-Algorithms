#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define size 100000
#define INF INT_MAX

bool vis[size],AP[size];
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
ll tim=0;
stack< pair<ll,ll> >S;
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
			S.push(make_pair(s,*it));
			par[*it]=s;
			dfs(G,*it);
			low[s]=min(low[s],low[*it]);
			if((par[s]==(-1)) && chd[s]>1)  // IF ROOT
			{
				while(!S.empty())
				{
					ll u=S.top().first;
					ll v=S.top().second;
					if(u==s && v==(*it))
					{
						cout << u << " " << v << "\n";
						S.pop();
						cout << "\n";
						break;
					}
					cout << u << " " << v << "\n";
					S.pop();
				}

			}
			if(par[s]!=(-1) && low[*it]>=disc[s])
			{
				while(!S.empty())
				{
					ll u=S.top().first;
					ll v=S.top().second;
					if(u==s && v==(*it))
					{
						cout << u << " " << v << "\n";
						S.pop();
						cout << "\n";
						break;
					}
					cout << u << " " << v << "\n";
					S.pop();
				}

			}
		}
		else if(par[s]!=*it && disc[*it]<low[s])   // Back Edge
		{
			low[s]=disc[*it];
			S.push(make_pair(s,*it));
		}
	}
}

void biconnected(const vector< list<ll> >&G, ll V)
{
	for(ll i=0;i<V;i++)
	{
		if(!vis[i])
		{
			dfs(G,i);
			while(!S.empty())
			{
				ll u=S.top().first;
				ll v=S.top().second;
				cout << u << " " << v << "\n";
				S.pop();
			}
			cout << "\n";
		}
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
		AP[i]=0;    // Articulation Point
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
	biconnected(G,V);
	return 0;
}
