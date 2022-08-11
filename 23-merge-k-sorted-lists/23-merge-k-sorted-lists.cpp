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
// struct compare {
//     bool operator()(const ListNode* l, const ListNode* r) {
//         return l->val > r->val;
//     }
// };
ListNode* merge(ListNode *l1, ListNode *l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    l2->next = merge(l1, l2->next);
    return l2;
}

ListNode* aux(vector<ListNode*>& lists, ListNode *par, int cur) {
    if (cur == lists.size()) return par;
    if (lists[cur] == NULL) return aux(lists, par, cur + 1);
    
    par = merge(par, lists[cur]);
    
    return aux(lists, par, cur + 1);
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0)return NULL;
        return aux(lists, lists[0], 1);
//         priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        
//         for (auto list : lists) {
//             if (list)
//                 pq.push(list);
//         }
        
//         ListNode *dummy = new ListNode(-1), *cur = dummy;
        
//         while (!pq.empty()) {
//             ListNode *t = pq.top();
//             pq.pop();
//             cur->next = t;
//             cur = cur->next;
            
//             if (t->next) {
//                 pq.push(t->next);
//             }
//         }
//         return dummy->next;
//     }
    }
};