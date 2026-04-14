class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

            int mini = INT_MAX ,maxi = 0 ,  ans = 0;

        for( int i = 0 ; i < prices.size() ;i++){

            if( prices[i] < mini){
                mini = prices[i];
            }

            if( prices[i]  > mini){
                ans = max( ans , prices[i] - mini);
            }

            

        }

        return ans;



    }
};
