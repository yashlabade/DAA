
#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a linked list in groups of size k
Node* reverseInGroups(Node* head, int k) {
    if (!head || k == 1) return head;

    Node *prev = nullptr, *curr = head, *next = nullptr;
    int count = 0;

    // Count nodes in the current group
    Node* temp = head;
    for (int i = 0; i < k && temp != nullptr; i++, temp = temp->next)
        count++;

    if (count == k) {
        // Reverse k nodes
        count = 0;
        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Recursively call for the remaining list
        if (next) {
            head->next = reverseInGroups(next, k);
        }

        // Return the new head of this group
        return prev;
    }

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to insert a new node at the end of the list
void appendNode(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Main function
int main() {
    Node* head = nullptr;

    // Input the linked list
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 2);
    appendNode(head, 4);
    appendNode(head, 5);
    appendNode(head, 6);
    appendNode(head, 7);
    appendNode(head, 8);

    int k = 4;

    cout << "Original Linked List: ";
    printList(head);

    head = reverseInGroups(head, k);

    cout << "Reversed in Groups of " << k << ": ";
    printList(head);

    return 0;
}