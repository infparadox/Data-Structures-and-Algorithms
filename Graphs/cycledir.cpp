#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define size 10000

bool w[size];
bool g[size];
bool b[size];

void print(vector< list<ll> >&G,ll V)
{
	for(ll i=0;i<V;i++)
	{
		cout << i ;
		for(auto it=G[i].begin();it!=G[i].end();it++)
			cout << "-->" << *it ;
		cout << "\n";
	}
}

bool dfs(vector< list<ll> >&G,ll s)
{
	w[s]=0;
	g[s]=1;
	for(auto it=G[s].begin();it!=G[s].end();it++)
	{
		if(g[*it])
			return 1;
		else if(w[*it])
		{
			if(dfs(G,*it))
				return 1;
		}
	}
	b[s]=1;
	g[s]=0;
	return 0;
}


int main()
{
	ios::sync_with_stdio(false);
	ll V,E,i;
	cin >> V >> E;
	vector< list<ll > >G(V);
	for(i=0;i<V;i++)
	{
		G[i].clear();
		w[i]=1;
		g[i]=0;
		b[i]=0;
	}
	for(i=0;i<E;i++)
	{
		ll m,n;
		cin >> m >> n;
		G[m].push_back(n);
	}
	bool fl=0;
	for(i=0;i<V;i++)
	{
		if(w[i])
		{
			if(dfs(G,i))
			{
				fl=1;
				break;
			}
		}
	}
	if(fl)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
