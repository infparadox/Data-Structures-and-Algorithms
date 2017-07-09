#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define size 1000000
bool vis[size];

void print(vector< list<ll> >&G,ll V)
{
	ll i;
	for(i=0;i<V;i++)
	{
		cout << i ;
		for(auto it=G[i].begin();it!=G[i].end();it++)
			cout << "-->" << *it ;
		cout << "\n";
	}
}

stack<ll>S;

void dfs(vector< list<ll> >&G,ll s)
{
	vis[s]=1;
	for(auto it=G[s].begin();it!=G[s].end();it++)
	{
		if(!vis[*it])
			dfs(G,*it);
	}
	S.push(s);
}

int main()
{
	ios::sync_with_stdio(false);
	ll V,E,i;
	cin >> V >> E;
	vector< list<ll> >G(V);
	for(i=0;i<V;i++)
	{
		G[i].clear();
		vis[i]=0;
	}
	for(i=0;i<E;i++)
	{
		ll m,n;
		cin >> m >> n;
		G[m].push_back(n);
	}
	print(G,V);
	for(i=0;i<V;i++)
	{
		if(!vis[i])
			dfs(G,i);
	}
	cout << "TOPOSORT ORDER:" ;
	while(!S.empty())
	{
		cout << S.top() << " ";
		S.pop();
	}
	return 0;
}
