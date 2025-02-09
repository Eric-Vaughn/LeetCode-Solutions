// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned int sum = l1->val + l2->val;
        bool carry = false;

        // ----------------------------- TO-DO: IMPLEMENT THE CARRY FUNCTIONALITY ----------------------------- 
        if (sum >= 10) {
            carry = true;
            sum = sum % 10;
        }

        ListNode* result = new ListNode(l1->val + l2->val); // Both numbers will have at least a first digit
        ListNode* result_head = result;

        // While both of our next digits exits
        while(l1->next && l2->next) {
            result->next = new ListNode(l1->next->val + l2->next->val);

            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        // If l1 runs out of digits, then we will just appened the rest of l2's digits
        if (!l1->next) {
            while(l2->next) {
                result->next = new ListNode(l2->next->val);

                result = result->next;
                l2 = l2->next;
            }
        }
        // If l2 runs out of digits, then we will just appened the rest of l1's digits
        else if (!l2->next) {
            while(l1->next) {
                result->next = new ListNode(l1->next->val);

                result = result->next;
                l1 = l1->next;
            }
        }

        // ----------------------------- DELETE ANYTHING THAT NEEDS TO BE CLEANED UP ----------------------------- 
        return result_head;
    }
};