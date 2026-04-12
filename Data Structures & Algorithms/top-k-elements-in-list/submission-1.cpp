class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> map;

        for(int i = 0 ; i < nums.size() ; i++){
            map[nums[i]]++;
        }

        priority_queue<pair<int,int>   , vector<pair<int , int > >, greater<pair<int,int>>> minHeap ;


        for(auto m : map){

            minHeap.push({m.second , m.first});

            if(minHeap.size() > k){
                minHeap.pop();
            }

        }

        vector<int> ans;

        while( minHeap.size() > 0){
            pair<int , int > temp = minHeap.top();
            minHeap.pop();
            ans.push_back( temp.second);
        }

        return ans;
        
    }
};
