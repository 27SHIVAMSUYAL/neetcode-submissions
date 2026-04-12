class Solution {
public:
    int climbStairs(int n) {


        vector<int> dp(n,-1);

        int ans = solve(dp , n ,0);

        return ans;
        
    }

    int solve( vector<int>&dp , int n  , int cur){

        if(cur == n ){
            return 1;
        }else if (cur > n ){
            return 0;
        }

        if(dp[cur] != -1){
            return dp[cur];
        }

        // it can go to 1 

        int one = solve(dp,n,cur+1);

        // it can go to 2 

         int two = solve(dp,n,cur+2);

        // so total number of ways is ways from 1 + ways from 2 

        dp[cur] = one + two;

        return dp[cur];



    }
};
