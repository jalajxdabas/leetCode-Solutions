class TrieNode {
    public: 
    bool isWord;
    TrieNode* child[26];

    TrieNode() {
        for(int i=0; i<26; i++){
            child[i] = NULL;
        }
        isWord = false;
    }
};

class WordDictionary {
    private: TrieNode* root;
public:

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i]-'a';
        

            if(node->child[idx] == NULL) node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return helper(root, word, 0);
    }

    bool helper(TrieNode* node, string word, int idx){
        if(idx == word.size()) return node->isWord;

        int i = word[idx] - 'a';

        if(word[idx] == '.'){
            for(auto &p: node->child){
                if(p!=NULL &&  helper(p, word, idx+1)) return true;
            }
            return false;
        }
        else{
            if(node->child[i] == NULL) return false;
            TrieNode* temp = node->child[i];
            return helper(temp, word, idx+1);
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */