#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    public:
    void dfs(const vector< list<int> >&G, const int src, vector<bool>&vis, vector<int>&level) {
        vis[src] = true;
        cout << src << " ";
        for(int v: G[src]) {
            if(!vis[v]) {
                level[v] = level[src] + 1;
                dfs(G, v, vis, level);
            }
        }
    }
    
    void bfs(const vector< list<int> >&G, const int src, vector<bool>&vis, vector<int>&level) {
        deque<int>Q;
        Q.push_back(src);
        vis[src] = true;
        while(!Q.empty()) {
            int u = Q.front();
            cout << u << " ";
            Q.pop_front();
            for(int v : G[u]) {
                if(!vis[v]) {
                    level[v] = level[u] + 1;
                    Q.push_back(v);
                    vis[v] = true;
                }
            }
            
        }
    }
};


int main() {
    ios::sync_with_stdio(0);
    int V, E;
    cin >> V >> E;
    vector< list<int> >G(V);
    vector<bool>vis(V);
    vector<int>level(V);
    for(int i=0; i<V; i++) {
        G[i].clear();
        vis[i] = false;
        level[i] = 0;
    }
    for(int i=0; i<E; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    Solution solve;
    solve.dfs(G, 0, vis, level);
    cout << "\n";
    for(int i=0; i<V; i++) {
        cout << i << " :" << level[i] << " ";
    }
    cout << "\n";
    return 0;
}
