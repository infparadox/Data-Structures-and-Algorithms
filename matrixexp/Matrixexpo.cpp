#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mo=1e9+7;
const ll dim=2; // dimension of matrix to be multiplied
	
void multiply(ll a[dim][dim], ll b[dim][dim])
{
	ll mul[2][2];
	for (ll i = 0; i < dim; i++)
	{
		for (ll j = 0; j < dim; j++)
		{
			mul[i][j] = 0;
			for (ll k = 0; k < dim; k++)
				mul[i][j] =(mul[i][j]%mo+ (a[i][k]%mo*b[k][j]%mo)%mo)%mo;
		}
	}
	// storing the muliplication resul in a[][]
	for (ll i=0; i<dim; i++)
		for (ll j=0; j<dim; j++)
			a[i][j] = mul[i][j]; // Updating our matrix
}

ll power(ll F[dim][dim], ll n)
{
	ll M[dim][dim] = {{2,1}, {3,0}};
	if (n==1) //base case
		return 0;
	power(F, n/2);
	multiply(F, F);
	if (n%2 != 0)
		multiply(F, M);
	return F[1][1]%mo ;
}
	
ll findNthTerm(ll n)
{
	ll F[dim][dim] = {{2,1}, {3,0}};
	return power(F, n);
}

int main()
{
	ios::sync_with_stdio(0);
	ll n;
	cin >> n;
	ll ans=findNthTerm(n)%mo ;
	cout << ans << "\n";
	return 0;
}