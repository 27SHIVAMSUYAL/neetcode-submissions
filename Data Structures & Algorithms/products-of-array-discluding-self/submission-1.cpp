class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        long long product = 1;
        vector<int> ans ;
        vector<int> left;
        vector<int> right(nums.size());


        for( int i = 0 ; i < nums.size() ; i++){
                product *= nums[i];
                left.push_back(product);
        }

        product = 1;

int j = nums.size()-1;
         for( int i = nums.size()-1 ; i  >=0  ; i--){
                product *= nums[i];
                right[j]=product;
                j--;
        }



        for( int i = 0 ; i < nums.size() ; i++){
            product = 1;

            if( i+1 < nums.size()){
                product = right[i+1];
            }

            if(i-1 >= 0){
                product *= left[i-1];
            }
           
    
            ans.push_back(product);

        }

        return ans;

    }
};
