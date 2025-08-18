class Solution {
public:
    struct TrieNode {
        TrieNode *left;
        TrieNode *right;
    };

    void insert(TrieNode* root, int num){
        TrieNode *p = root;

        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;

            if(bit == 0){
                if(p->left == NULL) p->left = new TrieNode();
                p = p->left;
            }
            else{
                if(p->right == NULL) p->right = new TrieNode();
                p = p->right;
            }
        }
    }

    int findXOR(TrieNode* root, int num){
        int maxi = 0;
        TrieNode* p = root;

        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;

            if(bit == 1){
                if(p->left){
                    maxi += pow(2, i);
                    p = p->left;
                }
                else{
                    p = p->right;
                }
            }
            else{
                if(p->right){
                    maxi += pow(2, i);
                    p = p->right;
                }
                else{
                    p = p->left;
                }
            }
        }
        return maxi;
    }


    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();

        for(int &i: nums){
            insert(root, i);
        }

        int maxi = INT_MIN;

        for(int &i: nums){
            int temp = findXOR(root, i);

            maxi = max(maxi, temp);
        }
        return maxi;
    }
};