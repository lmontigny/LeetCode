/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        
        int depth = 0;
        for (auto child : root->children) 
            depth = max(depth, maxDepth(child));
        return 1 + depth;
        
        /*
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            level++;
            for(int i=0; i<q.size(); i++){
                Node* cur = q.front();
                q.pop();
                for(int i=0; i<cur->children.size(); i++){
                     if(cur->children[i]) q.push(cur->children[i]);
                }
            }
        }
        
        return level;
        */
    }
};
