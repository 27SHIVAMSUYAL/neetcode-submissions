class Solution {
public:
    int trap(vector<int>& height) {


      vector<int> leftToRight(height.size() , -1) ;
      vector<int>  rightToLeft(height.size() , -1);


        int maxi = INT_MIN;
      for( int i = 0 ; i < height.size() ;i++){
        

        maxi = max(maxi , height[i]);
        leftToRight[i] = maxi;

      }

        maxi = INT_MIN;

      for( int i = height.size()-1 ; i >= 0 ;i--){
        

        maxi = max(maxi , height[i]);
        rightToLeft[i] = maxi;

      }
        
        int mini = INT_MAX;
        int sum = 0;
        for ( int i = 0 ; i < height.size() ; i++){
            mini = min(leftToRight[i],rightToLeft[i]);
            sum += mini - height[i];
        }

        return sum;

        
    }
};
