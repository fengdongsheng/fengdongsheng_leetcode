 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p&&q){
            if(p->val==q->val){
                bool left = isSameTree(p->left,q->left);
                if(!left) return 0;
                bool right = isSameTree(p->right,q->right);
                if(!right) return 0;
                return 1;
            }
            else
                return 0;
        }
        else if(!p&&!q) return 1;
        else return 0;
    }
};
