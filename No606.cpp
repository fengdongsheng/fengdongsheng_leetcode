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
private:
    string bracket="()";
    string left_bracket="(";
    string right_bracket=")";
public:
    string delete_empty(string node_str){
        int i=0,j=i+1;
        for(;j!=node_str.size()-1;j++,i++){
            //1:"())"  && 2:")()"需要删除的空括号的两情况
            bool con1=node_str[i]==left_bracket.data()[0]&&node_str[j]==right_bracket.data()[0]&&node_str[j+1]==right_bracket.data()[0];
            bool con2=node_str[i]==right_bracket.data()[0]&&node_str[j]==left_bracket.data()[0]&&node_str[j+1]==right_bracket.data()[0];
            if(con1){
                node_str.erase(i,2);
                i=0,j=i+1;//erase之后node_str.size()的值改变了，不可以再用原来的i，j遍历，所以从头开始
            }
            if(con2){
                node_str.erase(i+1,2);
                i=0,j=i+1;   
            }
        }
        
        return node_str;
    }
    string tree2str(TreeNode* t) {
        if(!t) return "";//为空，不能返回空括号（）
        string node_str=to_string(t->val);
        
        if(!t->left&&!t->right)
            return node_str;
               
        if(t->left)
            node_str+=left_bracket+tree2str(t->left)+right_bracket;
        else
            node_str+=bracket;
        
        if(t->right)
            node_str+=left_bracket+tree2str(t->right)+right_bracket;
        else
            node_str+=bracket;
        
        return delete_empty(node_str);
    }
};
