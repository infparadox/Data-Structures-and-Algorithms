#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	string pat,text;
	cin >> pat >> text;
	ll i,m,n,j;
	m=text.size();
	n=pat.size();
	j=0;
	i=1;
	ll temp[n];
	temp[0]=0;
	bool flag=false;
	while(i<n && n>1)
	{
		if(pat[i]==pat[j])
		{
			temp[i++]=j+1;
			j++;
		}
		else if(j!=0)
			j=temp[j-1];
		else
		{
			temp[i]=0;
			i++;
		}
	}
	i=0;
	j=0;
	ll count=0;
	while(i<m && j<n)
	{
		if(text[i]==pat[j])
		{
			i++;
			j++;
		}
		else if(j!=0)
			j=temp[j-1];
		else
			i++;
		if(j==n)
		{
			count++;
			j=temp[j-1];
		}
	}
	cout << count << "\n";
	return 0;
}

