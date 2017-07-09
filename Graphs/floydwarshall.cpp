#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define INF INT_MAX
#define size 1000
ll dis[size][size],path[size][size],graph[size][size];
stack<ll>S;

void init(ll V)        //initialize dis matrix and path matrix according to graph
{
	ll i,j;
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			dis[i][j]=graph[i][j];
			if(graph[i][j]!=INF && i!=j)
				path[i][j]=i;
			else
				path[i][j]=-1;
		}
	}
}
void warshall(ll V)
{
	ll i,j,k;
	for(k=0;k<V;k++)
	{
		for(i=0;i<V;i++)
		{
			for(j=0;j<V;j++)
			{
				if(dis[i][k]== INF || dis[k][j]==INF)
					continue;
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					path[i][j]=path[k][j];
				}
			}
		}
	}
}
bool checknegativecycle(ll V)   //returns 1 if exists
{
	ll i;
	for(i=0;i<V;i++)
	{
		if(dis[i][i]<0)
			return 1;
	}
	return 0;
}
ll printpath(ll i,ll j,ll V)
{
	if(i<0 || j<0 || i>=V || j>=V)
		return -1;
	S.push(j);
	while(1)
	{
		j=path[i][j];
	//	if(j==-1)
	//		return;
		S.push(j);
		if(j==i)
			break;
	}
	while(!S.empty())
	{
		printf("%lld ",S.top());
		S.pop();
	}
}
int main()
{
	ll V,m,n,w,i,j;
	scanf("%lld",&V);
	ll E;
	scanf("%lld",&E);
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
			graph[i][j]=INF;
	}
	for(i=0;i<E;i++)
	{
		scanf("%lld %lld %lld",&m,&n,&w);
		graph[m][n]=w;
	}
	for(i=0;i<V;i++)
		graph[i][i]=0;
	init(V);
/*	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			printf("%lld ",graph[i][j]);
		}
		printf("\n");
	}
	*/
	warshall(V);
	printf("final dis matrix:\n");
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			printf("%lld ",dis[i][j]);
		}
		printf("\n");
	}
	if((checknegativecycle(V)))
		printf("negative cycle exists\n");
	else
		printf("no negative cycle\n");
	if((checknegativecycle(V))!=1)
	{
		printf("Enter vertices to get shortest path\n");
		ll s,d;
		scanf("%lld %lld",&s,&d);
		printpath(s,d,V);
	}
	return 0;
}
