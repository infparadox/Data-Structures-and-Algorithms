#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define size 100000

bool vis[size];
ll level[size];

void print(const vector< list<ll> >&g,ll v)
{
	ll i;
	for(i=0;i<v;i++)
	{
		cout << i  ;
		for(auto it=g[i].begin();it!=g[i].end();it++)
			cout << " --->" << *it ;
		cout << "\n";
	}
}
void dfs(const vector< list<ll> >&g,ll s)
{
	vis[s]=1;
	cout << s << " ";
	for(auto it=g[s].begin();it!=g[s].end();it++)
	{
		if(!vis[*it])
		{
			level[*it]=level[s]+1;
			dfs(g,*it);
		}
	}
}

void bfs(const vector< list<ll> >&g,ll s)
{
	deque<ll>q;
	q.push_back(s);
	vis[s]=1;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop_front();
		cout << u << " ";
		for(auto it=g[u].begin();it!=g[u].end();it++)
		{
			if(!vis[*it])
			{
				q.push_back(*it);
				vis[u]=1;
			}
		}
	}
	q.clear();
}

int main()
{
	ios::sync_with_stdio(false);
	ll i,V,E;
	cin >> V >> E;
	vector< list<ll> >g(V);
	for(i=0;i<V;i++)
	{
		g[i].clear();
		vis[i]=0;
		level[i]=0;
	}
	for(i=0;i<E;i++)
	{
		ll u,v;
		cin >> u >> v;
		g[u].push_back(v); //directed
	}
	print(g,V);
	cout << "DFS:" ;
	dfs(g,0);
	cout << "\n";
	for(i=0;i<V;i++)
		vis[i]=0;
	cout << "BFS:" ;
	bfs(g,0);
	cout << "\n";
	for(i=0;i<V;i++)
		printf("level[%lld]:%lld ",i,level[i]);
	return 0;
}
