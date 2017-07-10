#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios::sync_with_stdio(false);
	priority_queue<ll, vector<ll> >pq;  // Max heap
	//priority_queue<ll, vector<ll>,greater<ll> >pq; // Min Heap
	ll n,i,x;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> x;
		pq.push(x);
	}
	ll q;
	cin >> q;
	while(q--)
	{
		ll op;
		cin >> op;
		if(op==1)
		{
			ll x;
			cin >> x;
			pq.push(x);
		}
		else if(op==2)
		{
			if(!pq.empty())
				pq.pop();
			else
				cout << "Empty\n";
		}
		else if(op==3)
			cout << "Max:" << pq.top() << "\n";
		else if(op==4)
			cout << "Size:" << pq.size() << "\n";
	}
	return 0;
}
