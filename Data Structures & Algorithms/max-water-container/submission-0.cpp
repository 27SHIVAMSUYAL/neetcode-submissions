class Solution {
public:
    int maxArea(vector<int>& heights) {


        int left = 0 , right = heights.size() -1;

        int answer = INT_MIN;
    int water;
    int mini;

        while( left < right){

            if( heights[left] < heights[right]){
                water = heights[left] * ( right - left);
                left++;
            }else{
                  water = heights[right] * ( right - left);
                  right--;
            }


            answer = max(water , answer);
            

        }


        return answer;
        
    }
};
