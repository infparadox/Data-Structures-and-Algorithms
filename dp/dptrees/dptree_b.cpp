#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define si 100001
ll val[si],in[si],out[si];
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

void dfs1(vector< list<ll> >&G,ll s)
{
	vis[s]=1;
	in[s]=0;
	for(auto it=G[s].begin();it!=G[s].end();it++)
	{
		if(!vis[*it])
		{
			dfs1(G,*it);
			in[s]=max(in[*it]+1,in[s]);
		}
	}
}

void dfs2(vector< list<ll> >&G,ll s)
{
	vis[s]=1;
	ll mx1=-1,mx2=-1;
	for(auto it=G[s].begin();it!=G[s].end();it++)
	{
		if(!vis[*it])
		{
			if(in[*it]>=mx1)
		s	{
				mx2=mx1;
				mx1=in[*it];
			}
			else
				mx2=max(mx2,in[*it]);
		}
	}
	for(auto it=G[s].begin();it!=G[s].end();it++)
	{
		if(!vis[*it])
		{
			ll use=mx1;
			if(in[*it]==mx1)
				use=mx2;
			out[*it]=max(use+2,out[s]+1);
			dfs2(G,*it);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	ll V,E;
	cin >> V ;
	vector< list<ll> >G(V+1);
	ll i,j;
	for(i=1;i<=V;i++)
	{
		G[i].clear();
		vis[i]=0;
		val[i]=0;
	}
	E=V-1;
	for(i=1;i<=E;i++)
	{
		ll u,v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(G,1);
	//print(G,V);
	for(i=1;i<=V;i++)
		vis[i]=0;
	dfs2(G,1);
	for(i=1;i<=V;i++)
		val[i]=max(in[i],out[i]);
	for(i=1;i<=V;i++)
		cout << val[i] << " ";
	cout << "\n";
	return 0;
}