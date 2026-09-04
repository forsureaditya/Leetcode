class KthLargest {
public:
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<>>min_heap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0;i<nums.size();i++){
            max_heap.push(nums[i]);
        }
        
        for(int i=1;i<k;i++){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        
    }
    
    int add(int val) {
        if(max_heap.size() == 0){
            min_heap.push(val);

            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        else if(val>max_heap.top()){
            min_heap.push(val);
            if(min_heap.size()==k+1){
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
        else{
            max_heap.push(val);
        }
        if(min_heap.size()==k) return min_heap.top();
        else return max_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */