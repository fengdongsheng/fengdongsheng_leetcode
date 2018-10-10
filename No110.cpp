/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right; 
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    //function:deepth 
    //input：treenode，output：height of treenode
    int deepth(TreeNode* root,int ideepth,int maxdep){
        int templef,temprig;
        templef=temprig=0;
        ++ideepth;
        maxdep=maxdep>ideepth?maxdep:ideepth;//ideepth,templef,temprig需要考虑，孰大孰小。递归的重点。
        if(root&&root->left)
            templef=deepth(root->left,ideepth,maxdep); 
        maxdep=maxdep>templef?maxdep:templef;
  
        if(root&&root->right)
            temprig=deepth(root->right,ideepth,maxdep);
        maxdep=maxdep>temprig?maxdep:temprig;
        return maxdep;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> nodeque;
        nodeque.push(root);
        TreeNode* temp;
        while(nodeque.size()){
            temp=nodeque.front();
            nodeque.pop();
            int templef=0;
            int temprig=0;
            if(temp->left) {nodeque.push(temp->left);templef=deepth(temp->left,0,0);}
            if(temp->right) {nodeque.push(temp->right);temprig=deepth(temp->right,0,0);}
            int diff =abs(templef-temprig);
            if(diff>1) return false;
        }
        
        return true;
    }
};
