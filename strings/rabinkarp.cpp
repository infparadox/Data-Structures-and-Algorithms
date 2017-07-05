#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	ll t;
	string text;
	cin >> text ;
	cin >> t;
	while(t--)
	{
		string pat;
		pat.clear();
		cin >> pat;
		ll p=101,h1=0,h2=0,m,n,i,j,k,mo=1000000007;
		bool fl=false;
		m=pat.size();
		n=text.size();
		for(i=0;i<m;i++)
			h1+=(pat[i]*pow(p,i));
		j=0;
		k=0;
		i=0;
		while(i<=n)
		{
			if(i<m)
				h2+=(text[i]*pow(p,i));
			else if(i>=m)
			{
				if(h1==h2)
				{
					j=i-m;
					k=0;
					while(k<m)
					{
						if(pat[k]==text[j])
						{
							j++;
							k++;
						}
						else
							break;
					}
				}
				if(k==m)
				{
					fl=true;
					break;
				}
				else
				{
					h2-=(text[i-m]);
					h2=h2/p;
					h2+=(text[i]*pow(p,m-1));
				}
			}
			i++;
		}
		if(fl)
			cout << "Y\n";
		else
			cout << "N\n";
	}
	return 0;
}
