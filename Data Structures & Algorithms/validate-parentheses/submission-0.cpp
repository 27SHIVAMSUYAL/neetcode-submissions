class Solution {
public:
    bool isValid(string s) {

        stack<char> stack;

        for( auto &ch : s){

            if(stack.empty()){
                stack.push(ch);
                continue;
            }
            
                if((stack.top() == '(' && ch == ')' ) || (stack.top() == '{' && ch == '}' ) || (stack.top() == '[' && ch == ']' ) ){
                    stack.pop();
                }else{
                         stack.push(ch);
                }
            
           
        }

        if(stack.empty()){
            return true;
        }

        return false;
        
    }
};
