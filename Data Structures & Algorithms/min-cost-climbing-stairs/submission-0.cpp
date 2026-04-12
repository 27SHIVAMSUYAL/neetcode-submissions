class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int>dp(n,-1);

        int ans = min ( solve(dp , cost , n , 0) , solve(dp , cost , n , 1) );

        return ans;
        
    }

    int solve(vector<int>&dp  , vector<int>&cost , int n , int curr){

        if( curr >= n ){
            return 0;
        }
        if( dp[curr] != -1){
            return dp[curr];
        }
        
            // we can take one step 

            int one = solve(dp , cost , n , curr+1);


            // we can take 2 steps 

            int two = solve( dp , cost , n , curr+2);

            // but we need to return the min amount 
            int total = cost[curr] + min(one , two);

            dp[curr] = total;

            return total;

    }
};
