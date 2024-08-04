// Design Neighbor Sum Service
// contest

class neighborSum {
public:
     vector<vector<int>> grid;
    int n;
    
    neighborSum(vector<vector<int>>& grid) {
     this->grid = grid;
        n = grid.size();
    }
    
    int adjacentSum(int value) {
        int sum=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]== value){
                   if(j>0)
                    sum+=grid[i][j-1];
                   if(j<n-1)
                    sum+=grid[i][j+1];
                   if(i>0)
                    sum+=grid[i-1][j];
                   if(i<n-1)
                    sum+=grid[i+1][j];
               
                   return sum;
               }
           }
       }
        return -1;
        
    }
    int diagonalSum(int value) {
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==value){
                    if(i>0 && j>0) sum+=grid[i-1][j-1];
                    if(i>0 && j<n-1) sum+=grid[i-1][j+1];
                    if(i<n-1 && j>0) sum+=grid[i+1][j-1];
                    if(i<n-1 && j<n-1) sum+=grid[i+1][j+1];
                    return sum;
                }
            }
        }
        return -1;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */