class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        vector<vector<bool>> visited( grid.size() , vector<bool>(grid[0].size() , false) );

        int rows = grid.size();
        int cols = grid[0].size();
        int land = 0 ;

        for( int i = 0 ; i < rows ; i++){
            for( int j = 0  ; j < cols ; j++){

                if( grid[i][j] == '1' && visited[i][j] == false){
                        land++;
                        markLand( visited , grid , i , j , rows , cols);
                }

            }
        }


        return land;
        
    }

    void markLand(vector<vector<bool>> &visited , vector<vector<char>> &grid , int i , int j , int rows, int cols){

        if( visited[i][j] == true){
            return;
        }


        visited[i][j] = true;

        // up 

        if( i-1 >= 0 && grid[i-1][j] == '1' ){
            markLand( visited , grid , i-1 , j , rows , cols);
        }

        // down 
         if( i+1 < rows && grid[i+1][j] == '1' ){
            markLand( visited , grid , i+1 , j , rows , cols);
        }


        // left 

         if( j-1 >= 0  && grid[i][j-1] == '1'){
            markLand( visited , grid , i , j-1 , rows , cols);
        }


        // right 

            if( j+1 < cols && grid[i][j+1] == '1' ){
            markLand( visited , grid , i , j+1 , rows , cols);
        }

        return ;


    }
};
