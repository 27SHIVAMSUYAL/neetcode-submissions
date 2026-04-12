class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {


        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited( rows , vector<bool>(cols , false) );

        int count = 0 ; 
        int ans = INT_MIN;


        for( int i = 0 ; i < rows ; i++){
            for( int j = 0 ; j < cols ; j++){

                if( grid[i][j] == 1 && visited[i][j] == false ){

                    count = markLand( grid , visited , i , j , rows , cols);

                    ans = max(ans , count);

                }

            }
        }
        if( ans != INT_MIN){
                 return ans;
        }

        return 0;
       
        
    }

    int markLand( vector<vector<int>>& grid , vector<vector<bool>>& visited , int i , int j , int &rows , int & cols){


            if( visited[i][j] == true || grid[i][j] == 0){
                return 0 ;
            }

            visited[i][j] = true;




            int sum = 1 , up = 0  , down  = 0 , left = 0  , right  = 0 ;


            // up 

            if( i-1 >=0 && grid[i-1][j] ==1){
                up =  markLand( grid , visited , i-1 , j , rows , cols);
            }

            // down 

              if( i+1 < rows && grid[i+1][j] ==1){
                down =  markLand( grid , visited , i+1 , j , rows , cols);
            }


            // left 

              if( j-1 >=0 && grid[i][j-1] ==1){
                left =  markLand( grid , visited , i , j-1 , rows , cols);
            }


            // right 

                 if( j+1 < cols && grid[i][j+1] ==1){
                right =  markLand( grid , visited , i , j+1 , rows , cols);
            }

            sum = sum + left + right + down + up  ;

        return sum;

    }
};
