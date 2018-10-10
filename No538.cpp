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
    
    //根据二叉搜索树的性质，小于一个节点的值全在该节点的左子树上
    //                      大于某个节点val值的都在该节点的右子树上
    //轮子：遍历右子树
    vector<int> tree2vec(TreeNode* root,vector<int> preorder_vec){
        if(root)
            preorder_vec.push_back(root->val);
        else
            return vector<int>();
        if(root->left)
            preorder_vec=tree2vec(root->left,preorder_vec);
        if(root->right)
            preorder_vec=tree2vec(root->right,preorder_vec);
        return preorder_vec;
    }
    
    //vector 前后都可以push和pop，但是前push和pop效率极差，常用push_back和pop_back;vector没有自带find，使用了algorithm中的方法，sort也是algorithm中的方法
    //queue 只可以在后端push和pop所以没有_back
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        TreeNode* temp_root=root;
        queue<TreeNode*> nodeque;
        vector<int> preorder_vec;
        nodeque.push(root);
        preorder_vec=tree2vec(root,preorder_vec);//先将树结构转为vector     
        sort(preorder_vec.begin(),preorder_vec.end());//对vector排序 从小到大

        while(nodeque.size()){
            TreeNode* temp_node=nodeque.front();
            //core line:
            vector<int>::iterator index=find(preorder_vec.begin(),preorder_vec.end(),temp_node->val);//find 找到temp_node->val 的索引
            //cout<<*index<<endl;
            for(;index!=preorder_vec.end();index++)
                if(*index!=temp_node->val){//预防有多个一样的值
                    temp_node->val=accumulate(index,preorder_vec.end(),temp_node->val);
                    break;
        }
            
            if(temp_node->left)
                nodeque.push(temp_node->left);

            if(temp_node->right)
                nodeque.push(temp_node->right);
            
            nodeque.pop();
        }
        return root;
    }
};
