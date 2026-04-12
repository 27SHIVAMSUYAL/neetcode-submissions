class Solution {
public:
    int longestConsecutive(vector<int>& nums) {


        if( nums.size() < 2){
            return nums.size();
        }
        
        int answer = 1; 

        int currentAns = 1;
        sort(nums.begin()  , nums.end());

        for ( int i = 1 ; i < nums.size() ; i++){

            if(nums[i] == nums[i-1] ){
                continue;
            }
            else if( nums[i] == nums[i-1] + 1){
                currentAns++;
                answer = max(currentAns , answer);
            }else{
                currentAns = 1;
            }
        }

        // for( int i = 0 ; i < nums.size()  ; i++){
        
        //     if( mapp[nums[i] - 1 ] != mapp.end()){
        //         currentAns = mapp[nums[i] - 1] + 1;
        //         mapp[nums[i]]  = currentAns;
        //     }else{
        //         mapp[nums[i]] = 1;
        //     }

        //     answer = max(answer , currentAns);
        // }

        return answer;

    }

};
