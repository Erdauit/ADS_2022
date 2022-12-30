#include <bits/stdc++.h>
using namespace std;

int n,m;

int mushroom(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        
        int mar = 0, t = -1;
        
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) mar++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                pair<int,int> cur = q.front();
                q.pop();
                for(auto dir: dirs) {
                    int x = cur.first + dir.first;
                    int y = cur.second + dir.second;
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                        mar--;
                    }
                }
            }
            t++;
        }
        if(mar>0) return -1; 
        if(t==-1) return 0; 
        return t;
}

int main(){
    cin >> n >> m;
    vector<vector< int > > v(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    cout << mushroom(v);
}