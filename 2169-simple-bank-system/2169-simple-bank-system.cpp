class Bank {
public:
    using ll = long long;
    int n;
    vector<ll> nums;
    Bank(vector<long long>& balance) {
        n = balance.size(); 
        nums = balance;

    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > n || account2 > n || nums[account1-1] < money) return false;

        nums[account2-1] += money;
        nums[account1-1] -= money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > n) return false;
        nums[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > n || nums[account-1] < money) return false;
         nums[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */