/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct compare {
        bool operator()(const ListNode* a, const ListNode* b)
        {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto x : lists)
            if (x)
                pq.push(x);

        ListNode dummy = ListNode(0);
        ListNode *res = &dummy, *cur = &dummy;
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            cur->next = x;
            cur = cur->next;
            if (x->next != 0)
                pq.push(x->next);
        }
        return res->next;
    }
};
// @lc code=end
