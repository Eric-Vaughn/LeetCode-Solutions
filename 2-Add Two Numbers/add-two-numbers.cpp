// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
carry_amount() figures out if we should carry nothing, a 1, or a 2 during addition
@param sum: the sum of potienally 2 digits
@return: the amount to be carried to the next sum
*/
bool should_carry(unsigned int sum) {
    // We are returning only a 0 or 1, so why not make it a boolean value!
    if (sum >= 10) { return true;  }
    else           { return false; }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned int sum = l1->val + l2->val;
        bool need_to_carry = false;

        need_to_carry = should_carry(sum);

        sum = sum % 10;

        ListNode* result = new ListNode(sum); // Both numbers will have at least a first digit
        ListNode* result_head = result;

        // While both of our next digits exits
        while(l1->next && l2->next) {
            // The static_casting from boolean to unsigned int is implicit, but this way is more robust
            sum = (l1->next->val + l2->next->val + static_cast<unsigned int>(need_to_carry));

            need_to_carry = should_carry(sum);

            sum = sum % 10;

            result->next = new ListNode(sum);

            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        // If l1 runs out of digits, then we will just appened the rest of l2's digits
        if (!l1->next) {
            while(l2->next) {
                sum = l2->next->val + static_cast<unsigned int>(need_to_carry);

                need_to_carry = should_carry(sum); // This will always be either 0 or 1

                sum = sum % 10;

                result->next = new ListNode(sum);

                result = result->next;
                l2 = l2->next;
            }
        }
        // If l2 runs out of digits, then we will just appened the rest of l1's digits
        else if (!l2->next) {
            while(l1->next) {
                sum = l1->next->val + static_cast<unsigned int>(need_to_carry);

                need_to_carry = should_carry(sum); // This will always be either 0 or 1

                sum = sum % 10;

                result->next = new ListNode(sum);

                result = result->next;
                l1 = l1->next;
            }
        }

        if (need_to_carry) { result->next = new ListNode(static_cast<unsigned int>(need_to_carry)); }

        return result_head;
    }
};