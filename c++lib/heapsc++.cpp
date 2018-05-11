//Default is max heap

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	ll n,i,x;
	cin >> n;
	vector<ll>a;
	vector<ll>::iterator it;
	for(i=0;i<n;i++)
	{
		cin >> x;
		a.push_back(x);
	}
	make_heap(a.begin(),a.end());
	cout << "The maximum element :" << a.front() << "\n";
	for(it=a.begin();it!=a.end();it++)
		cout << *it << " ";
	cout << "\n";
	a.push_back(8);
	push_heap(a.begin(),a.end());
	cout << "The maximum element :" << a.front() << "\n";
	for(it=a.begin();it!=a.end();it++)
		cout << *it << " ";
	cout << "\n";
	pop_heap(a.begin(),a.end());
	cout << "The maximum element :" << a.front() << "\n";
	for(it=a.begin();it!=a.end();it++)
		cout << *it << " ";
	cout << "\n";
	return 0;
}
