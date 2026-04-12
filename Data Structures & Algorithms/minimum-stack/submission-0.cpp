class MinStack {
public:
    int topPointer ;
    vector<int>values;
    vector<int>minStack;

    MinStack() {
        topPointer = -1;
    
    }
    
    void push(int val) {


            values.push_back(val);

            if(minStack.empty()){
                minStack.push_back(val);
            }else{
                minStack.push_back( min(val , minStack.back()));
            }

                        topPointer++;

        
    }
    
    void pop() {
        if(topPointer > -1){
            values.pop_back();
            minStack.pop_back();
            topPointer--;
        }
        
    }
    
    int top() {

        return values[this->topPointer];
        
    }
    
    int getMin() {

        return minStack.back();


        
    }
};
