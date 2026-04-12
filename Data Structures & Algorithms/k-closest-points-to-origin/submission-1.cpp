class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue< pair <int , int > > pq;
        int x , y  , distance ;

        for( int i = 0 ; i < points.size() ; i++){
                x = points[i][0];
                y = points[i][1];

                distance = x*x + y*y;

                pq.push({distance , i });

                if( pq.size() > k ){
                    pq.pop();
                }

        }

        pair<int , int > temp;
        vector<vector<int>> ans ;


        while(pq.size() > 0){
            temp = pq.top();
            pq.pop();
            ans.push_back(points[temp.second]);
        
        }
        return ans;
    }
};
