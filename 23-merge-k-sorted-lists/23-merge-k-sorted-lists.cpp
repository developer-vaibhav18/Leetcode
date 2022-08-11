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
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0)return NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        
        for (auto list : lists) {
            if (list)
                pq.push(list);
        }
        
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        
        while (!pq.empty()) {
            ListNode *t = pq.top();
            pq.pop();
            cur->next = t;
            cur = cur->next;
            
            if (t->next) {
                pq.push(t->next);
            }
        }
        return dummy->next;
    }
};