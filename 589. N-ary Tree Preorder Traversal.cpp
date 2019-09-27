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
    vector<int> res;
    vector<int> preorder(Node* root) {
        if(!root) return res;
        //traverse(root);  
        
        stack<Node*> nodeStack;
        nodeStack.push(root);
        //res.push_back(root->val);
        
        while(!nodeStack.empty()){
            Node* cur = nodeStack.top();
            res.push_back(cur->val);
            nodeStack.pop();
            
            for(int i=cur->children.size()-1; i>=0; i--){
                nodeStack.push(cur->children[i]);
            }
        }
        
        return res;
    }
    
private:
    void traverse(Node* root){
        if(!root) return ;
        
        res.push_back(root->val);
        for(int i=0; i<root->children.size(); i++)
            preorder(root->children[i]);

        
    }
};
