#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define size 1000000
bool vis[size];

void print(vector< list<ll> >&G,ll v)
{
	for(ll i=0;i<v;i++)
	{
		cout << i ;
		for(auto it=G[i].begin();it!=G[i].end();it++)
			cout << "-->" << *it ;
		cout << "\n";
	}
}

stack<ll>S;

void toposort(vector< list<ll> >&G,ll s)
{
	vis[s]=1;
	for(auto it=G[s].begin();it!=G[s].end();it++)
	{
		if(!vis[*it])
			toposort(G,*it);
	}
	S.push(s);
}

void dfs(vector< list<ll> >&G,ll s)
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
	ll V,E,i;
	cin >> V >> E;
	vector< list<ll> >G(V);
	vector< list<ll> >rev(V);
	for(i=0;i<V;i++)
	{
		G[i].clear();
		rev[i].clear();
		vis[i]=0;
	}
	for(i=0;i<E;i++)
	{
		ll m,n;
		cin >> m >> n;
		G[m].push_back(n);
		rev[n].push_back(m);
	}
	print(G,V);
	for(i=0;i<V;i++)
	{
		if(!vis[i])
			toposort(G,i);
	}
	for(i=0;i<V;i++)
		vis[i]=0;
	while(!S.empty())
	{
		i=S.top();
		S.pop();
		if(!vis[i])
		{
			dfs(rev,i);
			cout << "\n";
		}
	}
	return 0;
}
