class Solution {
public:
    bool isAnagram(string s, string t) {

       vector<int> test(26 , 0);


        for(auto c : s){
                test[ c - 'a' ]++;
        }

        for( auto ch : t){
             test[ ch - 'a' ]--;
        }

        for( auto te : test){
            if(te != 0){
                return false;
            }
        }

        return true;
        
    }
};
