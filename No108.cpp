/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
 //① 避免左旋右旋操作:先确定根节点，以数组中值作为root节点，再按分治法建树，这样构建的树一定是平衡的，且高度差绝对值不超过1；

//② 使用左旋右旋操作；在对没有排序的数组时需要
class Solution {
public:
    //分治法，在递归基础上   
    TreeNode* dividedandconquer(vector<int>& nums){
        int mid_index = nums.size()/2;
        TreeNode* root = new TreeNode(0);
        root->val=nums[mid_index];
        root->right=NULL;
        root->left=NULL;
        if(nums.size()==1) return root;
        
        vector<int> left_nums,right_nums;
        //省却了比较操作，构建左右两个数组十分耗时。
        left_nums.insert(left_nums.begin(),nums.begin(),nums.begin()+mid_index);
        TreeNode* result_left=dividedandconquer(left_nums);
        root->left=result_left;
        
        TreeNode* result_right;
        if(nums.size()>=3){
            right_nums.insert(right_nums.begin(),nums.begin()+mid_index+1,nums.end());
            result_right=dividedandconquer(right_nums);
            root->right=result_right;
        }

        return root;
    } 
    
    TreeNode* sortedArrayToBST(vector<int>& nums){
        if(nums.size()==0)
            return NULL;
        TreeNode* root = dividedandconquer(nums);
        return root;
    }
};
static auto _=[]()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        return 0;
    }();
