class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

 int m = grid.size();
 int n = grid[0].size();

 queue<pair<int , int > > treasures ; 

    
    for( int i = 0 ; i < m ; i++){
        for( int j = 0 ; j < n ; j++){

            if(grid[i][j] == 0){

                    treasures.push({i , j});

            }

        }
    }

    while( !treasures.empty()){

        startWave( grid , treasures.front().first , treasures.front().second , m , n   , 1 );
        treasures.pop();

    }



    return ;
        

    }

    void startWave( vector<vector<int>> & grid , int i , int j  , int m , int n  , int currentDistance){


        queue< pair< int , int >> que;

                    // up down right left 
        int dr[4] = {-1  , 1  , 0 , 0 }; 
        int dc[4] = { 0  , 0 , 1 , -1};
        int row , col;

   
            for( int t = 0 ; t < 4; t++){

                row = i + dr[t];
                col = j + dc[t];

                if( row >= 0 && row < m && col >= 0 && col < n  && grid[row][col] > currentDistance){

                    grid[row][col] = currentDistance;
                    que.push( { row , col });
                }
            }

        while(!que.empty()){

            startWave(grid , que.front().first , que.front().second , m , n , currentDistance + 1);
            que.pop();

        }




    }
};
