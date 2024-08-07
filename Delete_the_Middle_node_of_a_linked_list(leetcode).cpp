/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int value;
 *     ListNode *next;
 *     ListNode(int value = 0) : value(value), next(nullptr) {}
 *     ListNode(int value, ListNode *next) : value(value), next(next) {}
 * };
 */
class Solution {
public:
    // Function to delete the middle node of the linked list.
    ListNode* deleteMiddle(ListNode* head) {
        // Create a dummy node that points to the head of the list.
        ListNode* dummyNode = new ListNode(0, head);
      
        // Initialize slow and fast pointers for the runner technique.
        ListNode* slowPointer = dummyNode;
        ListNode* fastPointer = head;

        // Advance the fast pointer by two steps and the slow pointer by one step
        // until fast reaches the end of the list.
        while (fastPointer && fastPointer->next) {
            slowPointer = slowPointer->next;          // Move slow pointer by one
            fastPointer = fastPointer->next->next;    // Move fast pointer by two
        }

        // The slow pointer now points at the node before the middle node.
        ListNode* toDelete = slowPointer->next;       // Store the middle node to delete  
        slowPointer->next = slowPointer->next->next;  // Remove the middle node

        delete toDelete; // Free memory of the node to be deleted

        // The head of the new modified list is the next node of dummyNode.
        ListNode* newHead = dummyNode->next;
        delete dummyNode; // Delete the dummyNode to prevent memory leak

        return newHead; // Return the new head of the list
    }
};
