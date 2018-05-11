#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define LL long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<int, LL>	pil;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 1e5+2, M = N;
//=======================
 
vi g[N];
int a[N];
//-----------STRUCT BEGINS
struct node{
	LL OFFSET, cmp;
	#define vl vector<LL>
	vl arr, dp;
	vi inc_len, next_greater, ult;
	node() {}
	node(vl &x){
		int n = x.size(), i;
		if(n == 0)
			return;
		OFFSET = 0;
		arr =  vl(n, 0);
		dp =  vl(n, 0);
		next_greater =  vi(n, 0);
		ult =  vi(n, 0);
		inc_len =  vi(n, 0);
		fo(i, n) arr[i] = x[i];
		compute_stuff();
	}
	void init(vl &x){
		int n = x.size(), i;
		if(n == 0)
			return;
		OFFSET = 0;
		arr =  vl(n, 0);
		dp =  vl(n, 0);
		next_greater =  vi(n, 0);
		ult =  vi(n, 0);
		inc_len =  vi(n, 0);
		fo(i, n) arr[i] = x[i];
		compute_stuff();
	}
	void compute_stuff(){
		int i, n = arr.size();
		if(arr.empty()) return;
		dp[0] = arr[0];
		Fo(i, 1, n) dp[i] = max(dp[i-1], arr[i]);
		stack<int> s;
		LL element, next;
		s.push(0);
		for (i=1; i<n; i++)
		{
		    next = i;
		    while(!s.empty()){
		    	int cur = s.top();
		    	if(arr[cur] < arr[i]){
		    		next_greater[cur] = i;
		    		s.pop();
		    	}
		    	else break;
		    }		// for(int kk = fo; kk <= en[j]; kk++){
				// 	if((RTN*(j-1)+kk+1-tans) > 100) {
				// 		break;
				// 	}
				// 	if(my[j].arr[kk] > tem) tem = my[j].arr[kk], tans = RTN*(j-1)+kk+1, ul = kk, tot++;
				// }
		    s.push(i);
		}
		while (s.empty() == false)
		{
		    element = s.top(); s.pop();
		    next_greater[element] = n;
		}
		Fo(i, n-1, -1){
			if(next_greater[i] == n or (next_greater[i]-i) > 100) 
				inc_len[i] = 1, ult[i] = i;
			else 
				inc_len[i] = 1+inc_len[next_greater[i]], ult[i] = ult[next_greater[i]];
		}
	}
	pil get_next(LL val){
		
		//first element >= val
		//pos of no, ultimatum number
		//length of chain, ultimatum chiye <CCHECK HERE!!>
		cmp = val-OFFSET;//hereee
		int at = bin(0, arr.size()-1);
		if(at == -1) return {-1, -1};
		return {at, ult[at]};
	}
	bool f(int pos){
		return dp[pos] >= cmp;
	}
	int bin(int lo, int hi){
		if(lo == hi){
			if(f(lo)) return lo;
			return -1;
		}
		if(lo+1 == hi){
			if(f(lo)) return lo;
			lo = hi;
			if(f(lo)) return lo;
			return -1;
		}
		int mid = (lo+hi)/2;
		if(f(mid)) return bin(lo, mid);
		return bin(mid+1, hi);
	}
	void clear_offset(){
		int i, n = arr.size();
		fo(i, n) arr[i] += OFFSET;
		OFFSET = 0;
		compute_stuff();
	}
	
};
//--------------ENDS
int RTN = 320;
node my[317+10];
int pos[N], rep[N], en[N];
void solve(){
	int i, n, q, l, j, r, x, type, k, ans;
	cin >> n >> q;
	// RTN = sqrt(n);
	int bkt = 1;
	vl win = {};
	fo(i, n) {
		cin >> a[i];
		win.pb(a[i]);
		pos[i] = i%RTN;
		rep[i] = bkt;
		if((i+1)%RTN == 0 or i==n-1) {
			my[bkt].init(win);
			win.clear();
			en[bkt] = pos[i];
			if(i != n-1)bkt++;
		}
	}
 
	while(q--){
		cin >> type;
		if(type == 1){
			cin >> i >> k; i--;
			int x = rep[i];
			my[x].clear_offset();
			LL val = my[x].arr[pos[i]];
			// deb2(pos[i],en[x]);
			// deb2(k,x);
			ans = i+1;
			for(j = pos[i]; j <= en[x]; j++){
				if(k == 0 or (RTN*(x-1)+j-ans+1) > 100){
					k=0;break;
				}
				if(my[x].arr[j] > val) k--, val = my[x].arr[j], ans = RTN*(x-1)+j+1;
			}
			if(k == 0){
				cout << ans << endl;
				continue;
			}
			//k jumps, > val
			int found = -1;
			x=rep[i];
			for(j = x+1; j <= bkt; j++){
				
				pil cur = my[j].get_next(val+1);
				
				//length and ultimatum
				int fo = cur.F, ul = cur.S;
				if(fo == -1) break;
				int latest = RTN*(j-1)+fo+1;
				if(latest-ans>100) break;
				if(my[j].inc_len[fo] >= k){
					found = j; 
					break;
				}
				else{
					val = my[j].arr[ul] + my[j].OFFSET;
					ans = RTN*(j-1)+ul+1;
					k -= my[j].inc_len[fo];
				}
			}
			if(found == -1){
				cout << ans << endl;
				continue;
			}
			//is bucket me bas age badho
			x = found;
			my[x].clear_offset();
			for(j = 0; j <= en[x]; j++){
				if(k == 0 or (RTN*(x-1)+j+1-ans>100)) break;
				if(my[x].arr[j] > val) k--, val = my[x].arr[j], ans = RTN*(x-1)+j+1;
			}
			cout << ans << endl;
		}
		else{
			LL X;
			cin >> l >> r >> X; l--, r--; 
			if(rep[l] == rep[r]){
				for(j=pos[l]; j<=pos[r]; j++) 
					my[rep[l]].arr[j] += X;
				my[rep[l]].clear_offset();
				continue;
			}
			x = rep[l];
			for(j = pos[l]; j <= en[x]; j++)
				my[x].arr[j] += X;
			my[x].clear_offset();
			
			for(j=x+1; j < rep[r]; j++)
				my[j].OFFSET += X;
				
			x = rep[r];
			for(j = 0; j <= pos[r]; j++)
				my[x].arr[j] += X;
			my[x].clear_offset();
		}
	}
	
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
		solve();
	return 0;
}  