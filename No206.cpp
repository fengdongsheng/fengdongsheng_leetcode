/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* next = NULL;
        pre->next = NULL;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
        
//         ListNode* previous=NULL;
//         ListNode* now=head;
//         ListNode* next;
//         if(now!=NULL&&now->next!=NULL)
//             next=now->next;
//         else
//             return now; //特例的判断
        
//         while(next!=NULL && next->next!=NULL){
//             if(now!=NULL&&now->next!=NULL&&previous==NULL) //老问题，必须判空，trick，干脆直接赋值为NULL
//                 now->next=NULL;
            
//             if(previous!=NULL){  //一般情况
//                 now->next=previous;
//                  cout<<now->val<<endl;
//             }

//             previous=now;
//             now=next;
//             next=next->next;
//         }
//         //在跳出while循环后并没有将now和next所指向的对象链入到表中
//         now->next=previous;
//         next->next=now;
//         return next;
    }
};
