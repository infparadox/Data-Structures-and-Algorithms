#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define size 100000

ll color[size];

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

bool bfs(const vector< list<ll> >&G,ll s)
{
	bool fl=1; // bipartite
	deque<ll>q;
	q.push_back(s);
	color[s]=1;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop_front();
		for(auto it=G[u].begin();it!=G[u].end();it++)
		{
			if((*it)==u)  // SELF LOOP
			{
				fl=0;
				break;
			}
			if(color[*it]==-1)
			{
				q.push_back(*it);
				color[*it]=1-color[u];
			}
			else if(color[*it]==color[u]) // IF SAME COLOR
			{
				fl=0;
				break;
			}
		}
		if(!fl)
			break;
	}
	q.clear();
	return fl;
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
		color[i]=-1;
	}
	for(i=0;i<E;i++)
	{
		ll u,v;
		cin >> u >> v;
		G[u].push_back(v); //directed
	}
	print(G,V);
	bool fl=1;
	for(i=0;i<V;i++)
	{
		if(color[i]==-1)
		{
			if(!bfs(G,i))
			{
				fl=0;
				break;
			}
		}
	}
	if(fl)
		cout << "Bipartite Graph\n";
	else
		cout << "Not Bipartite Graph\n";
	return 0;
}
