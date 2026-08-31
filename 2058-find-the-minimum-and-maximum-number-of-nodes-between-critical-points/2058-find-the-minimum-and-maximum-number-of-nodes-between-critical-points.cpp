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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> store;
        ListNode* prev = NULL;
        ListNode* curr = head;
        int index = 1;
        while(curr != NULL)
        {
            ListNode* front = curr->next;
            if(prev != NULL && front != NULL)
            {
                if((curr->val > prev->val && curr->val > front->val) || (curr->val < prev->val && curr->val < front->val))
                {
                    store.push_back(index);
                }
            }
            index++;
            prev = curr;
            curr = curr->next;
        }
        if(store.size() <= 1) return {-1 , -1};
        int mini = INT_MAX;
        for(int i = 0 ; i<store.size()-1 ; i++)
        {
            int val = store[i+1]-store[i];
            mini = min(mini , val);
        }
        return { mini , store[store.size()-1] - store[0]};
    }
};