class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> mini;
    unordered_set<int> st;
    int current;
    SmallestInfiniteSet() {
        current = 1;
    }
    
    int popSmallest() {
        if(!mini.empty()){
            int top = mini.top();
            mini.pop();
            st.erase(top);
            return top;
        }
        return current++;
    }
    
    void addBack(int num) {
        if(num < current && st.find(num) == st.end()) {
            st.insert(num);
            mini.push(num);
        }
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */