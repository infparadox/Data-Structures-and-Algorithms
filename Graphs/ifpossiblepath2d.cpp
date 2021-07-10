#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool dfs(const vector< vector<int> >matrix, const int x, const int y, int dx, int dy, vector< vector<int> >&vis) {
        if(!isValid(x, y, matrix.size(), matrix[0].size()) || vis[x][y] || matrix[x][y] == 0)
            return false;
        
        if(x == dx && y == dy) 
            return true;
        
        cout << x << " " << y << "\n";
        vis[x][y] = true;
        if( dfs(matrix, x+1, y, dx, dy, vis) ) 
            return true;
        if( dfs(matrix, x, y+1, dx, dy, vis) )
            return true;
        return false;
    }
    
    private:
    bool isValid(int x, int y, int m, int n) {
        if(x>=0 && x<m && y>=0 && y<n) {
            return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector< vector<int> >matrix(n, vector<int>(m));
    vector< vector<int> >vis(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m ;j++) {
            cin >> matrix[i][j];
            vis[i][j] = false;
        }
    }
    Solution solve;
    if(solve.dfs(matrix, 0, 0, n-1, m-1, vis)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    
    return 0;
}
