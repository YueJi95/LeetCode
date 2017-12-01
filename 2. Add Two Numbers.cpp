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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        else if(l2 == nullptr) return l1;
        int carryon = 0;
        ListNode* pos = l2;
        ListNode* cur = l1;
        ListNode* pre = nullptr;
        for(cur = l1; cur != nullptr; cur = cur->next){
            if(pos == nullptr) break;
            cur->val = cur->val + pos->val + carryon;
            carryon = cur->val / 10;
            cur->val = cur->val - 10 * carryon;
            pos = pos->next;
            pre = cur;
        }
        ListNode* temp = pre;
        if(pos == nullptr){
            while(cur != nullptr){
                cur->val = cur->val + carryon;
                carryon = cur->val / 10;
                cur->val = cur->val - 10 * carryon;
                temp = cur;
                cur = cur->next;
            }
            if(carryon != 0){
                ListNode* add = new ListNode(carryon);
                add->next = nullptr;
                temp->next = add;
            }
        }
        else if(cur == nullptr){
            pre->next = pos;
            while(pos != nullptr){
                pos->val = pos->val + carryon;
                carryon = pos->val / 10;
                pos->val = pos->val - 10 * carryon;
                temp = pos;
                pos = pos->next;
            }
            if(carryon != 0){
                ListNode* add = new ListNode(carryon);
                add->val = carryon;
                add->next = nullptr;
                temp->next = add;
            }
        }
        return l1;
    }
};