class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string , vector<string>> map;


        for(int i = 0 ; i < strs.size() ; i++){

                string hash = createHash(  strs[i] );

                if( map.find(hash) != map.end()){
                    //found
                    map[hash].push_back(strs[i]);
                }else{
                    vector<string> vec;
                    vec.push_back(strs[i]);

                    map[hash] = vec;
                }


        }

        vector<vector<string>> ans;

        for( auto s : map){
            ans.push_back(s.second);
        }

        return ans;
        
    }

    string createHash( string strs){

        vector<int> chars(26 , 0);

        for(char ch : strs){

            chars[ ch - 'a']++;

        }

        string st = "";

        for(int i = 0 ; i < 26 ; i++){

            if(chars[i] > 0){
                st = st + string(1, 'a' + i) + to_string(chars[i]);
            }

        }

        return st;

        
    }
};
