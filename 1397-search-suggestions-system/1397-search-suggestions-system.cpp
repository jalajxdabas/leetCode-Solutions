class TrieNode {
    public: 
    bool flag;
    TrieNode* check[26];

    TrieNode(){
        flag = false;
        for(int i=0; i<26; i++){
            check[i] = NULL;
        }
    }
};



class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(TrieNode* root, string s){
        TrieNode* p = root;

        for(auto ch: s){
            int i = ch - 'a';
            if(!p->check[i]) p->check[i] = new TrieNode();
            p = p->check[i];
        }
        p->flag = true;
    }

    
    void dfs(vector<string> &temp, string s, TrieNode* p){
        if(temp.size() == 3) return;
        if(p->flag) temp.push_back(s);

        

        for(int i=0; i<26; i++){
            if(temp.size() == 3) return;
            if(p->check[i]){
                s.push_back('a' + i);
                dfs(temp, s, p->check[i]);
                s.pop_back();
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        TrieNode* p = root;
        int n = products.size();
        for(int i=0; i<n; i++){
            insert(root, products[i]);
        }

        vector<vector<string>> ans;
        string s = "";

        for(auto ch: searchWord){
            
             s.push_back(ch);
            vector<string> temp;
           
            if(p && p->check[ch - 'a']){
                p = p->check[ch - 'a'];
                dfs(temp, s, p);
            } else {
                p = NULL; 
            }
            ans.push_back(temp);
        }

        return ans;

        

    }
};