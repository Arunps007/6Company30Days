class Solution {
public:
    
    void initializeQueue(queue<pair<int, int>> &q, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)   
                    q.push({i, j});
            }
        }
    }
    
    void expand(queue<pair<int, int>> &q, vector<vector<int>> &grid,
               int i, int j) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n &&
              grid[x][y] == 1) {
                grid[x][y] = 2;
                q.push({x, y});
            }
        }
    }
    
    bool leftNotRotten(vector<vector<int>> grid, int m, int n) {
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                if(grid[i][j] == 1)
                    return true;
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        initializeQueue(q, grid);
        
        int d = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int k = 0; k < sz; k++) {
                auto [i, j] = q.front(); q.pop();
                expand(q, grid, i, j);
            }
            d++;
        }
        if(leftNotRotten(grid, m, n))
            return -1;
        return max(0, d-1);
    }
};