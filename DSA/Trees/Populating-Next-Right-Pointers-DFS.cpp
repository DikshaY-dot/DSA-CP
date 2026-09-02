/*
    Problem: Populating Next Right Pointers in Each Node
    Approach: Iterative DFS / Level-wise Traversal

    Idea:
    - curr points to the first node of the current level.
    - temp moves through all nodes of that level using the `next` pointers.
    - For every node:
        1. Connect left child -> right child.
        2. Connect right child -> next node's left child.
    - After completing a level, move curr to the leftmost node of the next level.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    Node* connect(Node* root) {

        // curr points to the first node of the current level
        Node* curr = root;

        // Continue while there is another level
        while (curr && curr->left) {

            // temp traverses the current level using next pointers
            Node* temp = curr;

            while (temp) {

                // Connect left child to right child
                temp->left->next = temp->right;

                // Connect right child to the next node's left child
                if (temp->next) {
                    temp->right->next = temp->next->left;
                }

                // Move to the next node in the current level
                temp = temp->next;
            }

            // Move to the first node of the next level
            curr = curr->left;
        }

        return root;
    }
};
