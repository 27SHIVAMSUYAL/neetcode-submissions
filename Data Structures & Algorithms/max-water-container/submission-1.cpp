class Solution {
public:
    int maxArea(vector<int>& heights) {


        int left = 0 , right = heights.size() -1;

        int answer = INT_MIN;
   
        while( left < right){

            if( heights[left] < heights[right]){
                answer = max( heights[left] * ( right - left)    , answer ) ;
                left++;
            }else{
                  answer =  max(heights[right] * ( right - left)  , answer);
                  right--;
            }

            

        }


        return answer;
        
    }
};
