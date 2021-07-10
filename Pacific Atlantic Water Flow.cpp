class Solution {
public:
    int d[4][4] = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(vector<vector<int>>& matrix , vector<vector<bool>>&ocean , int r,int c,int &m ,int &n){
        ocean[r][c] = true;        
        for(int i=0;i<4;i++){
            int x = d[i][0]+r , y = d[i][1]+c;
            if(x>=0 && y>=0 && x<m && y<n && matrix[x][y]>=matrix[r][c] && !ocean[x][y]) 
                dfs(matrix,ocean,x,y,m,n);
        }
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size();
        
        vector<vector<bool>> pacific(m,vector<bool>(n,false)), atlantic(m,vector<bool>(n,false));    
        vector<vector<int>> result;
                  
        if(m==0 || n==0)
            return result;                   
        for(int i=0;i<m;i++) //left and right sides
        {
            dfs(matrix,pacific,i,0,m,n);
            dfs(matrix,atlantic,i,n-1,m,n);
        }
        
        for(int i=0;i<n;i++) //top and bottom 
        {
            dfs(matrix,pacific,0,i,m,n);
            dfs(matrix,atlantic,m-1,i,m,n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(pacific[i][j]==1 && atlantic[i][j]==1){
                    result.push_back({i,j});
                }
            }
        }
        
        return result;
    }
};
