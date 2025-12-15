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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, vector<ListNode*>> nodesCount;

        if (lists.empty())
            return nullptr;
        for (ListNode* v : lists) {
            while (v) {
                nodesCount[v->val].push_back(v);
                v = v->next;
            }
        }
        ListNode* out;
        ListNode* it;
        if (nodesCount.empty())
            return nullptr;
        out = nodesCount.begin()->second[0];
        it = out;
        for (auto p : nodesCount) {
            for (auto n : p.second) {
                if (out == n)
                    continue;
                it->next = n;
                it = it->next;
            }
        }

        return out;
    }
};