#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;

ll exp(ll x,ll y,ll p) 
{ 
    ll res = 1;
    x = x % p; 
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
} 

int main()
{
	ios::sync_with_stdio(false);
	ll x,n,m,ans;
	cin >> x >> n >> m;
	ans=exp(x,n,m);
	cout << ans << "\n";
	return 0;
}

