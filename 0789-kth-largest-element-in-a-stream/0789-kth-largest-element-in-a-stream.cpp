class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for(int &i: nums){
            if(mini.size() < k){
                mini.push(i);
            }
            else if(i > mini.top()){
                mini.push(i);
                mini.pop();
            }
        }
    }
    
    int add(int val) {
        if(mini.size() < k){
            mini.push(val);
        }
        else if(val > mini.top()){
            mini.push(val);
            mini.pop();
        }
        return mini.top();
    }
private: 
    int k;
    priority_queue<int, vector<int>, greater<int>> mini;
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */