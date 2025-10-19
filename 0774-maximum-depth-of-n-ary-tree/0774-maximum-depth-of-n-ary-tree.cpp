/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node* root, int &level, int reached){
        if(reached > level) level = reached;

        for(auto i: root->children){
            dfs(i, level, reached+1);
        }
    }
    int maxDepth(Node* root) {
        if(root == NULL) return 0;

        int level = 1;
        dfs(root, level, 1);
        return level;
    }
};