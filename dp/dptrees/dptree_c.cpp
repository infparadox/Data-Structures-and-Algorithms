#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define si 100001
const int LG= 20;  //log(n)
ll lev[si],P[si][LG];
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
	for(auto it=G[s].begin();it!=G[s].end();it++)
	{
		if(!vis[*it])
		{
			lev[*it]=lev[s]+1;
			P[*it][0]=s;
			dfs(G,*it);
		}
	}
}

ll lca(ll u,ll v)
{
	ll i,lg;
	if(lev[u]<lev[v])
		swap(u,v);
	for(lg=0;(1<<lg)<=lev[u];lg++);
	lg--;
	for(i=lg;i>=0;i--)
	{
		if(lev[u]-(1<<i) >=lev[v])
			u=P[u][i];
	}
	if(u==v)
		return u;
	for(i=lg;i>=0;i--)
	{
		if(P[u][i]!=-1 && P[u][i]!=P[v][i])
		{
			u=P[u][i];
			v=P[v][i];
		}
	}
	return P[u][0];
}

ll getancestor(ll u,ll dis)  // at distance dis from u
{
	dis=lev[u]-dis;
	ll i,lg=0;
	for(;(1<<lg)<=lev[u];lg++);
	lg--;
	for(i=lg;i>=0;i--)
	{
		if(lev[u]-(1<<i)>=dis)
			u=P[u][i];
	}
	return u;
}

ll dis(ll u,ll v)
{
	if(lev[u]<lev[v])
		swap(u,v);
	ll w=lca(u,v);
	ll ans=lev[u]+lev[v]-2*lev[w];
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	ll V,E;
	cin >> V ;
	vector< list<ll> >G(V+1);
	ll i,j;
	E=V-1;
	for(i=1;i<=V;i++)
	{
		G[i].clear();
		vis[i]=0;
	}
	for(i=0;i<LG;i++)
	{
		for(j=1;j<=V;j++)
			P[j][i]=-1;
	}
	for(i=1;i<=E;i++)
	{
		ll u,v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(G,1);
	for(i=1;i<LG;i++)
	{
		for(j=1;j<=V;j++)
		{
			if(P[j][i-1]!=-1)
				P[j][i]=P[P[j][i-1]][i-1];
		}
	}
	//print(G,V);
	ll q;
	cin >> q;
	while(q--)
	{
		ll x;
		cin >> x;
		if(x==1) // lca
		{
			ll u,v;
			cin >> u >> v;
			ll ans=lca(u,v);
			cout << ans << "\n";
		}
		else if(x==2) // ancestor at dis=x
		{
			ll u,dis;
			cin >> u >> dis;
			cout << getancestor(u,dis) << "\n";
		}
		else if(x==3) //dis b/w u,v
		{
			ll u,v;
			cin >> u >> v;
			cout << dis(u,v) << "\n";
		}
	}
	return 0;
}