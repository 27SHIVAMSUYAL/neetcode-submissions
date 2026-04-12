class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int rows = board.size();
        int cols = board[1].size();

        for(int i = 0 ; i < rows ; i++){
            if(checkRow(board , i , rows , cols ) == false){
                return false;
            }
        }

        for(int i = 0 ; i < cols ; i++){
            if(checkCol(board , i , rows , cols ) == false){
                return false;
            }
        }

        for(int i = 0 ; i < rows ; i=i+3){
            for(int j = 0 ; j < cols ; j=j+3){
            if(checkBox(board , i , j , rows , cols) == false){
                return false;
            }
        }
        }
        return true;
    }

    bool checkRow(vector<vector<char>>& board , int row , int rows , int cols ){

        vector<int>count(10,0);

        for(int i = 0 ; i < cols ; i++){
             if(board[row][i] == '.'){continue;}
             
            if(count[ board[row][i] - '0'] == 0){
                count[ board[row][i] - '0']++;
            }else{
                return false;
            }
        }
        return true;

    }

        bool checkCol(vector<vector<char>>& board , int col , int rows , int cols ){

        vector<int>count(10,0);

        for(int i = 0 ; i < rows ; i++){
            if(board[i][col] == '.'){continue;}
            if(count[ board[i][col] - '0'] == 0){
                count[ board[i][col] - '0']++;
            }else{
                return false;
            }
        }
        return true;

    }

    bool checkBox(vector<vector<char>>& board ,int row ,  int col , int rows , int cols){

        vector<int>count(10,0);

            for( int i = row ; i < row +3 ; i++){
                for(int j = col ; j < col + 3 ; j++){
                if(board[i][j] == '.'){continue;}
            if(count[ board[i][j] - '0'] == 0){
                count[ board[i][j] - '0']++;
            }else{
                return false;
            }


                }
            }




        return true;
    }
};
