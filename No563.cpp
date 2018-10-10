/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static auto x = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
    int travel(TreeNode* root,int sum){
        sum+=root->val;
        if(!root->left&&!root->right)return sum;
        if(root->left) sum=travel(root->left,sum);
        if(root->right) sum=travel(root->right,sum);
        return sum;
    }
    
    int findTilt(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> nodeque;
        nodeque.push(root);
        vector<int> nodeslope;
        while(nodeque.size()){
            TreeNode* tempnode =nodeque.front();
            nodeque.pop();
            int temp_left=0,temp_right=0;
            
            if(tempnode->left){
                temp_left=travel(tempnode->left,0);
                nodeque.push(tempnode->left);
            } 
            if(tempnode->right){
                temp_right=travel(tempnode->right,0);
                nodeque.push(tempnode->right);
            }
            
            nodeslope.push_back(abs(temp_right-temp_left));
        }
        return accumulate(nodeslope.begin(),nodeslope.end(),0);
    }
};
