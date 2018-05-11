#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll suf[500002];
int main()
{
    ios::sync_with_stdio(false);
    ll n,i;
    cin >> n;
    vector<ll>a;
    a.push_back(0);
    for(i=1;i<=n;i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    suf[n]=a[n];
    unordered_map<ll,ll>cnt;
    cnt[0]=1;
    cnt[suf[n]]=1;
    for(i=n-1;i>0;i--)
    {
        suf[i]=a[i]^suf[i+1];
        if(cnt.find(suf[i])==cnt.end())
           cnt[suf[i]]=1;
        else
           cnt[suf[i]]++;
    }
    //for(auto itr=cnt.begin();itr!=cnt.end();itr++)
   // 	cout << (*itr).first << " " << (*itr).second << "\n";
    ll ans=0,cur=0;
    for(i=1;i<=n;i++)
    {
        cur=cur^a[i-1];
        auto it=cnt.find(suf[i]);            
        if(it!=cnt.end())
        {
            if((*it).second>1)
                cnt[suf[i]]--;
            else
                cnt.erase(it);
        }
        it=cnt.find(cur);
        if(it!=cnt.end())
            ans+=(*it).second;
    }
    cout << ans << "\n";
    return 0;         
}