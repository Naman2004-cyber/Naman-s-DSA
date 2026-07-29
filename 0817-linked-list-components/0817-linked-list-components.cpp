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
    int numComponents(ListNode* head, vector<int>& nums) {
        int count = 0;
        unordered_set<int> st;
        st.insert(nums.begin() , nums.end());
        ListNode* temp = head;
        while(temp != NULL){
            if(st.count(temp->val) && (temp->next == NULL || !st.count(temp->next->val))){
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};