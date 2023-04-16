/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ff=new ListNode(-1),*tmp=ff;

        while(list1 and list2){
            if(list1->val<=list2->val){
                tmp->next=list1;
                list1=list1->next;
            }
            else{
                tmp->next=list2;
                  list2=list2->next;
            }
            tmp=tmp->next;
        }
        while(list1){
             tmp->next=list1;
            tmp=tmp->next;
              list1=list1->next;
        }
         while(list2){
             tmp->next=list2;
            tmp=tmp->next;
              list2=list2->next;
        }

        return ff->next;
        
    }
};