#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define size 100000

bool vis[size];
ll indegree[size];

void print(const vector< list<ll> >&G,ll v)
{
	ll i;
	for(i=1;i<=v;i++)
	{
		cout << i  ;
		for(auto it=G[i].begin();it!=G[i].end();it++)
			cout << " --->" << *it ;
		cout << "\n";
	}
}
void bfs(const vector< list<ll> >&G,ll s)
{
	deque<ll>q;
	q.push_back(s);
	vis[s]=1;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop_front();
		//	cout << u << " ";
		for(auto it=G[u].begin();it!=G[u].end();it++)
		{
			indegree[*it]++; 
			if(!vis[*it])
			{
				q.push_back(*it);
				vis[*it]=1;
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
	vector< list<ll> >G(V+1);
	for(i=0;i<=V;i++)
	{
		G[i].clear();
		vis[i]=0;
		indegree[i]=0;
	}
	for(i=0;i<E;i++)
	{
		ll u,v;
		cin >> u >> v;
		G[u].push_back(v); //directed
	}
	print(G,V);
	for(i=0;i<=V;i++)
		vis[i]=0;
	for(i=1;i<=V;i++)
	{
		if(!vis[i])
			bfs(G,i);
	}
	ll count=0;
	priority_queue< ll,vector<ll> ,greater<ll>  > q; // MIN HEAP
	for(i=1;i<=V;i++)
	{
		if(indegree[i]==0)
			q.push(i);
	}
	while(!q.empty())
	{
		i=q.top();
		q.pop();
		cout << i << " ";
		for(auto it=G[i].begin();it!=G[i].end();it++)
		{
			indegree[*it]-=1;
			if(indegree[*it]==0)
				q.push(*it);
		}
	}
	cout << "\n";
	return 0;
}
