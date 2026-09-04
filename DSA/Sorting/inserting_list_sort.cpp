```cpp
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
    ListNode* insertionSortList(ListNode* head) {
        // If the list has 0 or 1 node, it is already sorted
        if(head == nullptr || head->next == nullptr)
            return head;

        // 'temp' represents the head of the sorted portion
        ListNode* temp = head;

        // 'temphead' points to the first node that is yet to be sorted
        ListNode* temphead = temp->next;

        // Detach the first node from the remaining list
        temp->next = nullptr;

        // Process each remaining node one by one
        while(temphead) {

            // Store the current node to be inserted
            ListNode* n = temphead;

            // Move to the next unsorted node before modifying n->next
            temphead = temphead->next;

            // Start searching for the correct position in the sorted list
            ListNode* tt = temp;
            ListNode* prev = nullptr;

            while(tt) {

                // Found the position where current node should be inserted
                if(tt->val > n->val) {

                    // If prev is nullptr, n becomes the new head
                    if(prev == nullptr) {
                        n->next = tt;
                        temp = n;
                    }
                    else {
                        // Insert n between prev and tt
                        prev->next = n;
                        n->next = tt;
                    }

                    break;
                }

                // If we reached the last node, insert n at the end
                if(tt->next == nullptr) {
                    tt->next = n;
                    n->next = nullptr;
                    break;
                }

                // Move forward in the sorted portion
                prev = tt;
                tt = tt->next;
            }
        }

        // temp points to the head of the sorted linked list
        return temp;
    }
};
```
