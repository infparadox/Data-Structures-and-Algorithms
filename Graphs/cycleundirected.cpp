#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define size 100000

bool vis[size];

void print(vector< list<ll > >&G,ll v)
{
	for(ll i=0;i<v;i++)
	{
		cout << i ;
		for(auto it=G[i].begin();it!=G[i].end();it++)
			cout << "-->" << *it ;
		cout << "\n";
	}
}

bool cycle(vector< list<ll > >&G,ll s, ll p)
{
	vis[s]=1;
	bool fl=0;
	for(auto it=G[s].begin();it!=G[s].end();it++)
	{
		if(!vis[*it])
			cycle(G,*it,s);
		else if((*it)!=p)
		{
			fl=1;
			break;
		}
	}
	if(fl)
		return true;
	else
		return false;
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
		G[n].push_back(m);
	}
	print(G,V);
	bool fl=0;
	for(i=0;i<V;i++)
	{
		if(!vis[i])
		{
			if(cycle(G,i,-1))
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
