#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge nodes between zeros
ListNode* mergeNodes(ListNode* head) {
    ListNode dummy(0);
    ListNode* newHead = &dummy;
    ListNode* current = head->next;
    int sum = 0;

    while (current) {
        if (current->val == 0) {
            if (sum > 0) {
                newHead->next = new ListNode(sum);
                newHead = newHead->next;
                sum = 0;
            }
        } else {
            sum += current->val;
        }
        current = current->next;
    }

    return dummy.next;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Main function to test the solution
int main() {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(0);

    std::cout << "Original list: ";
    printList(head);

    head = mergeNodes(head);

    std::cout << "List after merging nodes between zeros: ";
    printList(head);

    return 0;
}

