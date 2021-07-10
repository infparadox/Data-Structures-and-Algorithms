#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define INF INT_MAX

class Solution {
    public:
    void djikstra(const vector< list<pii> >&G, const int src, vector<int>&dis, vector<bool>&vis) {
        priority_queue< pii, vector<pii>, greater<pii> >Q;
        Q.push(make_pair(0,src));
        dis[src] = 0;
        while(!Q.empty()) {
            int u;
            u = Q.top().second;
            Q.pop();
            if(vis[u])
                continue;
            vis[u] = true;
            for(auto it : G[u]) {
                int v = it.second;
                int w = it.first;
                if(!vis[v] && dis[v] > dis[u]+w) {
                    dis[v] = dis[u] + w;
                    Q.push(make_pair(dis[v],v));
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    int V, E;
    cin >> V >> E;
    vector< list<pii> >G(V);
    vector<bool> vis(V);
    vector<int> dis(V);
    for(int i=0; i<V; i++) {
        G[i].clear();
        vis[i] = false;
        dis[i] = INF;
    }
    
    for(int i=0; i<E; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back(make_pair(w,v));
        G[v].push_back(make_pair(w,u));
    }
    
    Solution solve;
    solve.djikstra(G, 0, dis, vis);
    for(int i=0; i<V; i++) {
        cout << i << " " << dis[i] << "\n";
    }
    cout << "\n";
    return 0;
}
