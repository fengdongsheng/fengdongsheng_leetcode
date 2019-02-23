class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int max_length =0;
        int last_index =0;
        string result_string;
        int result_size = s.size();//考虑到从头到尾没有进入过else
        for(int i=0;i<s.size();i++){
            if(result_string.find(s[i])==string::npos)
                result_string += string(1,s[i]);
            else{

                result_size = result_string.size();
                max_length = max_length > result_size ? max_length:result_size;
               
                int new_index = result_string.find(s[i]);
                i = last_index + new_index;

                last_index = i+1;//在此处加1，而不是上一行加1再将i赋值到last_index，是考虑到for循环还会再加1

                //cout<<result_string<<endl;
                result_string.clear();
            }
            //i++;
        }
        result_size =result_string.size();//考虑到退出for前的操作没有执行else，result_size 中装的不是最新的length
        max_length = max_length > result_size ? max_length:result_size;//和line8相协调
        return max_length;
    }
};
static int x = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
