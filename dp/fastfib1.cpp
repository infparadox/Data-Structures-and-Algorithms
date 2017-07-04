#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void multiply(ll F[2][2],ll M[2][2])
{
	ll w,x,y,z;
	w=F[0][0]*M[0][0]+F[0][1]*M[1][0];
	x=F[0][0]*M[0][1]+F[0][1]*M[1][1];
	y=F[1][0]*M[0][0]+F[1][1]*M[1][0];
	z=F[1][0]*M[0][1]+F[1][1]*M[1][1];
	F[0][0]=w;
	F[0][1]=x;
	F[1][0]=y;
	F[1][1]=z;
}

void power(ll F[2][2],ll n)
{
	if(n==0 || n==1)
		return ;
	ll M[2][2]={{1,1},{1,0}};
	power(F,n/2);
	multiply(F,F);
	if((n%2)==1)
		multiply(F,M);
}

ll fib(ll n)
{
	if(n<=1)
		return n;
	ll F[2][2]={{1,1},{1,0}};
	power(F,n-1);
	return F[0][0];
}

int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll ans=fib(n);
	cout << ans << "\n";
	return 0;
}

