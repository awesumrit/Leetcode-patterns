class Solution {
public:
    
    int dir[4][4] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& vis, int &m, int &n){
        
        vis[r][c] = true;
        for(int i = 0; i<4; i++){
            int x = r + dir[i][0], y = c + dir[i][1];
            if(x>=0 && y>=0 && x<m && y<n && !vis[x][y] && grid[x][y]=='1'){
                dfs(grid, x, y, vis, m, n);
            }
        }
         
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(grid, i, j, vis, m, n);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};
