class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

 int m = grid.size();
 int n = grid[0].size();

    
    for( int i = 0 ; i < m ; i++){
        for( int j = 0 ; j < n ; j++){

            if(grid[i][j] == 0){

                startWave( grid , i , j , m , n   , 1 );

            }

        }
    }

    return ;
        

    }

    void startWave( vector<vector<int>> & grid , int i , int j  , int m , int n  , int currentDistance){


        queue< pair< int , int >> que;

        if( i-1 >= 0 && grid[i-1][j] > currentDistance){
            grid[i-1][j] = currentDistance;
            que.push({i-1 , j });
        }
        if( j -1 >= 0 && grid[i][j-1] > currentDistance){
            grid[i][j-1] = currentDistance;
            que.push({i , j-1});
        }
        if( i + 1 < m  && grid[i+1][j] > currentDistance){
            grid[i+1][j] = currentDistance;
            que.push({i+1 , j});
        }
        if( j + 1 < n && grid[i][j+1] > currentDistance){
            grid[i][j+1] = currentDistance;
            que.push({i , j+1});
        }

        while(!que.empty()){

            startWave(grid , que.front().first , que.front().second , m , n , currentDistance + 1);
            que.pop();

        }




    }
};
