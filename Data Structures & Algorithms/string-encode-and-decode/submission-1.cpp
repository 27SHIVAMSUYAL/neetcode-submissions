class Solution {
public:

    string encode(vector<string>& strs) {
        string ans ="";

        for(string st : strs){
            ans += to_string(st.size());
           
            ans += '#';

            ans += st;

        }

        return ans;
        

    }

    vector<string> decode(string s) {
        vector<string> ans;
        string count = "" , str ;
        int i = 0 ;

            while(i < s.size()){

                if(s[i] == '#'){
                    str = s.substr(i+1 , stoi(count));
                    ans.push_back(str);
                    i += stoi(count) + 1;
                    count = "" ;
                    
                    continue;
                }

                count += s[i];
                i++;

            }

        return ans;

    }




};
