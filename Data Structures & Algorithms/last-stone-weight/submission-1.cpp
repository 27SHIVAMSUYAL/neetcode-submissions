class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;
        pq.push(0);
        int x , y ;

        for( int i = 0 ; i < stones.size() ; i++){
            pq.push(stones[i]);
        }

        while( pq.size() > 2){
            x = pq.top();
            pq.pop();

            y = pq.top();
            pq.pop();

            if( x==y){
                continue;
            }else{
                pq.push(abs(x-y));
            }



        }
        
        return pq.top();
        
        
    }
};
